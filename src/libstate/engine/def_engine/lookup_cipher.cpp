/*************************************************
* Cipher Lookup                                  *
* (C) 1999-2007 Jack Lloyd                       *
*************************************************/

#include <botan/def_eng.h>
#include <botan/lookup.h>
#include <botan/scan_name.h>
#include <memory>

#if defined(BOTAN_HAS_AES)
  #include <botan/aes.h>
#endif

#if defined(BOTAN_HAS_BLOWFISH)
  #include <botan/blowfish.h>
#endif

#if defined(BOTAN_HAS_CAST)
  #include <botan/cast128.h>
  #include <botan/cast256.h>
#endif

#if defined(BOTAN_HAS_DES)
  #include <botan/des.h>
  #include <botan/desx.h>
#endif

#if defined(BOTAN_HAS_GOST)
  #include <botan/gost.h>
#endif

#if defined(BOTAN_HAS_IDEA)
  #include <botan/idea.h>
#endif

#if defined(BOTAN_HAS_KASUMI)
  #include <botan/kasumi.h>
#endif

#if defined(BOTAN_HAS_LION)
  #include <botan/lion.h>
#endif

#if defined(BOTAN_HAS_LUBY_RACKOFF)
  #include <botan/lubyrack.h>
#endif

#if defined(BOTAN_HAS_MARS)
  #include <botan/mars.h>
#endif

#if defined(BOTAN_HAS_MISTY1)
  #include <botan/misty1.h>
#endif

#if defined(BOTAN_HAS_NOEKEON)
  #include <botan/noekeon.h>
#endif

#if defined(BOTAN_HAS_RC2)
  #include <botan/rc2.h>
#endif

#if defined(BOTAN_HAS_RC5)
  #include <botan/rc5.h>
#endif

#if defined(BOTAN_HAS_RC6)
  #include <botan/rc6.h>
#endif

#if defined(BOTAN_HAS_SAFER)
  #include <botan/safer_sk.h>
#endif

#if defined(BOTAN_HAS_SEED)
  #include <botan/seed.h>
#endif

#if defined(BOTAN_HAS_SERPENT)
  #include <botan/serpent.h>
#endif

#if defined(BOTAN_HAS_SERPENT_IA32)
  #include <botan/serp_ia32.h>
#endif

#if defined(BOTAN_HAS_SKIPJACK)
  #include <botan/skipjack.h>
#endif

#if defined(BOTAN_HAS_SQUARE)
  #include <botan/square.h>
#endif

#if defined(BOTAN_HAS_TEA)
  #include <botan/tea.h>
#endif

#if defined(BOTAN_HAS_TWOFISH)
  #include <botan/twofish.h>
#endif

#if defined(BOTAN_HAS_XTEA)
  #include <botan/xtea.h>
#endif

#if defined(BOTAN_HAS_ARC4)
  #include <botan/arc4.h>
#endif

#if defined(BOTAN_HAS_SALSA20)
  #include <botan/salsa20.h>
#endif

#if defined(BOTAN_HAS_TURING)
  #include <botan/turing.h>
#endif

#if defined(BOTAN_HAS_WID_WAKE)
  #include <botan/wid_wake.h>
#endif

#if defined(BOTAN_HAS_CIPHER_MODE_PADDING)
  #include <botan/mode_pad.h>
#endif

