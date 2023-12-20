//package WS1.Observables;

public class SensorAlarmListener implements AlarmListener{
    Sensor itsSensor;
    public SensorAlarmListener(Sensor sensor)
    {
        itsSensor = sensor;
        System.out.println(sensor.toString() + " registered to clock");
    }
    @Override
    public void WakeUp() {
        itsSensor.check();
    }
}
