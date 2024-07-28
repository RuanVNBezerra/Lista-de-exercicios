int x, y, *p; //declarando variaveis
    y = 0; //y recebe 0
    p = &y; //declara p como o endereço da variavel y
    x = *p; // declara x como o valor que está no endereço de p (o valor de y)
    x = 4; //declara x como 4, deixando o valor de y inalterado (0)
    (*p)++; //adiciona 1 ao valor de y, e agora y passa a valer 1 (uma vez que p é o endereço de y)
    --x; //decrementa o valor de x, passando a valer 3 (4 - 1 = 3)
    (*p) += x; //o valor apontado por p é somado ao valor de x (1 + 3 = 4), resultando no valor 4
    // sendo que (*p) é o próprio y (conteudo do endereço de p)
    //portanto, o resultado final dos valores: 
    // x = 3
    // y = 4 
    // p = enderço de y