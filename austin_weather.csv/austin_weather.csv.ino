#define ch_nu 1
#define ch_def_val 1500
#define fr_ln 4800
#define pls_ln 1500
#define onstate 1
#define sigPin 9
int ppm[ch_nu];
void setup()
{
  for(int i=0; i<ch_nu; i++)
  {
    ppm[i]=ch_def_val;
  }
   pinMode(sigPin 1,OUTPUT);
   digitalWrite(sigPin 1,!onstate);
   cli();
   tccr1A=0;
   tccr1B=0;
   ocr1A=100;
   tccr1B |=(1<<WGM 12);
   tccr1B |=(1<<cs11);
   timsk1 |=(1<<ocie1A);
   sci();
}

void loop()
{
  ISR(timer1_comp_vect)
  static boolean state =true;
  tcnt1=0;
  if(state)
  {
    digitalWrite(sigPin 1,onstate);
    ocr1A=pls_ln *2;
    state=false;
  }
  else
  {
    static byte cur_chan_numb;
    static unsignd int calc_rest;
    digitalWrite(sigPin 1,!onstate);
    state=true;
    if(cur_chan_numb>=ch_nu)
    {
      cur_chan_num=0;
      calc_rest=calc_rest+pls_ln;
      ocr1A=(fr_ln-calc_rest)*2;
      calc_rest=0;
    }
    else
    {
      ocr1A=(ppm[cur_chan_numb]-pls_ln)*2;
      calc_rest=calc_rest+ppm[cur_chan_numb];
      cur_chan_numb ++;
    }
  }
  
 }
}