namespace Botan {

/*************************************************
* Look for an algorithm with this name           *
*************************************************/
BlockCipher*
Default_Engine::find_block_cipher(const std::string& algo_spec) const
   {
   SCAN_Name request(algo_spec);

#if defined(BOTAN_HAS_AES)
   if(request.algo_name() == "AES")
      return new AES;
   if(request.algo_name() == "AES-128")
      return new AES_128;
   if(request.algo_name() == "AES-192")
      return new AES_192;
   if(request.algo_name() == "AES-256")
      return new AES_256;
#endif

#if defined(BOTAN_HAS_BLOWFISH)
   if(request.algo_name() == "Blowfish")
      return new Blowfish;
#endif

#if defined(BOTAN_HAS_CAST)
   if(request.algo_name() == "CAST-128")
      return new CAST_128;
   if(request.algo_name() == "CAST-256")
      return new CAST_256;
#endif

#if defined(BOTAN_HAS_DES)
   if(request.algo_name() == "DES")
      return new DES;
   if(request.algo_name() == "DESX")
      return new DESX;
   if(request.algo_name() == "TripleDES")
      return new TripleDES;
#endif

#if defined(BOTAN_HAS_GOST)
   if(request.algo_name() == "GOST")
      return new GOST;
#endif

#if defined(BOTAN_HAS_IDEA)
   if(request.algo_name() == "IDEA")
      return new IDEA;
#endif

#if defined(BOTAN_HAS_KASUMI)
   if(request.algo_name() == "KASUMI")
      return new KASUMI;
#endif

#if defined(BOTAN_HAS_MARS)
   if(request.algo_name() == "MARS")
      return new MARS;
#endif

#if defined(BOTAN_HAS_MISTY1)
   if(request.algo_name() == "MISTY1")
      return new MISTY1(request.argument_as_u32bit(0, 8));
#endif

#if defined(BOTAN_HAS_NOEKEON)
   if(request.algo_name() == "Noekeon")
      return new Noekeon;
#endif

#if defined(BOTAN_HAS_RC2)
   if(request.algo_name() == "RC2")
      return new RC2;
#endif

#if defined(BOTAN_HAS_RC5)
   if(request.algo_name() == "RC5")
      return new RC5(request.argument_as_u32bit(0, 12));
#endif

#if defined(BOTAN_HAS_RC6)
   if(request.algo_name() == "RC6")
      return new RC6;
#endif

#if defined(BOTAN_HAS_SAFER)
   if(request.algo_name() == "SAFER-SK")
      return new SAFER_SK(request.argument_as_u32bit(0, 10));
#endif

#if defined(BOTAN_HAS_SEED)
   if(request.algo_name() == "SEED")
      return new SEED;
#endif

#if defined(BOTAN_HAS_SERPENT_IA32)
   if(request.algo_name() == "Serpent")
      return new Serpent_IA32;
#elif defined(BOTAN_HAS_SERPENT)
   if(request.algo_name() == "Serpent")
      return new Serpent;
#endif

#if defined(BOTAN_HAS_SKIPJACK)
   if(request.algo_name() == "Skipjack")
      return new Skipjack;
#endif

#if defined(BOTAN_HAS_SQUARE)
   if(request.algo_name() == "Square")
      return new Square;
#endif

#if defined(BOTAN_HAS_TEA)
   if(request.algo_name() == "TEA")
      return new TEA;
#endif

#if defined(BOTAN_HAS_TWOFISH)
   if(request.algo_name() == "Twofish")
      return new Twofish;
#endif

#if defined(BOTAN_HAS_XTEA)
   if(request.algo_name() == "XTEA")
      return new XTEA;
#endif

#if defined(BOTAN_HAS_LUBY_RACKOFF)
   if(request.algo_name() == "Luby-Rackoff" && request.arg_count() == 1)
      {
      HashFunction* hash = get_hash(request.argument(0));
      if(hash)
         return new LubyRackoff(hash);
      }
#endif

#if defined(BOTAN_HAS_LION)
   if(request.algo_name() == "Lion" &&
      (request.arg_count() == 2 || request.arg_count() == 3))
      {
      const u32bit block_size = request.argument_as_u32bit(2, 1024);

      std::auto_ptr<HashFunction> hash(get_hash(request.argument(0)));
      if(!hash.get())
         return 0;

      std::auto_ptr<StreamCipher> sc(get_stream_cipher(request.argument(1)));
      if(!sc.get())
         return 0;

      return new Lion(hash.release(), sc.release(), block_size);
      }
#endif

   return 0;
   }

/*************************************************
* Look for an algorithm with this name           *
*************************************************/
StreamCipher*
Default_Engine::find_stream_cipher(const std::string& algo_spec) const
   {
   SCAN_Name request(algo_spec);

#if defined(BOTAN_HAS_ARC4)
   if(request.algo_name() == "ARC4")
      return new ARC4(request.argument_as_u32bit(0, 0));
   if(request.algo_name() == "RC4_drop")
      return new ARC4(768);
#endif

#if defined(BOTAN_HAS_SALSA20)
   if(request.algo_name() == "Salsa20")
      return new Salsa20;
#endif

#if defined(BOTAN_HAS_TURING)
   if(request.algo_name() == "Turing")
      return new Turing;
#endif

#if defined(BOTAN_HAS_WID_WAKE)
   if(request.algo_name() == "WiderWake4+1-BE")
      return new WiderWake_41_BE;
#endif

   return 0;
   }

/*************************************************
* Look for an algorithm with this name           *
*************************************************/
BlockCipherModePaddingMethod*
Default_Engine::find_bc_pad(const std::string& algo_spec) const
   {
   SCAN_Name request(algo_spec);

#if defined(BOTAN_HAS_CIPHER_MODE_PADDING)
   if(request.algo_name() == "PKCS7")
      return new PKCS7_Padding;

   if(request.algo_name() == "OneAndZeros")
      return new OneAndZeros_Padding;

   if(request.algo_name() == "X9.23")
      return new ANSI_X923_Padding;

   if(request.algo_name() == "NoPadding")
      return new Null_Padding;
#endif

   return 0;
   }

}
