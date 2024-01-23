using System.Runtime.InteropServices;

namespace ln{
    public class lotteryNumbers{
        public int lottonum{get; set;}

        public string date{get; set;}
        public int num1 {get; set;}
        public int num2 {get; set;}
        public int num3 {get; set;}
        public int num4 {get; set;}
        public int num5 {get; set;}
        public int num6 {get; set;}
        public int strongnum{get; set;}
        public int winnings{get; set;}
        public int watch{get; set;}

        public string ToString(){
            return "lottoNum: "  + lottonum.ToString() + ' ' +  date.ToString() + ' ' + num1.ToString() + ' ' + num2.ToString() + ' ' + num3.ToString() + ' ' + num4.ToString() + ' ' + num5.ToString() + ' ' + num6.ToString() + "\tstrongnum: " + strongnum.ToString();
        }
    }
}