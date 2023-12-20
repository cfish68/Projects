//package WS1.Observables;

public abstract class Sensor extends Observable {
    int lastReading;
    int interval;
    String type;
    @Override
    public String toString(){return type;}
    public Sensor(String type, int interval)
    {
        this.type = type;
        this.interval = interval;
    }
    public abstract int read();
    public void check()
    {
        int val = this.read();
        if(val != lastReading)
        {
            lastReading = val;
//update observables
            this.notifyObservers(val);
        }
    }
}
