#include "QThread"
#include "onvifcontrol.h"
#include "CmdLineParser.h"
#include "SoapHelper.h"
#include "soapStub.h"
#include "OnvifMediaClient.h"
#include "OnvifDeviceClient.h"

const QString mediasrv = "http://www.onvif.org/ver10/media/wsdl";
const QString ptzsrv = "http://www.onvif.org/ver20/ptz/wsdl";

QSharedPointer<SoapCtx> ctx = QSharedPointer<SoapCtx>::create();

OnvifControl::OnvifControl(QObject *parent) : QObject(parent)
{
    //ptzClient = new OnvifPtzClient(QUrl("http://192.168.200.65/onvif/ptz_service"),ctx);
    //mediaClient = new OnvifMediaClient(QUrl("http://192.168.200.65/onvif/media_service"),ctx);
}

int OnvifControl::GetDeviceServices( QString ipaddr, QString login, QString pass)
{

    OnvifDeviceClient onvifDevice(QUrl("http://" + ipaddr + "/onvif/device_service"),ctx);
    onvifDevice.SetAuth(login, pass, AUTO);

    Request<_tds__GetServices> request;
    request.IncludeCapability = false;
    auto servicesResponse = onvifDevice.GetServices(request);
    qInfo() << "Onvif Namespaces: (" << ipaddr << ") - "<< login << "/" << pass;
    if(servicesResponse){
        QString mediaURL;
        QString ptzURL;
        for(auto service : servicesResponse.GetResultObject()->Service){
            qInfo() << " - Name: " << service->Namespace << ", Url: " << service->XAddr;
            if (service->Namespace == mediasrv)
            {
                mediaURL = service->XAddr;

            }
            if (service->Namespace == ptzsrv)
            {
                ptzURL = service->XAddr;
            }
        }
        qInfo()  << "media service: " << mediaURL << "; ptz service: " << ptzURL;
    } else {
        qInfo()  << "Response empty";
        return -1;
    }
    return 0;
}

void OnvifControl::InitMediaClient(QString ipaddr, QString login, QString pass)
{

    /*QCommandLineParser parser;
    CmdLineParser::setup(parser);
    //parser.process(app);
    auto response = CmdLineParser::parse(parser);
    //if(response)
    auto ctxBuilder = SoapCtx::Builder();
    ctxBuilder.SetSendTimeout(1000);
    ctxBuilder.SetReceiveTimeout(1000);*/
    //mediaClient->SetEndpoint(QUrl("http://" + ipaddr + "/onvif/media_service"));
    //mediaClient->SetAuth(login,pass, AUTO);
    GetProfile(ipaddr, login, pass);
    GetStreamUri(ipaddr, login, pass);
/*    Request<_trt__GetServiceCapabilities> st_request;
    Response<_trt__GetServiceCapabilitiesResponse> res = mpMediaClient->GetServiceCapabilities(st_request);
    if(res)
    {
        trt__Capabilities * cap = res.GetResultObject()->Capabilities;
        qInfo()  <<  cap->ProfileCapabilities->code;
    }else qInfo() << mpMediaClient->GetFaultString();*/
}

void OnvifControl::GetProfile(QString ipaddr, QString login, QString pass)
{
        OnvifMediaClient mc(QUrl("http://" + ipaddr + "/onvif/media_service"),ctx);
        mc.SetAuth(login,pass, AUTO);

        Request<_trt__GetProfiles> profilesRequest;

        auto profilesResponse = mc.GetProfiles(profilesRequest);

        if(profilesResponse) {
            if(profilesResponse.GetResultObject()->Profiles.size()>0)
            {
                auto profile = profilesResponse.GetResultObject()->Profiles[0];
                ProfileToken = profile->token;
                qInfo()  << "Profile: " <<profile->token;
            }
        }else qInfo() << mc.GetFaultString();
}

void OnvifControl::GetStreamUri(QString ipaddr, QString login, QString pass)
{
    OnvifMediaClient mc(QUrl("http://" + ipaddr + "/onvif/media_service"),ctx);
    mc.SetAuth(login,pass, AUTO);
    Request<_trt__GetStreamUri> rRequest;
    rRequest.StreamSetup = new tt__StreamSetup();
    rRequest.StreamSetup->Stream = tt__StreamType::RTP_Unicast;
    rRequest.StreamSetup->Transport = new tt__Transport();
    rRequest.StreamSetup->Transport->Protocol = tt__TransportProtocol::RTSP;

    rRequest.ProfileToken = ProfileToken;
    Response<_trt__GetStreamUriResponse> resuri = mc.GetStreamUri(rRequest);
    if(resuri){
         tt__MediaUri * uri = resuri.GetResultObject()->MediaUri;
         stream_uri = uri->Uri;
         qInfo()  << "Media URL: " << uri->Uri;
    }else qInfo() << mc.GetFaultString();
}

