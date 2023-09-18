class Solution {
    public double angleClock(int hour, int minutes) {
        double min_angle=(minutes/60.0)*360.0;
        double hour_angle=hour*30.0+(min_angle/360.0*30.0);
        double result=0.0;
        if(hour_angle>min_angle)
        result=hour_angle-min_angle;
        else
        result=min_angle-hour_angle;

        if(result>180)
        result=360-result;

        return result;
    }
}