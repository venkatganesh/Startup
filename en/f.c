////kJZieMsSC1ij/e4JnUITmfBIle1dFky9v1xlBPkVhp+aWRk2DCsmNcutsnyLAQzY0u7+yWWwGMiSlybSoc3RLA==
////AES-256 / CBC / ZeroBytePadding encrypted
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//#include <string.h>
//
///*
// * MCrypt API available online:
// * http://linux.die.net/man/3/mcrypt
// */
//#include <mcrypt.h>
//
//#include <math.h>
//#include <stdint.h>
//#include <stdlib.h>
//
//char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//char myb64[1024] = "";
//char mydst[1024] = "";
//
//void decodeblock(unsigned char in[], char *clrstr) {
//	char out[4];
//	out[0] = in[0] << 2 | in[1] >> 4;
//	out[1] = in[1] << 4 | in[2] >> 2;
//	out[2] = in[2] << 6 | in[3] >> 0;
//	out[3] = '\0';
//	strncat(clrstr, out, sizeof(out));
//}
//
//void b64_decode(char *b64src, char *clrdst) {
//	int c, phase, i;
//	unsigned char in[4];
//	char *p;
//
//	clrdst[0] = '\0';
//	phase = 0;
//	i = 0;
//	while (b64src[i]) {
//		c = (int) b64src[i];
//		if (c == '=') {
//			decodeblock(in, clrdst);
//			break;
//		}
//		p = strchr(b64, c);
//		if (p) {
//			in[phase] = p - b64;
//			phase = (phase + 1) % 4;
//			if (phase == 0) {
//				decodeblock(in, clrdst);
//				in[0] = in[1] = in[2] = in[3] = 0;
//			}
//		}
//		i++;
//	}
//}
//void encodeblock(unsigned char in[], char b64str[], int len) {
//	char out[5];
//	out[0] = b64[in[0] >> 2];
//	out[1] = b64[((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)];
//	out[2] = (unsigned char) (
//			len > 1 ? b64[((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)] : '=');
//	out[3] = (unsigned char) (len > 2 ? b64[in[2] & 0x3f] : '=');
//	out[4] = '\0';
//	strncat(b64str, out, sizeof(out));
//}
//
//void b64_encode(char *clrstr, char *b64dst) {
//	unsigned char in[3];
//	int i, len = 0;
//	int j = 0;
//
//	b64dst[0] = '\0';
//	while (clrstr[j]) {
//		len = 0;
//		for (i = 0; i < 3; i++) {
//			in[i] = (unsigned char) clrstr[j];
//			if (clrstr[j]) {
//				len++;
//				j++;
//			} else
//				in[i] = 0;
//		}
//		if (len) {
//			encodeblock(in, b64dst, len);
//		}
//	}
//}
//int encrypt(void* buffer, int buffer_len,char* IV, char* key, int key_len) {
//
//	printf("Buffer _len_encrypt func=%d\n",buffer_len);
//	printf("key_len encrypt =%d\n",key_len);
//	MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL );
//	int blocksize = mcrypt_enc_get_block_size(td);
//	printf("%d\n",blocksize);
//	printf("%d\n", buffer_len % blocksize);
//	//if( buffer_len % blocksize != 0 ){return 1;}
//
//	mcrypt_generic_init(td, key, key_len, IV);
//	mcrypt_generic(td, buffer, buffer_len);
//	mcrypt_generic_deinit(td);
//	mcrypt_module_close(td);
//
//	return 0;
//}
//
//int decrypt(void* buffer, int buffer_len, char* IV, char* key, int key_len) {
//	MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL );
//	int blocksize = mcrypt_enc_get_block_size(td);
//	printf("%d\n",blocksize);
//	printf("%d\n", buffer_len % blocksize);
////	if (buffer_len % blocksize != 0) {
////		return 1;
////	}
//
//	mcrypt_generic_init(td, key, key_len, IV);
//	mdecrypt_generic(td, buffer, buffer_len);
//	mcrypt_generic_deinit(td);
//	mcrypt_module_close(td);
//
//	return 0;
//}
//
//int main() {
//
//	char *IV;
//	char *key ="0123456789abcdef";
//	char cipher_text[1024];
//
//
////------------------------Decrypt Function---------------------------------------------------
//	b64_decode("kJZieMsSC1ij/e4JnUITmfBIle1dFky9v1xlBPkVhp+aWRk2DCsmNcutsnyLAQzY0u7+yWWwGMiSlybSoc3RLA==", mydst);
//	printf("b64 decode=%s\n", mydst);
//	printf("b64decode= %d\n",strlen(mydst));
//	strncpy(IV, mydst, 16);
//	printf("IV=%s\n",IV);
//	printf("IV=%d\n",strlen(IV));
//	memcpy(cipher_text, mydst+16, strlen(mydst+1));
//	printf("cipher_text=%s\n",cipher_text);
//	printf("cipher_text=%d\n",strlen(cipher_text));
//	decrypt(cipher_text, strlen(cipher_text), IV, key, strlen(key));
//	printf("decrypt: %s\n", cipher_text);
//
//
////-
//
////	b64_encode(buffer, myb64);
////	printf("b64 encode=%s\n", myb64);
////	b64_decode(myb64, mydst);
////	printf("b64 decode=%s\n", mydst);
//
//
//	return 0;
//}
//
