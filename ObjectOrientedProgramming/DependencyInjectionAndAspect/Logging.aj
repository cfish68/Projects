package sortingAlgorithms;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

import java.util.Arrays;
import java.util.Date;
import java.time.LocalDateTime;
public aspect Logging {

    @Pointcut("execution(* sort(..))")
    private void selectSorts(){}

    long milliseconds;
    @Before("selectSorts()")
    public void beforeLoggable(JoinPoint jp){
        Object[] obj = (Object[]) jp.getArgs()[0];
        System.out.println("Running sort in " + jp.getThis().getClass() + " with array size " + obj.length);
        Date time = new Date();
        milliseconds = time.getTime();
    }

    @After("selectSorts()")
    public void AfterLoggable(JoinPoint jp){
        Date time = new Date();

        milliseconds = (time.getTime() - milliseconds);
        System.out.println(String.format("Function sort in %s took %d ms", jp.getThis().getClass().toString(), milliseconds));
    }
}
