#define rele01 7 //Lampada 1
#define rele02 6 //Lampada 2
#define aviso 8  //LED vermelho para aviso

char valor = 0; //Char para armazenar o que sem do Serial.read()
   
void setup() 
{
  //Definindo o pinMode e ativando o Serial
  Serial.begin(9600);         
  pinMode(rele01, OUTPUT);
  pinMode(rele02, OUTPUT);
  pinMode(aviso, OUTPUT);
  //----------------------//
  //Iniciar com as lampadas apagadas e o aviso ligado//
  digitalWrite(rele01, LOW);
  digitalWrite(rele02, LOW);
  digitalWrite(aviso, HIGH);
  //----------------------//      
}

void loop()
{
  if(Serial.available() > 0) //Vendo se o Serial está disponivel  
  {
    //valor = Serial.read(); //Pegando o valor que ta chegando e igualando com um char
    char valor = Serial.read();

    Serial.println(valor);
    Serial.println(Serial.read());
    
    //------- Leitura dos valores do bluetooth -------//
    if(valor == '1'){            
      digitalWrite(rele01, HIGH);
      digitalWrite(rele02, HIGH);
      digitalWrite(aviso, LOW); 
    } else if(valor == '0'){     
      digitalWrite(rele01, LOW);
      digitalWrite(rele02, LOW);
      digitalWrite(aviso, HIGH);  
  }
  //-------------------------------------------------//
  } 

  //Caso a pessoa finalize o aplicativo, ou a conexão de bluetooth seja perdida. As lampadas UVC apagarão automaticamente
  if(Serial.read() > 1) {
    digitalWrite(rele01, LOW);
    digitalWrite(rele02, LOW);
    //--- A luz vermelha irá acender ---//
    digitalWrite(aviso, HIGH);
  }
  
}
