//package WS1.Observables;

//import WS1.Observers.Observer;

public class PressureTrendSensor extends Observable implements Observer{
    int lastReading1 = -1;
    int lastReading2 = -1;
    int lastReading3 = -1;
    Trend pressureState = null;
    Trend lastState = null;
    public String toString(){
        return new String("pressure trend");
    }
    public PressureTrendSensor(Sensor pressureSensor) {
        pressureSensor.addObserver(this);
    }
    Trend calc()
    {
        if(lastReading1 != -1 && lastReading2 != -1 && lastReading3 != -1)
        {
            Trend currentTrend;
            if(lastReading1 < lastReading2 && lastReading2 < lastReading3)
            {
                currentTrend = Trend.RISING;
            }
            else if(lastReading3 < lastReading2 && lastReading2 < lastReading1)
            {

                currentTrend = Trend.FALLING;
            }
            else currentTrend = Trend.STABLE;
            lastState = pressureState;
            pressureState = currentTrend;

            return currentTrend;
        }
        return null;
    }
    void check()
    {
        if(pressureState != lastState)
        {
            this.notifyObservers(pressureState.ordinal());
        }
    }
    public void update(int pressure)
    {
        lastReading1 =lastReading2;
        lastReading2 = lastReading3;
        lastReading3 = pressure;
        calc();
        this.check();
    }
}
