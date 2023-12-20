//package WS1.Observables;

public class AlarmClockRecord {
    int remainingTime;
    int interval;
    AlarmListener alarmListener;
    public AlarmClockRecord(int interval, AlarmListener AL)
    {
        remainingTime = this.interval = interval;
        this.alarmListener = AL;
    }
    public int getRemainingTime(){return remainingTime;}
    public int getInterval(){return interval;}
    public AlarmListener getListener(){return alarmListener;}
    public void SetRemainingTime(int interval){remainingTime = interval;}
    public void decrementRemainingTime(int ticUnit){
        remainingTime -= ticUnit;
    }

}
