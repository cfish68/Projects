//package WS1.Observables;

//import WS1.Nimbus1.Nimbus1PressureSensor;
//import WS1.Nimbus1.Nimbus1TempratureSensor;
//import WS1.Observers.Observer;

public class WeatherMonitoringSystem {
    //singleton
    protected static WeatherMonitoringSystem instance = null;
    public Sensor itsPressureSensor;
    public Sensor itsTempratureSensor;
    public PressureTrendSensor itsPressureTrendSensor;

    protected WeatherMonitoringSystem()
    {
        System.out.println(this.getClass().getSimpleName() + " was created");
        itsPressureSensor = new Nimbus1PressureSensor("pressure", 1100);
        itsTempratureSensor = new Nimbus1TemperatureSensor("temperature", 700);
        itsPressureTrendSensor = new PressureTrendSensor(itsPressureSensor);
    }

    public static WeatherMonitoringSystem theInstance()
    {
        if(null==instance)
            instance = new WeatherMonitoringSystem();
        return instance;
    }

}
