//package WS1.Observers;

//import WS1.Observables.WeatherMonitoringSystem;

public class MonitoringScreen{
    MSTempObserver MStemp;
    MSPressObserver MSPress;
    public MonitoringScreen(WeatherMonitoringSystem ws)
    {
        System.out.println(this.getClass().getSimpleName() + " was created");
        MStemp = new MSTempObserver(ws.itsTempratureSensor);
        MSPress = new MSPressObserver(ws.itsPressureSensor);
    }
    //public void update(int data){
        //System.out.println(this.getClass().getSimpleName() + ":temperature = " + data);
    //}
}
