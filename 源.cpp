/*
extern "C" 
{ 
  #include <openssl/applink.c> 
 };
#include<iostream>
#include <string.h>
#include <stdio.h>
#include <openssl/evp.h> 
#include <openssl/bio.h> 

using namespace std;
int my_sm4encrpt(unsigned char* keyStr, unsigned char* surbuf, int surlen, unsigned char* enbuf);
int dencryptStr(unsigned char* sm4PriKey, unsigned char* cEnStr, int cEnstrlen, unsigned char* deStr);
 int main(int argc, char* argv[])
    {
        unsigned char sm4_en[512], sm4_de[512];
        int sm4enStrLen, sm4deStrLen;
        unsigned char source[20] = { 0x41,0x12,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10, 0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20 };
        unsigned char keyStr[16] = { 0x15,0x67,0x28,0xe1,0x5f,0x9a,0xfc,0x01,0xd4,0xb6,0x1b,0x4e,0x44,0x5d,0xbb,0x26 };
        sm4enStrLen = my_sm4encrpt(keyStr, source, 20, sm4_en);
        printf("sm4enStrLen:%d", sm4enStrLen);
        for (int i = 0; i < sm4enStrLen; ++i)
        {
            printf("0x%x", sm4_en[i]);
        }
        printf("\n");
        sm4deStrLen = dencryptStr(keyStr, sm4_en, sm4enStrLen, sm4_de);
        printf("sm4deStrLen:%d", sm4deStrLen);
        cout << endl;
        for (int i = 0; i < sm4deStrLen; ++i)
        {
            printf("0x%x", sm4_de[i]);
            cout << " ";
        }
        printf("\n");
    }
    int my_sm4encrpt(unsigned char* keyStr, unsigned char* surbuf, int surlen, unsigned char* enbuf)
    {
        unsigned char* out_buf = enbuf;
        int out_len;
        int out_padding_len;
        int i;
       
        EVP_CIPHER_CTX* ctx;
        unsigned char iv[8];
        for (int i = 0; i < 8; i++)

        {

            memset(&iv[i], i, 0);

        }
        ctx = EVP_CIPHER_CTX_new();
        EVP_EncryptInit(ctx, EVP_sm4_ecb(), keyStr, iv);
        if (0 == surlen % 16)
        {
            EVP_CIPHER_CTX_set_padding(ctx, 0);
        }
        out_len = 0;
        EVP_EncryptUpdate(ctx, out_buf, &out_len, surbuf, surlen);
        out_padding_len = 0;
        EVP_EncryptFinal(ctx, out_buf + out_len, &out_padding_len);

        EVP_CIPHER_CTX_free(ctx);
        return out_len + out_padding_len;
    }


    int dencryptStr(unsigned char* sm4PriKey, unsigned char* cEnStr, int cEnstrlen, unsigned char* deStr)
    {
        
        EVP_CIPHER_CTX* ctx;
        int len;
        int temlen;
        int deStrLen;
        unsigned char iv[8];
        for (int i = 0; i < 8; i++)

        {

            memset(&iv[i], i, 0);

        }
        if (!(ctx = EVP_CIPHER_CTX_new())) {
            printf("EVP_CIPHER_CTX_new failed");
        }
        if (1 != EVP_DecryptInit(ctx, EVP_sm4_ecb(), sm4PriKey, iv)) {
            printf("EVP_DecryptInit_ex failed");
        }


        if (1 != EVP_DecryptUpdate(ctx, deStr, &len, cEnStr, cEnstrlen)) {
            printf("EVP_DecryptUpdate failed");
        }
        if (0 == len % 16)
        {
            EVP_CIPHER_CTX_set_padding(ctx, 0);
            len += 16;

        }
        if (!EVP_DecryptFinal(ctx, deStr + len, &temlen))
        {
            printf("EVP_DecryptFinal failed");
            return EXIT_FAILURE;
        }
        deStrLen = len + temlen;
        printf("½âÃÜÊý¾Ý£º%d\n", deStrLen);
        for (int i = 0; i < deStrLen; i++) {
            printf("0x%02x ", *(deStr + i));
        }
        printf("\n");
        EVP_CIPHER_CTX_free(ctx);
        return deStrLen;
    }
    */