void OnvifControl::InitPtzClient(QString ipaddr, QString login, QString pass)
{
    ClosePtzClient();
    ptzClient = new OnvifPtzClient(QUrl("http://" + ipaddr + "/onvif/ptz_service"),ctx);
    //ptzClient->SetEndpoint(QUrl("http://" + ipaddr + "/onvif/media_service"));
    xaddrs = ipaddr;
    ptzClient->SetAuth(login,pass,AUTO);
}

void OnvifControl::ClosePtzClient()
{
    if(ptzClient != nullptr)
        delete ptzClient;
}

void OnvifControl::CloseMediaClient()
{
   // if(mediaClient != nullptr)
   //     delete mediaClient;
}

void OnvifControl::AbsoluteMove(float x, float y, float z)
{
    Request<_tptz__AbsoluteMove> rRequest;
    rRequest.ProfileToken = ProfileToken;

    tt__PTZVector *Position = new tt__PTZVector();
    tt__Vector2D *pan = new tt__Vector2D();
    tt__Vector1D *zoom = new tt__Vector1D();
    pan->x = x;
    pan->y = y;
    zoom->x = z;
    Position->PanTilt = pan;
    Position->Zoom = zoom;
    rRequest.Position = Position;
    Response<_tptz__AbsoluteMoveResponse> resmove= ptzClient->AbsoluteMove(rRequest);

    if( not resmove )
    {
        std::cerr << "Response empty" << std::endl;
        std::cerr << resmove.GetSoapFault().toUtf8().data() << ", ("
                  << resmove.GetSoapFaultDetail().toUtf8().data() << ")" << std::endl;
    }

   /* delete pan;
    delete zoom;
    delete Position;*/
    return;
}

void OnvifControl::ContinuousMove(float x, float y, float z)
{
    PtzStatus status;
    Request<_tptz__ContinuousMove> rRequest;
    rRequest.ProfileToken = ProfileToken;

    tt__PTZSpeed *Velocity = new tt__PTZSpeed();
    tt__Vector2D *pan = new tt__Vector2D();
    tt__Vector1D *zoom = new tt__Vector1D();
    pan->x = x;
    pan->y = y;
    zoom->x = z;
    Velocity->PanTilt = pan;
    Velocity->Zoom = zoom;
    rRequest.Velocity = Velocity;
    Response<_tptz__ContinuousMoveResponse> resmove= ptzClient->ContinuousMove(rRequest);

    if( not resmove )
    {
        std::cerr << "Response empty" << std::endl;
        std::cerr << resmove.GetSoapFault().toUtf8().data() << ", ("
                  << resmove.GetSoapFaultDetail().toUtf8().data() << ")" << std::endl;
    }

   /* delete pan;
    delete zoom;
    delete Velocity;*/
    return;
}

void OnvifControl::PtzStop()
{
    Request<_tptz__Stop> sRequest;
    sRequest.ProfileToken = ProfileToken;
    Response<_tptz__StopResponse> resstop = ptzClient->Stop(sRequest);
    if(not resstop )
    {
        std::cerr << "Response empty" << std::endl;
        std::cerr << resstop.GetSoapFault().toUtf8().data() << ", ("
                  << resstop.GetSoapFaultDetail().toUtf8().data() << ")" << std::endl;
    }
}


PtzStatus OnvifControl::getPtzStatus()
{
    PtzStatus status;
    Request<_tptz__GetStatus> st_request;
    st_request.ProfileToken = ProfileToken;
    Response<_tptz__GetStatusResponse> st_res = ptzClient->GetStatus( st_request );
    if( st_res )
    {
        tt__PTZStatus* ptz = st_res.GetResultObject()->PTZStatus;
        if( ptz )
        {
            status.time = ptz->UtcTime;
            if( ptz->Position )
            {
                if( ptz->Position->PanTilt )
                {
                    if( ptz->Position->PanTilt->x )
                        status.tilt = ptz->Position->PanTilt->y;
                    if( ptz->Position->PanTilt->y )
                        status.pan = ptz->Position->PanTilt->x;
                }
                if( ptz->Position->Zoom && ptz->Position->Zoom->x )
                    status.zoom = ptz->Position->Zoom->x;
            }

            if( ptz->MoveStatus )
            {
                /*if( ptz->MoveStatus->PanTilt )
                    status.pan_tilt_status = (PtzMoveStatus) *(ptz->MoveStatus->PanTilt);
                if( ptz->MoveStatus->PanTilt )
                    status.zoom_status = (PtzMoveStatus) *(ptz->MoveStatus->Zoom);*/
            }
        }
    }
    else
    {
        std::cerr << "Response empty" << std::endl;
        std::cerr << st_res.GetSoapFault().toUtf8().data() << ", ("
                  << st_res.GetSoapFaultDetail().toUtf8().data() << ")" << std::endl;
    }

    return status;
}
