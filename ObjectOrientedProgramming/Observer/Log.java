//package WS1.Observers;

//import WS1.Observables.PressureTrendSensor;
//import WS1.Observables.WeatherMonitoringSystem;

public class Log {

    PressureTrendSensor PTS;
    LogPressObserver ps;
    LogPressTrendObserver lg;
    public Log(WeatherMonitoringSystem ws)
    {
        System.out.println("Log was created");
        ps = new LogPressObserver((ws.itsPressureSensor));
        lg = new LogPressTrendObserver(ws.itsPressureTrendSensor);
    }
}
