void SDbytes(char path[],int sdarray[]){
  File w=FileSystem.open(path,FILE_READ);
  int x;
  for(int i = 0 ; i < 64; i++){
    x = w.read() << 8; // Extract the MSB of the 16-bit integer
    x |= w.read(); // Append the LSB to the previous MSB
    sdarray[i] = x;
  }//end forloop
  w.close(); // close sd file
}// end function


void drawbitmap(int colorbuffer[],uint8_t mode) {
if(mode = 0){
    int bufferindex = 0;
    for (int y = 7 ; y >= 0 ; y--) { //after the color array is built, they are pushed into this loop where it build the each pixel
      for (int x = 0 ; x < 8 ; x++) {    //and displays according to the color array
        matrix.drawPixel(x, y, colorbuffer[bufferindex]);
        bufferindex++;
      }
    }

}//end if mode 0 which doesnt fade in (used for bitmap animations)
if (mode = 1){
  for(int i = 0 ; i <= brightness ; i += 2){
  int bufferindex = 0;
    for (int y = 7 ; y >= 0 ; y--) { //after the color array is built, they are pushed into this loop where it build the each pixel
      for (int x = 0 ; x < 8 ; x++) {    //and displays according to the color array
        matrix.drawPixel(x, y, colorbuffer[bufferindex]);
        bufferindex++;
      }
    }
    matrix.setBrightness(i);
    matrix.show();
    delay(5);
  }
}//endif mode 1 which fades in


}


void fetchNsketch(char* werd,uint8_t mode){
  char* w = ("/mnt/sda1/Dsprites/");
  char* path =(char*)malloc(strlen(w)+strlen(werd)+1); /* make space for the new string (should check the return value ...) */
  strcpy(path, w); /* copy name into the new var*/
  strcat(path, werd); /* add the extension */
  SDbytes(path,sd);
  free(path);// deallocate memory used for char array
  drawbitmap(sd,mode);
  
  delay(60); // To give the Yun a break so it doesnt straight up die
}
