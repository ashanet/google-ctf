/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 */

#include "tomcrypt_private.h"

#ifdef LTC_SOSEMANUK

/**
   Encrypt (or decrypt) bytes of ciphertext (or plaintext) with Sosemanuk
   @param key     The key
   @param keylen  The key length
   @param iv      The initial vector
   @param ivlen   The initial vector length
   @param datain  The plaintext (or ciphertext)
   @param datalen The length of the input and output (octets)
   @param dataout [out] The ciphertext (or plaintext)
   @return CRYPT_OK if successful
*/
int sosemanuk_memory(const unsigned char *key,    unsigned long keylen,
                     const unsigned char *iv,     unsigned long ivlen,
                     const unsigned char *datain, unsigned long datalen,
                     unsigned char *dataout)
{
   sosemanuk_state st;
   int err;

   if ((err = sosemanuk_setup(&st, key, keylen)) != CRYPT_OK) goto WIPE_KEY;
   if ((err = sosemanuk_setiv(&st, iv, ivlen))   != CRYPT_OK) goto WIPE_KEY;
   err = sosemanuk_crypt(&st, datain, datalen, dataout);
WIPE_KEY:
   sosemanuk_done(&st);
   return err;
}

#endif /* LTC_SOSEMANUK */

/* ref:         HEAD -> develop */
/* git commit:  9c0d7085234bd6baba2ab8fd9eee62254599341c */
/* commit time: 2018-10-15 10:51:17 +0200 */
