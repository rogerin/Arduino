void I2C_IO_Write(int pinN, byte endereco,int status){
int aux = 0;
aux = 1 << pinN;
if(status == LOW){
inicio &= ~ aux;     //(LOW)
}
if (status == HIGH){
inicio |= aux;          //(HIGH)
}
  inicio = inicio ^ (1 pinN);
  Wire.beginTransmission(endereco);
    Wire.write(inicio);
  Wire.endTransmission(endereco);
  delay(40);
}