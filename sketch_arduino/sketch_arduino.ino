int rele01 = 7; //Relé lampada 1
int rele02 = 6; //Relé lampada 2
int aviso = 8; // LED para aviso
char valor_leitura = 0; //Valor para ler do bluetooth do aplicativo
             
void setup() 
{
//-- Setando o pinMode  --//         
  pinMode(rele01, OUTPUT);
  pinMode(rele02, OUTPUT);
  pinMode(aviso, OUTPUT);
//------------------------//

 //Iniciar com as lampadas apagadas//
 digitalWrite(rele01, LOW);
 digitalWrite(rele02, LOW);
 //--------------------------------//
}

void loop()
{
  if(Serial.available() > 0)  {
    
    valor_leitura = Serial.read();

//------- Leitura dos valores do bluetooth -------// 
    if(valor_leitura == '1'){            
      digitalWrite(rele01, HIGH);
      digitalWrite(rele02, HIGH);
      digitalWrite(aviso, LOW); 
    } else if(valor_leitura == '0'){     
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);   
    }
//-----------------------------------------------//
                              
  } //Serial.available
} //Void loop
