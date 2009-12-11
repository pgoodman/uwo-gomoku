/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf --compare-strncmp --seven-bit --readonly-tables --enum --pic --includes --hash-function-name=player1_hash --lookup-function-name=player1_score --language=ANSI-C --switch=5 ./export/hashes1.txt  */
/* Computed positions: -k'1-2,4,12,17' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#include <string.h>
#include <stddef.h>

/* pos/neg scores for these board states. */
static int scores[362] = {
    17,
    15,
    13,
    11,
    9,
    16,
    1208,
    2197,
    2219,
    3,
    1,
    5,
    3,
    1,
    5,
    3,
    1,
    33,
    31,
    29,
    27,
    25,
    23,
    21,
    19,
    17,
    2,
    5,
    3,
    1,
    33,
    31,
    29,
    27,
    25,
    23,
    38,
    33,
    31,
    29,
    27,
    25,
    23,
    21,
    19,
    1025,
    1023,
    1021,
    1019,
    1017,
    1015,
    1013,
    1011,
    1009,
    1007,
    1005,
    10,
    7,
    4,
    2,
    1,
    238,
    0,
    1015,
    257,
    255,
    253,
    251,
    249,
    247,
    245,
    243,
    241,
    239,
    237,
    241,
    9,
    8,
    7,
    17,
    15,
    13,
    11,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    258,
    254,
    250,
    246,
    1279,
    1271,
    1205,
    129,
    127,
    125,
    123,
    8326,
    8320,
    8314,
    8821,
    8814,
    8762,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    5,
    4,
    3,
    2,
    1,
    1,
    0,
    85,
    75,
    65,
    55,
    49,
    0,
    0,
    258,
    254,
    250,
    246,
    242,
    238,
    234,
    230,
    226,
    222,
    218,
    214,
    210,
    206,
    202,
    198,
    194,
    190,
    186,
    182,
    178,
    174,
    170,
    166,
    162,
    158,
    154,
    150,
    146,
    142,
    138,
    134,
    130,
    126,
    122,
    118,
    114,
    110,
    106,
    102,
    98,
    94,
    17,
    14,
    31,
    1,
    70,
    67,
    64,
    61,
    58,
    56,
    54,
    52,
    50,
    48,
    46,
    44,
    42,
    40,
    38,
    36,
    34,
    32,
    30,
    28,
    26,
    24,
    22,
    20,
    18,
    16,
    14,
    12,
    10,
    8,
    6,
    0,
    9,
    8,
    7,
    6,
    5,
    4,
    3,
    2,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    5,
    4,
    1057,
    1053,
    1049,
    1045,
    1041,
    17,
    15,
    5,
    4,
    33,
    31,
    29,
    27,
    25,
    5,
    12,
    11,
    10,
    9,
    8,
    7,
    6,
    5,
    4,
    3,
    2,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    7,
    6,
    5,
    4,
    3,
    2,
    2,
    2,
    1045,
    1043,
    1041,
    1039,
    1037,
    1035,
    1033,
    1031,
    1029,
    1027,
    1025,
    1023,
    1021,
    1019,
    43,
    41,
    39,
    37,
    35,
    33,
    31,
    29,
    27,
    25,
    23,
    21,
    19,
    17,
    15,
    13,
    11,
    9,
    7,
    5,
    3,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    7,
    6,
    5,
    4,
    3,
    2,
    8213,
    8209,
    8242,
    8238,
    8234,
    8230,
    8226,
    8222,
    8218,
    1062,
    2,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    4,
    3,
    2,
    1,
    1,
    1,
    1,
    531,
    529,
    527,
    525,
    523,
    521,
    519,
    517,
    515
};

/* maximum key range = 16906, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
player1_hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,  3912,  6481,
       3398,   740,  1629,    55,    30,   300,   165,    60,   135,    15,
        100,    10,     5,   667,   410,  1200,   220,  1866,  4841, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990,  1844,  7711,  5571,
         67,  1265,     0,  1725,  1612,   262,  1845,  2933,     2,   555,
        894,  1565,  3688,  6136, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990,
      16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990, 16990
    };
  return len + asso_values[(unsigned char)str[16]+9] + asso_values[(unsigned char)str[11]+5] + asso_values[(unsigned char)str[3]+11] + asso_values[(unsigned char)str[1]+3] + asso_values[(unsigned char)str[0]];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
int player1_score (register const char *str, register unsigned int len)
{
  int so=0;
  enum
    {
      TOTAL_KEYWORDS = 1442,
      MIN_WORD_LENGTH = 32,
      MAX_WORD_LENGTH = 32,
      MIN_HASH_VALUE = 84,
      MAX_HASH_VALUE = 16989
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = player1_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          register const char *resword;

          if (key < 3751)
            {
              if (key < 2111)
                {
                  switch (key - 84)
                    {
                      case 0:
                        so=283;
                        resword = "f39a300cec6607d15626fe3b3143bd65";
                        goto compare;
                      case 42:
                        so=4;
                        resword = "dcea6b319f96b61a413d3736cf12eaae";
                        goto compare;
                      case 48:
                        so=165;
                        resword = "638030d015381e0e28d16ac2894958a1";
                        goto compare;
                      case 60:
                        so=246;
                        resword = "682316b0f3443719c71ec2dd1f0f199b";
                        goto compare;
                      case 70:
                        so=335;
                        resword = "53aa2af07d3177805083455f77708a06";
                        goto compare;
                      case 83:
                        so=313;
                        resword = "f8c0b19ac0f75b00563b0e4bd1e6ded9";
                        goto compare;
                      case 88:
                        so=30;
                        resword = "fc533942f0aa920710ac570bb11b45d6";
                        goto compare;
                      case 93:
                        so=321;
                        resword = "6c729ee987b779ac57e1bb3d0f76dd5f";
                        goto compare;
                      case 110:
                        so=292;
                        resword = "93403f6b4430756ecb10d9cad820723a";
                        goto compare;
                      case 118:
                        so=78;
                        resword = "5c008ea6200a145f3a7aaf9b67d46704";
                        goto compare;
                      case 123:
                        so=340;
                        resword = "f81352fe2b30068130eb8a54a4bdd217";
                        goto compare;
                      case 128:
                        so=281;
                        resword = "5cc23ab5a2767c9936cb1860dbd9b3d2";
                        goto compare;
                      case 137:
                        so=35;
                        resword = "d84aff7313078d0e59df9c6ade93c7ee";
                        goto compare;
                      case 165:
                        so=313;
                        resword = "58fa4eb127f891c118b3a4b1abafda96";
                        goto compare;
                      case 170:
                        so=63;
                        resword = "6a927f60975644e037dddbd64e7de23e";
                        goto compare;
                      case 178:
                        so=64;
                        resword = "f8a0c82d99c7ed783a73dc7210d9bb9c";
                        goto compare;
                      case 182:
                        so=173;
                        resword = "d68ab39c62c90d083a6e4ee75c469e6c";
                        goto compare;
                      case 185:
                        so=295;
                        resword = "fa4001c1b680ca8f3b3b4ca5c066a26c";
                        goto compare;
                      case 188:
                        so=101;
                        resword = "65036aa2f711f18645b3c84819386649";
                        goto compare;
                      case 193:
                        so=27;
                        resword = "fc17458c22e60e9e44fc8edcb62fb40d";
                        goto compare;
                      case 203:
                        so=329;
                        resword = "8262e61d5cd81dd42ef40b489b749b07";
                        goto compare;
                      case 215:
                        so=132;
                        resword = "f7ea05ec31f1769e39acf0c3fd5e1872";
                        goto compare;
                      case 220:
                        so=42;
                        resword = "59eac0e460a6ae9533f67dd1338e9a59";
                        goto compare;
                      case 223:
                        so=234;
                        resword = "9620acb5420901471867223142c4a11c";
                        goto compare;
                      case 230:
                        so=161;
                        resword = "68c1a2526a55d5f8c98d37c21d8310a8";
                        goto compare;
                      case 250:
                        so=58;
                        resword = "fa927570ab5359d70643d815f1baf875";
                        goto compare;
                      case 253:
                        so=105;
                        resword = "f7a1a961c3c041942d3a1d1f83821125";
                        goto compare;
                      case 255:
                        so=244;
                        resword = "8a326a99c399c0f7045dfd1170cb8e2c";
                        goto compare;
                      case 257:
                        so=353;
                        resword = "8aaadb9e679467532e989b25d2588c92";
                        goto compare;
                      case 267:
                        so=15;
                        resword = "783af87933eaea67cd1392e66b2a99b2";
                        goto compare;
                      case 275:
                        so=325;
                        resword = "d847a07c2e382b3a2d0143da4fcd63d5";
                        goto compare;
                      case 282:
                        so=0;
                        resword = "8afaaac1c19ab4963c77aae8705d2cc5";
                        goto compare;
                      case 288:
                        so=137;
                        resword = "9c1738aa0c402e2651d969b4e1513cce";
                        goto compare;
                      case 290:
                        so=295;
                        resword = "f2c05e6f39cd8bf04e14bce59e440392";
                        goto compare;
                      case 300:
                        so=113;
                        resword = "92ba9f8e62e5f8f73b04629b8272ad98";
                        goto compare;
                      case 318:
                        so=207;
                        resword = "f520e4c327c0d4a01a06f9d92b28b454";
                        goto compare;
                      case 332:
                        so=150;
                        resword = "7a2a148bf9a89af952bba79e288e9fa2";
                        goto compare;
                      case 340:
                        so=317;
                        resword = "d49012c32d79b6eb576d3495cbab4238";
                        goto compare;
                      case 353:
                        so=269;
                        resword = "673050d3dc19641a982c8300b08aa920";
                        goto compare;
                      case 368:
                        so=296;
                        resword = "6957d4436cf4c9cf4aae112da411597e";
                        goto compare;
                      case 378:
                        so=100;
                        resword = "6cf7b40f06f322cc2d33324670c68709";
                        goto compare;
                      case 380:
                        so=261;
                        resword = "f5ca9f2a0403b71033a6f73ae6f43caf";
                        goto compare;
                      case 397:
                        so=123;
                        resword = "8f0a4e53f07944d7227748b198edc3e8";
                        goto compare;
                      case 400:
                        so=196;
                        resword = "9a41cb96c243547207eed222925b0535";
                        goto compare;
                      case 405:
                        so=111;
                        resword = "6af7ee4015b5cfac5f40bb9b4241eea1";
                        goto compare;
                      case 418:
                        so=259;
                        resword = "87d3b990d3e146f71f1dc4baac099e4f";
                        goto compare;
                      case 427:
                        so=343;
                        resword = "59eaaae57dbd7ca20e98af4b309b476d";
                        goto compare;
                      case 433:
                        so=158;
                        resword = "9770cb8b2cd0fcf89e6cc52f9ce438f5";
                        goto compare;
                      case 434:
                        so=194;
                        resword = "df1a8c8e67f01e503306928ca5a52bd2";
                        goto compare;
                      case 445:
                        so=253;
                        resword = "8aa7caeebad165a22bd2257e0cba0b1d";
                        goto compare;
                      case 447:
                        so=105;
                        resword = "86da1818b9edb4ec4c7c285902610b33";
                        goto compare;
                      case 467:
                        so=232;
                        resword = "6fcae0a4b5f30efb01f3d4373dc1efc0";
                        goto compare;
                      case 472:
                        so=70;
                        resword = "d3351880fab6a083c6125e0756067369";
                        goto compare;
                      case 478:
                        so=335;
                        resword = "96a224dc0092be7739464ac7fe40e42d";
                        goto compare;
                      case 485:
                        so=0;
                        resword = "548ab5cb03636e952826886c1d5c16a0";
                        goto compare;
                      case 505:
                        so=304;
                        resword = "8a9133ad5649d5dc948cac0d59332651";
                        goto compare;
                      case 508:
                        so=199;
                        resword = "86f799e65a76412c3e1317dca9923f27";
                        goto compare;
                      case 513:
                        so=18;
                        resword = "68a534249e37f95a4915396923e965a6";
                        goto compare;
                      case 530:
                        so=163;
                        resword = "d6d7f84b0886003b978bf8a69675bb04";
                        goto compare;
                      case 532:
                        so=192;
                        resword = "55d11ae4be7d7372c4ecf74e55aa6a05";
                        goto compare;
                      case 558:
                        so=289;
                        resword = "82d7c40cd003e19a59c78e51c5958dfe";
                        goto compare;
                      case 563:
                        so=134;
                        resword = "6ceb9dcd37d6ebe62f0345c346512710";
                        goto compare;
                      case 573:
                        so=195;
                        resword = "59256cc65b603fa05b150bea80948a05";
                        goto compare;
                      case 578:
                        so=98;
                        resword = "5547817614a0ba6d16ede5f1f17f7c63";
                        goto compare;
                      case 583:
                        so=111;
                        resword = "5590cf34614238c83ec5d2bd8ff10a02";
                        goto compare;
                      case 593:
                        so=345;
                        resword = "54903b31ded06eed91b9dd4d3f03bf19";
                        goto compare;
                      case 598:
                        so=133;
                        resword = "93e539b1c705f57d2463baf20a13e96e";
                        goto compare;
                      case 613:
                        so=319;
                        resword = "66ab9a468f58d4eb40a14c81dd8f8fe4";
                        goto compare;
                      case 618:
                        so=20;
                        resword = "77d10ca509aab54b142299cbd5754780";
                        goto compare;
                      case 620:
                        so=314;
                        resword = "7fe22ca875fa0d3337cefee4ea5947b6";
                        goto compare;
                      case 625:
                        so=297;
                        resword = "87e1c21fefed10ab2c33408fb15882e0";
                        goto compare;
                      case 635:
                        so=233;
                        resword = "977223b76d3db16192833f1aa4fba6bf";
                        goto compare;
                      case 637:
                        so=178;
                        resword = "5f62e68ba5dd47b7373203864feb452e";
                        goto compare;
                      case 638:
                        so=361;
                        resword = "928313a79a065f28d2dfd9e6a757b4d5";
                        goto compare;
                      case 648:
                        so=102;
                        resword = "f4d008b0f9f3d5e29fc0ea2fd0610d68";
                        goto compare;
                      case 653:
                        so=257;
                        resword = "9cf18e3525b5a7257c2dbaeb873c55b9";
                        goto compare;
                      case 660:
                        so=99;
                        resword = "54d7d9b8bcd550d8c7e6c09e8409c37d";
                        goto compare;
                      case 663:
                        so=282;
                        resword = "75508d5937f5d3133476a0b1d07e6e6c";
                        goto compare;
                      case 672:
                        so=193;
                        resword = "d5f76091c1bd3a804df469c45dea6f33";
                        goto compare;
                      case 677:
                        so=348;
                        resword = "df41887eb25338811c008ad57f9488d6";
                        goto compare;
                      case 688:
                        so=312;
                        resword = "92800a9842603981d3e1841d6847299d";
                        goto compare;
                      case 693:
                        so=245;
                        resword = "73377c4e6e756e82057bcd3dd8b887a6";
                        goto compare;
                      case 703:
                        so=324;
                        resword = "73b5be04b6c91bc240c66237c2c825a1";
                        goto compare;
                      case 708:
                        so=206;
                        resword = "f002ff58a7cabe80493b39c5a1864132";
                        goto compare;
                      case 713:
                        so=66;
                        resword = "f56ba4fe1d61ea272e91c7555d34fcfc";
                        goto compare;
                      case 718:
                        so=6;
                        resword = "855782afd2ea8a1095e4e0c4f676e3c0";
                        goto compare;
                      case 727:
                        so=77;
                        resword = "5caa9bd500d0a6b862f92e7aced7b043";
                        goto compare;
                      case 738:
                        so=181;
                        resword = "7635c63b49069bdc5b47d886222c2113";
                        goto compare;
                      case 753:
                        so=125;
                        resword = "50331d541a2ad03a58f03ebcf774752b";
                        goto compare;
                      case 764:
                        so=53;
                        resword = "dae4c4e8bfa96a4f40ff4409c2df7255";
                        goto compare;
                      case 797:
                        so=263;
                        resword = "da95493b40a2a4bb5c45eab1f185886a";
                        goto compare;
                      case 803:
                        so=9;
                        resword = "33a01f0e4f14c3004ce7a9c00ff9f22b";
                        goto compare;
                      case 815:
                        so=302;
                        resword = "9ce5c5bf495dca6f1295e504d56ff955";
                        goto compare;
                      case 818:
                        so=127;
                        resword = "7892c0a29fc51c127ad0f3756cc4734a";
                        goto compare;
                      case 820:
                        so=307;
                        resword = "5a2b49b57d2589d806b77163928aae16";
                        goto compare;
                      case 823:
                        so=34;
                        resword = "77d50c37d8d690c32575c1d39397e07c";
                        goto compare;
                      case 828:
                        so=215;
                        resword = "84651de5d28ae5c158215f1656b4b591";
                        goto compare;
                      case 845:
                        so=170;
                        resword = "5f87a1a09032a9390d068f43f862859e";
                        goto compare;
                      case 853:
                        so=232;
                        resword = "f36bce715ff77ebb971556a73ec84c62";
                        goto compare;
                      case 863:
                        so=268;
                        resword = "3290f6827c69aca03f7104a4d23af618";
                        goto compare;
                      case 868:
                        so=62;
                        resword = "67d106c55bb7d768d32e473fdcc47252";
                        goto compare;
                      case 870:
                        so=339;
                        resword = "3770ea7847e1b281ceecb554e603bc86";
                        goto compare;
                      case 873:
                        so=197;
                        resword = "873b3b963a84131541d37b80da88568d";
                        goto compare;
                      case 879:
                        so=352;
                        resword = "d37a6f10b203cfdf6fbf237b381dc673";
                        goto compare;
                      case 880:
                        so=250;
                        resword = "601a46f8f824ecd63a466b6462f8a1f2";
                        goto compare;
                      case 888:
                        so=235;
                        resword = "89d111d596039b9575def445106ef3cf";
                        goto compare;
                      case 890:
                        so=117;
                        resword = "56ab32374f9d8bbf41750ea6be3538c7";
                        goto compare;
                      case 893:
                        so=320;
                        resword = "7ce515400bf7a5131e850437b88e9e88";
                        goto compare;
                      case 902:
                        so=9;
                        resword = "965ad79d6333f6f8659ed9dfd8464ac9";
                        goto compare;
                      case 905:
                        so=261;
                        resword = "7afb5ee27151ec5b5bf6a04f79866df9";
                        goto compare;
                      case 913:
                        so=98;
                        resword = "72b13f1f6bc76a4a7928754d5c2f97b0";
                        goto compare;
                      case 918:
                        so=293;
                        resword = "7ca1e0124ce6b6c5d7057a7567743d51";
                        goto compare;
                      case 923:
                        so=100;
                        resword = "8062a457b9c0ae1a5291c0065a60e07a";
                        goto compare;
                      case 937:
                        so=149;
                        resword = "5cf2d9173fa1edf4ef3c94c176ea2c1a";
                        goto compare;
                      case 938:
                        so=86;
                        resword = "5417e3e2ebe9b4597fdb8124aac3fe43";
                        goto compare;
                      case 942:
                        so=247;
                        resword = "5fa253d7620a407f60e30759e4ebf851";
                        goto compare;
                      case 943:
                        so=177;
                        resword = "f3dba3fee47a15187cecdeb438c796e0";
                        goto compare;
                      case 944:
                        so=195;
                        resword = "688c78c50b307b90c3bbf608154d0db5";
                        goto compare;
                      case 947:
                        so=202;
                        resword = "5363ca319a567becedb92e6bd292b405";
                        goto compare;
                      case 948:
                        so=140;
                        resword = "69eba5ec96725ef5202a48cdfd5d2358";
                        goto compare;
                      case 953:
                        so=341;
                        resword = "8977743b420204de93b7f49bfc93b0a7";
                        goto compare;
                      case 957:
                        so=207;
                        resword = "d784fdefe5296f9f10d5c023555b3a6d";
                        goto compare;
                      case 977:
                        so=299;
                        resword = "f67c90a7f58602f40619d1b86db7f429";
                        goto compare;
                      case 978:
                        so=229;
                        resword = "60b773d13b915adf4136413f90609520";
                        goto compare;
                      case 980:
                        so=136;
                        resword = "9724c49f5c73f12b5b726698ce4902ee";
                        goto compare;
                      case 982:
                        so=346;
                        resword = "98d36d62bab4d514ee10933506c7940a";
                        goto compare;
                      case 988:
                        so=311;
                        resword = "828b4d52e633efa73b287eab466fb108";
                        goto compare;
                      case 993:
                        so=40;
                        resword = "89cbcaef7bd9928b904dd26fc5d5d485";
                        goto compare;
                      case 997:
                        so=41;
                        resword = "5f4471c402947f555d40996d8e3776e2";
                        goto compare;
                      case 998:
                        so=184;
                        resword = "769731353564c60472f50718c3357221";
                        goto compare;
                      case 1002:
                        so=190;
                        resword = "92dcc9e326e1d39425cfbe4bd8376ebe";
                        goto compare;
                      case 1007:
                        so=107;
                        resword = "5f20e4fa8304103669913cb9e13d1d03";
                        goto compare;
                      case 1010:
                        so=345;
                        resword = "3f70116c6241e42a28b1cce190eb08f1";
                        goto compare;
                      case 1015:
                        so=138;
                        resword = "9051ef3027134348cb85658b53d9a7b2";
                        goto compare;
                      case 1039:
                        so=288;
                        resword = "d60c880a76f070812d24336ea5a6820e";
                        goto compare;
                      case 1045:
                        so=317;
                        resword = "87b4cd5d8ce1462e30c25b6d5c4ec8a6";
                        goto compare;
                      case 1073:
                        so=5;
                        resword = "7425e62338871d682b36b7ad98505e20";
                        goto compare;
                      case 1088:
                        so=181;
                        resword = "fc3b0c23f3e191ffda2d4647f2977fbe";
                        goto compare;
                      case 1103:
                        so=180;
                        resword = "5c6b77c03e758d8a7e1d9ca212efe417";
                        goto compare;
                      case 1107:
                        so=337;
                        resword = "868279756c518eb3e0d4b75fd2540af6";
                        goto compare;
                      case 1138:
                        so=155;
                        resword = "3547e0a2dc20c95447e886d61d7d366b";
                        goto compare;
                      case 1158:
                        so=170;
                        resword = "36822b13a2d29cc33089822627a83a3f";
                        goto compare;
                      case 1174:
                        so=294;
                        resword = "9c9c784587bdc1e04309ebef2f0d64f7";
                        goto compare;
                      case 1188:
                        so=321;
                        resword = "875bcb38b0c331df99baf13fd6f0c902";
                        goto compare;
                      case 1193:
                        so=333;
                        resword = "34b2042fae148995128ba281324218d3";
                        goto compare;
                      case 1203:
                        so=304;
                        resword = "77551db6546af27371e6dd15010a5c1c";
                        goto compare;
                      case 1205:
                        so=333;
                        resword = "3397cd6b9dbd68be50d14f832b4ea59c";
                        goto compare;
                      case 1207:
                        so=8;
                        resword = "f4838e1c96949dc3e8727116e3e18908";
                        goto compare;
                      case 1218:
                        so=132;
                        resword = "fcb2c3c9ca04e78e805cf98c61ba1dca";
                        goto compare;
                      case 1220:
                        so=290;
                        resword = "689b71d9a06d2768738807663f47a48d";
                        goto compare;
                      case 1223:
                        so=344;
                        resword = "9cd02a4b5ffa62ad8b8bfefb542c560f";
                        goto compare;
                      case 1227:
                        so=259;
                        resword = "767c366ca836746c4ffb102c83b5b1e3";
                        goto compare;
                      case 1240:
                        so=310;
                        resword = "56e5e00e5ee761d16e95a16909f208be";
                        goto compare;
                      case 1253:
                        so=80;
                        resword = "3c6371be7609d6f0d9269f1936a44170";
                        goto compare;
                      case 1258:
                        so=155;
                        resword = "60f1c79745315c747c2877cb16efac7c";
                        goto compare;
                      case 1263:
                        so=331;
                        resword = "90b35b829bb773ed7ba11b51925c646b";
                        goto compare;
                      case 1265:
                        so=248;
                        resword = "d883373a852141ec8754017a000ba6f5";
                        goto compare;
                      case 1272:
                        so=31;
                        resword = "d8c518fdb3a359ac650cf028249529b2";
                        goto compare;
                      case 1275:
                        so=224;
                        resword = "8335f7b83100b70f67716f955d55dd64";
                        goto compare;
                      case 1278:
                        so=263;
                        resword = "32e724b10f02665923c2d0bf29ccdbc6";
                        goto compare;
                      case 1280:
                        so=141;
                        resword = "d616b6e63f1a61be5f10925258f08b8b";
                        goto compare;
                      case 1284:
                        so=195;
                        resword = "ea6ab2ea285a896cc2065fab48d654f6";
                        goto compare;
                      case 1287:
                        so=243;
                        resword = "95a79880b8eac48ae0815004d634949d";
                        goto compare;
                      case 1288:
                        so=360;
                        resword = "955bf4ced839f9d8d0cc2ecaa6bf60a3";
                        goto compare;
                      case 1290:
                        so=9;
                        resword = "fa7bc4fb93331860da02453f8c6dcd47";
                        goto compare;
                      case 1297:
                        so=1;
                        resword = "5597e3c3a586a728e282ddb58d365106";
                        goto compare;
                      case 1298:
                        so=156;
                        resword = "e260c5cbc068cc6f564f1ea4e262d601";
                        goto compare;
                      case 1305:
                        so=335;
                        resword = "5674efb2c973c7227330746b7c367bcb";
                        goto compare;
                      case 1307:
                        so=347;
                        resword = "79bced0fe9e0605e41f29cade154e88d";
                        goto compare;
                      case 1308:
                        so=49;
                        resword = "3635caebd5850c012db1e28a3abd9010";
                        goto compare;
                      case 1319:
                        so=336;
                        resword = "92b15336b9cdf9f8e7cce691306bd109";
                        goto compare;
                      case 1327:
                        so=21;
                        resword = "d354b285b0b4c23fd85a95669b51db57";
                        goto compare;
                      case 1330:
                        so=175;
                        resword = "67a68771c3a64227c6fc6909fe66f26e";
                        goto compare;
                      case 1332:
                        so=250;
                        resword = "5f419397a09228a261ccb07c1152b3b2";
                        goto compare;
                      case 1338:
                        so=101;
                        resword = "38d7ca425cd9b1a5733247d710ac9169";
                        goto compare;
                      case 1343:
                        so=228;
                        resword = "fb8072c0be07cb482c263fae8c4af21c";
                        goto compare;
                      case 1348:
                        so=271;
                        resword = "8ce65f88f3a178e15b5b6642a5aa4aba";
                        goto compare;
                      case 1353:
                        so=247;
                        resword = "3cf2a338a0974762defd2237920e9d82";
                        goto compare;
                      case 1365:
                        so=237;
                        resword = "fb2047ed60c55420c07182c9d526f453";
                        goto compare;
                      case 1370:
                        so=256;
                        resword = "d7468e493778821d4800e2cec7c1ab57";
                        goto compare;
                      case 1375:
                        so=235;
                        resword = "d0f37414b954a3a1dcf163e7976cda78";
                        goto compare;
                      case 1392:
                        so=204;
                        resword = "f5ec1313aa733c7c9bba1c8d931810c3";
                        goto compare;
                      case 1393:
                        so=243;
                        resword = "751bba5086069bde75074d22216adc01";
                        goto compare;
                      case 1398:
                        so=25;
                        resword = "9b41758b9898432d2cfbaba290cb949d";
                        goto compare;
                      case 1403:
                        so=85;
                        resword = "3ca522ba74b2b993582911f1c663458c";
                        goto compare;
                      case 1410:
                        so=317;
                        resword = "667b8befb19d94cbd090e0eba04d65b1";
                        goto compare;
                      case 1415:
                        so=350;
                        resword = "d7e679749b4084fa4451892b3b1abb74";
                        goto compare;
                      case 1423:
                        so=145;
                        resword = "f956e225da2315b14e0dd81dfaa074d4";
                        goto compare;
                      case 1428:
                        so=60;
                        resword = "93e68d8873202dee1ec725e080db9205";
                        goto compare;
                      case 1433:
                        so=34;
                        resword = "75ab22c5bff034b57fc1b47b2fa0ed4e";
                        goto compare;
                      case 1447:
                        so=242;
                        resword = "f32cac9cbc43654a7b10794a0b46ea52";
                        goto compare;
                      case 1452:
                        so=223;
                        resword = "6794a548147d11897117fa7285f9e52d";
                        goto compare;
                      case 1453:
                        so=11;
                        resword = "984724f630d8233d827d00de5af16b2b";
                        goto compare;
                      case 1463:
                        so=117;
                        resword = "90db9a98917758090d72249a2c7cb4c5";
                        goto compare;
                      case 1470:
                        so=55;
                        resword = "5cf33256d22d59c585418a51e150ab8d";
                        goto compare;
                      case 1473:
                        so=16;
                        resword = "5ce63419d05520271f093410efaf237a";
                        goto compare;
                      case 1482:
                        so=151;
                        resword = "83b4da2f193dd57b74238fcd1479a32a";
                        goto compare;
                      case 1492:
                        so=209;
                        resword = "dcc09ebb784dff0386a3d54a51d70c04";
                        goto compare;
                      case 1502:
                        so=129;
                        resword = "6ffadb3326243dcc8ec336a276c8c0d1";
                        goto compare;
                      case 1503:
                        so=122;
                        resword = "9806a06e68d48bf89ecd1fa4ee80bd7f";
                        goto compare;
                      case 1508:
                        so=79;
                        resword = "85b0dc734c164ffd81dd99668d860b82";
                        goto compare;
                      case 1510:
                        so=151;
                        resword = "9af7cafdf0a6efe38bdb9dbbb18c4ded";
                        goto compare;
                      case 1513:
                        so=197;
                        resword = "82c663424d95ff124ce8e4e27cee0c15";
                        goto compare;
                      case 1520:
                        so=343;
                        resword = "3f95bbc879c784a40016027faeeb23f3";
                        goto compare;
                      case 1523:
                        so=260;
                        resword = "e7d13082702671e5010e79a32b9b919d";
                        goto compare;
                      case 1527:
                        so=43;
                        resword = "350a767df48da54f76c36a7726c05fcd";
                        goto compare;
                      case 1528:
                        so=236;
                        resword = "e95103196d77e6312880a47d9cc47a7c";
                        goto compare;
                      case 1530:
                        so=134;
                        resword = "63b63b35797d91aa0ae005eacd00e3af";
                        goto compare;
                      case 1532:
                        so=18;
                        resword = "d0615d09e338aa0c6a4f890e2a23fa4c";
                        goto compare;
                      case 1535:
                        so=359;
                        resword = "9f15519483c21052d3cb0c2d73741709";
                        goto compare;
                      case 1548:
                        so=22;
                        resword = "322b1cc589b187c29e6cfc7fe4acd0cc";
                        goto compare;
                      case 1550:
                        so=284;
                        resword = "300a1a26ae14b0ee08ae21637943d34e";
                        goto compare;
                      case 1563:
                        so=269;
                        resword = "f4c14f9a6ec6be918e5b5386880ca281";
                        goto compare;
                      case 1565:
                        so=263;
                        resword = "80245bbdee81939e21af29c44aa01885";
                        goto compare;
                      case 1575:
                        so=189;
                        resword = "8b5ad5f111f4e39d15ec7215a7cd1392";
                        goto compare;
                      case 1580:
                        so=313;
                        resword = "3214531d922304b65e6de1a5c6ab9f25";
                        goto compare;
                      case 1595:
                        so=37;
                        resword = "37b4eadfdfa9c67e38bc1dd008a1e5ef";
                        goto compare;
                      case 1603:
                        so=140;
                        resword = "e8f7364a3c002e7b3b39cda4c3081a0a";
                        goto compare;
                      case 1609:
                        so=178;
                        resword = "f1aa160d812621b6222ee5f06aaf6013";
                        goto compare;
                      case 1628:
                        so=255;
                        resword = "f510625a6712004d8a00e4468a9cfddc";
                        goto compare;
                      case 1635:
                        so=342;
                        resword = "36a4542e861a9fdf96aecdb1cc0a623f";
                        goto compare;
                      case 1647:
                        so=246;
                        resword = "54e48292e7784c2b689dbf2536a8c08f";
                        goto compare;
                      case 1650:
                        so=299;
                        resword = "9e928035f628a983487829a35690ab76";
                        goto compare;
                      case 1655:
                        so=62;
                        resword = "d8d3b5c6ac30cee7ff7fbca37ce96cad";
                        goto compare;
                      case 1658:
                        so=165;
                        resword = "6490f08f3563830284875dbe5ea70d45";
                        goto compare;
                      case 1663:
                        so=342;
                        resword = "503530bdefc7ab337e079cfe0d1811f5";
                        goto compare;
                      case 1675:
                        so=161;
                        resword = "661235fc39bc7e9e2cd4d94b172afad3";
                        goto compare;
                      case 1680:
                        so=43;
                        resword = "fec395c3a6503d01018fd841b37a499f";
                        goto compare;
                      case 1681:
                        so=189;
                        resword = "d935c90b5edd9af0e784814d7462481e";
                        goto compare;
                      case 1682:
                        so=301;
                        resword = "3262f08369fd5bf661c55482fafc92f6";
                        goto compare;
                      case 1685:
                        so=275;
                        resword = "6bea3e64e3b13c9e7b39d93d9198346d";
                        goto compare;
                      case 1690:
                        so=276;
                        resword = "56829c4f904cb4035b435f5d5217386c";
                        goto compare;
                      case 1695:
                        so=7;
                        resword = "6c63a8dfb4dc959f36a1fc1bf45cf507";
                        goto compare;
                      case 1700:
                        so=110;
                        resword = "9e40df288540c8534e74fea328cb1f82";
                        goto compare;
                      case 1702:
                        so=88;
                        resword = "3922fedc9fc88421e735fe040ba680d1";
                        goto compare;
                      case 1713:
                        so=207;
                        resword = "574209b3e61adfb1fe78b3d79a97da5d";
                        goto compare;
                      case 1714:
                        so=206;
                        resword = "4a23a1f040e49df552bf0c7201508bf3";
                        goto compare;
                      case 1723:
                        so=104;
                        resword = "67b5f27ab4bad39880f5baace6fad3f2";
                        goto compare;
                      case 1727:
                        so=286;
                        resword = "3ac34ddff5025da265f588aa8a3d684e";
                        goto compare;
                      case 1732:
                        so=84;
                        resword = "389cbfdd1cda4ac81e02cb5abc30a885";
                        goto compare;
                      case 1740:
                        so=218;
                        resword = "5a4d8b067f3970c23a76d622925de4b2";
                        goto compare;
                      case 1756:
                        so=173;
                        resword = "4a91fa33c5c80d19c978a248e401879e";
                        goto compare;
                      case 1758:
                        so=169;
                        resword = "74639dd47fc955ea880f70b8d15850d9";
                        goto compare;
                      case 1763:
                        so=121;
                        resword = "925d3134856a94aa1dbc850fe92cc5bf";
                        goto compare;
                      case 1785:
                        so=351;
                        resword = "9750fd73150c555a22dec3e41787cee1";
                        goto compare;
                      case 1789:
                        so=104;
                        resword = "43f0d894c3d3088ac63b0b7dc8005d97";
                        goto compare;
                      case 1798:
                        so=339;
                        resword = "82ad99802769f02e051c228c78e8eb19";
                        goto compare;
                      case 1808:
                        so=237;
                        resword = "5de267c4f300537d20e5e1deeda77447";
                        goto compare;
                      case 1809:
                        so=46;
                        resword = "f7d450b203037a8dee3c092dcf838980";
                        goto compare;
                      case 1810:
                        so=59;
                        resword = "697a8d06f09bab2b5a283f4df0cdc9ad";
                        goto compare;
                      case 1820:
                        so=27;
                        resword = "8b8583a78f612013c7199ce1d0f03b02";
                        goto compare;
                      case 1822:
                        so=172;
                        resword = "81d040fd3b809d9a464ed62f15952afd";
                        goto compare;
                      case 1830:
                        so=8;
                        resword = "fd11f6300c0026fdc0d5f54414be5e92";
                        goto compare;
                      case 1863:
                        so=270;
                        resword = "f937a2479ed1e4cfffcb96af005ae8ce";
                        goto compare;
                      case 1869:
                        so=352;
                        resword = "427a26b9eac691c69c5fbf8398cc1f54";
                        goto compare;
                      case 1878:
                        so=117;
                        resword = "9216f8a178e4b21bdf9edad10939eb17";
                        goto compare;
                      case 1883:
                        so=45;
                        resword = "689be5233b1521048277806fd887ea71";
                        goto compare;
                      case 1887:
                        so=29;
                        resword = "fbc56e20561d355cca505bed06a2c1be";
                        goto compare;
                      case 1890:
                        so=47;
                        resword = "d99621b420b31f95774ba842ae6246e9";
                        goto compare;
                      case 1894:
                        so=298;
                        resword = "8e5acbeeb723307cc4590a72cbc3118a";
                        goto compare;
                      case 1897:
                        so=201;
                        resword = "7363cec2f49c4decc4a488d32c707d67";
                        goto compare;
                      case 1902:
                        so=120;
                        resword = "d2a37b15e45d825cfa8ac310db67024d";
                        goto compare;
                      case 1905:
                        so=173;
                        resword = "5c5a6ceaabc0a53caa763275b551609d";
                        goto compare;
                      case 1915:
                        so=357;
                        resword = "920a064b569ecd7455622d3b6e13edf1";
                        goto compare;
                      case 1920:
                        so=246;
                        resword = "6a20d817d8fee1a423c8cc8fb6d27a92";
                        goto compare;
                      case 1943:
                        so=231;
                        resword = "62838ac2de4413b6a72ad4c823aee951";
                        goto compare;
                      case 1947:
                        so=244;
                        resword = "a7024cccb22a2c074b6e9e9515b891ff";
                        goto compare;
                      case 1950:
                        so=118;
                        resword = "60b6f5d562c1ad65c296a82549a658fe";
                        goto compare;
                      case 1952:
                        so=119;
                        resword = "a7635bd0c0c9239d25a6fbf9e02f0434";
                        goto compare;
                      case 1953:
                        so=91;
                        resword = "f9b399a528702614a172d19414991e00";
                        goto compare;
                      case 1960:
                        so=51;
                        resword = "9daa2c26a8e3981b06c8a20b974485ec";
                        goto compare;
                      case 1964:
                        so=356;
                        resword = "d9aa81aea6bebf0fccbe703ef72bbdf8";
                        goto compare;
                      case 1970:
                        so=280;
                        resword = "fa31f1a1d23832b5ae96a1a599d50f2f";
                        goto compare;
                      case 1974:
                        so=4;
                        resword = "aa402650f32ac2c3360e185bb2927568";
                        goto compare;
                      case 1977:
                        so=314;
                        resword = "a6d097a1aef7b6d94a7ee284afd185fd";
                        goto compare;
                      case 1980:
                        so=277;
                        resword = "53da0d88d1eb0ecf92e52748669be048";
                        goto compare;
                      case 1981:
                        so=343;
                        resword = "678884655e5a4b00c14ad96e4ca3b270";
                        goto compare;
                      case 1983:
                        so=354;
                        resword = "e5e78c6bdaa32a2d939f1f2e6ddb1ecc";
                        goto compare;
                      case 1985:
                        so=288;
                        resword = "9e076cfd35556589428eaf00f6eb2570";
                        goto compare;
                      case 1988:
                        so=353;
                        resword = "5397374b511b70e745c6868da5fef5f9";
                        goto compare;
                      case 1993:
                        so=200;
                        resword = "e205a0f560e23cda2005a679ef6c7f0e";
                        goto compare;
                      case 1996:
                        so=128;
                        resword = "aaaac9c81fea02381ad891b21be8d300";
                        goto compare;
                      case 1997:
                        so=184;
                        resword = "d8d4fa82a4279d8989ad05c6257cb1ae";
                        goto compare;
                      case 2003:
                        so=6;
                        resword = "6730779485a1f416a6b8c7a01f8a0076";
                        goto compare;
                      case 2004:
                        so=83;
                        resword = "39dc993af13de48502d6de231c8c9ba3";
                        goto compare;
                      case 2008:
                        so=51;
                        resword = "9895ae1277581c00f5d070a949238832";
                        goto compare;
                      case 2009:
                        so=106;
                        resword = "33fcb81fb8cd1b7d10ac5a644f9bc4fc";
                        goto compare;
                      case 2018:
                        so=50;
                        resword = "3610bdd3bcd048fb8d14643f5de68e8c";
                        goto compare;
                      case 2023:
                        so=128;
                        resword = "f50520107e1249db88c247e8e9d0b943";
                        goto compare;
                    }
                }
              else
                {
                  switch (key - 2111)
                    {
                      case 0:
                        so=335;
                        resword = "a293de1ad873f1f74a0ed9c02aee5d3e";
                        goto compare;
                      case 1:
                        so=302;
                        resword = "55a31130836eb51e4bcef3ccb825de05";
                        goto compare;
                      case 6:
                        so=105;
                        resword = "e97550251382be20444555797bdcae2a";
                        goto compare;
                      case 11:
                        so=94;
                        resword = "d9f82df02ad01568c18c301739484c92";
                        goto compare;
                      case 16:
                        so=235;
                        resword = "7223b56f17ab20ec4419bcbf329e9dc8";
                        goto compare;
                      case 31:
                        so=112;
                        resword = "5de7704ff427b07d4dded8573aaf5f79";
                        goto compare;
                      case 41:
                        so=60;
                        resword = "8d6352f26d5936a591afc8ae2f437a0f";
                        goto compare;
                      case 46:
                        so=143;
                        resword = "f530566390bbb73d9ab83ffe96119ac9";
                        goto compare;
                      case 50:
                        so=192;
                        resword = "e3e47374657362d1cbe9dcf24fa1d02a";
                        goto compare;
                      case 57:
                        so=153;
                        resword = "f78892616d5a68bc12c32e5583109a64";
                        goto compare;
                      case 61:
                        so=282;
                        resword = "ecd589210a7046ef7df4d4e16ea9b2d4";
                        goto compare;
                      case 63:
                        so=349;
                        resword = "8f2dcaa690e543cb23be8fc0f8b3ba08";
                        goto compare;
                      case 66:
                        so=175;
                        resword = "fdd509d29c0ac3ef423224bc0808b579";
                        goto compare;
                      case 67:
                        so=268;
                        resword = "4f219c5bb470eecc33708f780453e6a0";
                        goto compare;
                      case 75:
                        so=51;
                        resword = "5b3a5d2e9013a0986f00338016cab268";
                        goto compare;
                      case 76:
                        so=122;
                        resword = "7820cc07586bca353d6d89e9dcf16c03";
                        goto compare;
                      case 78:
                        so=132;
                        resword = "6fedc54b540311791c80f4ba14926983";
                        goto compare;
                      case 81:
                        so=214;
                        resword = "7d2086f7e9e47c9e033c8af6fc8d5ec5";
                        goto compare;
                      case 83:
                        so=124;
                        resword = "6fb054c9353eb0ec404d065078c0c5db";
                        goto compare;
                      case 85:
                        so=343;
                        resword = "5f3aadd1355a08cda011b9b00ab04bb5";
                        goto compare;
                      case 88:
                        so=292;
                        resword = "50bb381e421db58dd11f0f466ef81532";
                        goto compare;
                      case 96:
                        so=303;
                        resword = "805689ebbfb8c2500c5a74d2e2ff40e3";
                        goto compare;
                      case 100:
                        so=63;
                        resword = "61c115e63e48e1f17f10e9b82d106a5a";
                        goto compare;
                      case 105:
                        so=40;
                        resword = "ff8684dd4d3001a36403c4a22059353b";
                        goto compare;
                      case 123:
                        so=272;
                        resword = "6f33e630881401a0a1357c61d60a8047";
                        goto compare;
                      case 125:
                        so=124;
                        resword = "a93123f2aec735e2006b3ca192c4212d";
                        goto compare;
                      case 131:
                        so=56;
                        resword = "3b417169b697f2e6563ba316473bea3d";
                        goto compare;
                      case 133:
                        so=191;
                        resword = "e38763870ff149cb6ee91549cc9fe9a6";
                        goto compare;
                      case 140:
                        so=221;
                        resword = "4525d2abf368b6805f1b3c5ba6c4a2dc";
                        goto compare;
                      case 141:
                        so=54;
                        resword = "e54b295a2f35f333350ad39afc25c55a";
                        goto compare;
                      case 143:
                        so=131;
                        resword = "d8450331d6136ee7fb2784742a2591dd";
                        goto compare;
                      case 146:
                        so=325;
                        resword = "82858b3ca4d13c52f81f1b04947e2ba5";
                        goto compare;
                      case 157:
                        so=179;
                        resword = "a2706fa686ad6f3502edb1cf1893d8b2";
                        goto compare;
                      case 158:
                        so=133;
                        resword = "739a464e9d94681ea06cc01150923d62";
                        goto compare;
                      case 160:
                        so=97;
                        resword = "9eba041c0078195ad0ddc8268785694f";
                        goto compare;
                      case 175:
                        so=79;
                        resword = "33db8e64e31d5c206d217aa82e4ff60b";
                        goto compare;
                      case 180:
                        so=296;
                        resword = "de95ac1fddd3e7c452fe01cf425a6c80";
                        goto compare;
                      case 187:
                        so=141;
                        resword = "8ce8bc2543656f223859f1afa943683b";
                        goto compare;
                      case 190:
                        so=350;
                        resword = "fbf1fe109dd853ebe038b4b395815122";
                        goto compare;
                      case 193:
                        so=157;
                        resword = "3b4167429dd386f9c9f6ce28f6dd4b3a";
                        goto compare;
                      case 195:
                        so=272;
                        resword = "436bf4bab50ae4c00f35e34a16f78559";
                        goto compare;
                      case 198:
                        so=14;
                        resword = "fefb1ae344376dd44306fe5273269e9f";
                        goto compare;
                      case 210:
                        so=302;
                        resword = "675c883404019e2e8dac05ad11ebf578";
                        goto compare;
                      case 213:
                        so=312;
                        resword = "754a2f6918eb299c3704a906c8cdd15f";
                        goto compare;
                      case 215:
                        so=50;
                        resword = "df4d281128225a7234856adcd09e0635";
                        goto compare;
                      case 218:
                        so=103;
                        resword = "77c0f0c7da3ef5b1c7768177c074645f";
                        goto compare;
                      case 223:
                        so=230;
                        resword = "74dd8a766815440bceafd904f91be8ec";
                        goto compare;
                      case 225:
                        so=111;
                        resword = "83bc3d2790c65be98a0b61cee7cac7fa";
                        goto compare;
                      case 242:
                        so=219;
                        resword = "a44a461943f3bece47aa655929e683a8";
                        goto compare;
                      case 245:
                        so=10;
                        resword = "6bb40e9ed77dfd2e3529edc0c8c32111";
                        goto compare;
                      case 247:
                        so=182;
                        resword = "38c4778355788cc6e4c5c6883e68cd86";
                        goto compare;
                      case 257:
                        so=340;
                        resword = "8c68b05937e2b572563e229c38076b46";
                        goto compare;
                      case 272:
                        so=25;
                        resword = "472aed7f63411994db43e2ea0ffc17d7";
                        goto compare;
                      case 273:
                        so=87;
                        resword = "f68d124db85464ef618ee66c21dc40d6";
                        goto compare;
                      case 275:
                        so=174;
                        resword = "8bb0e168efa65ac9e5cb02f3e015767f";
                        goto compare;
                      case 276:
                        so=256;
                        resword = "5737029a8e1be9109b806bdc431ac504";
                        goto compare;
                      case 280:
                        so=126;
                        resword = "61cb4e5a2e257f1143b7df3c9e8d77a6";
                        goto compare;
                      case 281:
                        so=239;
                        resword = "72571809debb5e5a0375379b55ee941c";
                        goto compare;
                      case 286:
                        so=32;
                        resword = "935d41b35f6229cd71403c92414c9948";
                        goto compare;
                      case 298:
                        so=339;
                        resword = "f755f885df0c975192f43a10c29253fd";
                        goto compare;
                      case 305:
                        so=347;
                        resword = "a7639957f522264933ab70a406f2ecca";
                        goto compare;
                      case 311:
                        so=294;
                        resword = "9b7561b9daa716a7d72d5011fd83e5cf";
                        goto compare;
                      case 316:
                        so=315;
                        resword = "748d874e2748126c93201f21c26fcb39";
                        goto compare;
                      case 322:
                        so=285;
                        resword = "87a8109db216747f98435e387d16e17a";
                        goto compare;
                      case 323:
                        so=223;
                        resword = "39a1c07da83d30cd8ae0d2f7141e87eb";
                        goto compare;
                      case 328:
                        so=231;
                        resword = "e07a5c7fdf72b7eb349104e8d1b349bb";
                        goto compare;
                      case 332:
                        so=142;
                        resword = "d1f5fb1a2222b8655320b906cee72bf4";
                        goto compare;
                      case 333:
                        so=171;
                        resword = "5a725144cafbe7cadfd93d3eb32e1b3f";
                        goto compare;
                      case 336:
                        so=240;
                        resword = "8457510528931374f6a8ed30cabbfeb8";
                        goto compare;
                      case 341:
                        so=61;
                        resword = "fc5b665002928a8ffaea29de1bfbc68f";
                        goto compare;
                      case 350:
                        so=81;
                        resword = "9e84b8e987d16279079c2c9f136fd017";
                        goto compare;
                      case 351:
                        so=68;
                        resword = "e9ab6a41d9a793857e557664684bf182";
                        goto compare;
                      case 373:
                        so=56;
                        resword = "576d026ea501567169a8748c448c5712";
                        goto compare;
                      case 376:
                        so=132;
                        resword = "75a5297f46f6529ff4b1154cd97a6a2a";
                        goto compare;
                      case 382:
                        so=249;
                        resword = "3fecf3e174687957d2718e6713013960";
                        goto compare;
                      case 397:
                        so=139;
                        resword = "6508713a876984f07e8208fb2c37a6d8";
                        goto compare;
                      case 410:
                        so=68;
                        resword = "342b3cfcd72a033fe0a4e938d3ea2cee";
                        goto compare;
                      case 416:
                        so=296;
                        resword = "73c7397740bbc96d9b08874cea4a9901";
                        goto compare;
                      case 425:
                        so=60;
                        resword = "e44c4e6c78f1c9122215c6910dd00084";
                        goto compare;
                      case 430:
                        so=280;
                        resword = "5de4a74ab0e46909c8115b39b46202d7";
                        goto compare;
                      case 437:
                        so=20;
                        resword = "79d8aea665617b479df5919dd7bdb720";
                        goto compare;
                      case 443:
                        so=334;
                        resword = "590d2de18ea52da966219b9819de297b";
                        goto compare;
                      case 447:
                        so=74;
                        resword = "31d131985d002fb5c1c19d113aba711e";
                        goto compare;
                      case 458:
                        so=163;
                        resword = "7ffd8198ad4abfd679836f3c1d6ecb6f";
                        goto compare;
                      case 469:
                        so=84;
                        resword = "480236eab5aa3c1deb7c08829a38fd6c";
                        goto compare;
                      case 477:
                        so=176;
                        resword = "3a7ca0ece67272cfd6cddcd99526290d";
                        goto compare;
                      case 484:
                        so=191;
                        resword = "613ca4f6c9d9fa2b525ed199f4981579";
                        goto compare;
                      case 488:
                        so=203;
                        resword = "dc6bfe734a0e1c9c3aa4c9c48394fa69";
                        goto compare;
                      case 489:
                        so=160;
                        resword = "61b212ad79d9351bee7295ab128658bb";
                        goto compare;
                      case 494:
                        so=27;
                        resword = "4c204d0b98cd22a76273240e8f79ef15";
                        goto compare;
                      case 511:
                        so=187;
                        resword = "465a4cc3e07990a7e28d4baa4a5f5049";
                        goto compare;
                      case 519:
                        so=127;
                        resword = "5f6ae22c039c33026f21c20cdb68e3ed";
                        goto compare;
                      case 521:
                        so=355;
                        resword = "6445faea091e42d72d467f9a8a7c2919";
                        goto compare;
                      case 525:
                        so=124;
                        resword = "9e11c2b05a63a1be674eb9acc263b312";
                        goto compare;
                      case 537:
                        so=228;
                        resword = "8528c2458eb885b87099b24ee83388e6";
                        goto compare;
                      case 545:
                        so=33;
                        resword = "a6d2c6597e0233167a563327a17b534b";
                        goto compare;
                      case 546:
                        so=88;
                        resword = "836b74fd00a1e097aaa92a60d33a8acb";
                        goto compare;
                      case 551:
                        so=301;
                        resword = "e485e8fbb1f7b633d30e5f9cb37dbe62";
                        goto compare;
                      case 557:
                        so=96;
                        resword = "f3a15d046d8cf6aded5ceb1ab94f3629";
                        goto compare;
                      case 558:
                        so=360;
                        resword = "e7ab1a0fd416ad8d6c003bbe9883ce69";
                        goto compare;
                      case 577:
                        so=127;
                        resword = "6a5c2563f5576bcbf589985de2e9b140";
                        goto compare;
                      case 581:
                        so=18;
                        resword = "d1021a4c05e450a9e6e07c14ce23e9f5";
                        goto compare;
                      case 585:
                        so=306;
                        resword = "45a03184bc62717ede99b35e8869b4ad";
                        goto compare;
                      case 588:
                        so=340;
                        resword = "603496ea4a71b53388735406beebe156";
                        goto compare;
                      case 591:
                        so=352;
                        resword = "d2c800a93876eacf6bba8492e5d21577";
                        goto compare;
                      case 597:
                        so=85;
                        resword = "5e0cba6c164741cb25e25d0122b21356";
                        goto compare;
                      case 599:
                        so=358;
                        resword = "4cd10293e0205fabe6e342f6be8cfcbc";
                        goto compare;
                      case 600:
                        so=356;
                        resword = "30237f9881b29ea8ea594c5a46f1a16f";
                        goto compare;
                      case 617:
                        so=178;
                        resword = "3308d59ba600dd525f4388b0e9def6d5";
                        goto compare;
                      case 621:
                        so=210;
                        resword = "e791cd1f9efa70488b316881a19ddf1d";
                        goto compare;
                      case 623:
                        so=46;
                        resword = "3f9d5a7061ca65351bccb60c0905d984";
                        goto compare;
                      case 642:
                        so=8;
                        resword = "59dc627aea8c33a40720bd47c2a12a55";
                        goto compare;
                      case 644:
                        so=154;
                        resword = "4f2b90d4a41d70ef246a6378aaa44734";
                        goto compare;
                      case 650:
                        so=229;
                        resword = "dd74590ebea529ac173bed8a9bcdbd5d";
                        goto compare;
                      case 654:
                        so=205;
                        resword = "d1479cb9269d72d1d8411c8d67eeafef";
                        goto compare;
                      case 656:
                        so=93;
                        resword = "644b22723dbe4a9e584c9cbf7059b649";
                        goto compare;
                      case 657:
                        so=274;
                        resword = "a610f8b8562dee6cd34d9109da62d3ce";
                        goto compare;
                      case 666:
                        so=333;
                        resword = "8d2bf69b8d4336dc17f1a74f31d299e3";
                        goto compare;
                      case 667:
                        so=360;
                        resword = "dd5cbb07d77a9fe501f3f7a1008d5403";
                        goto compare;
                      case 668:
                        so=333;
                        resword = "357db6eba34d334b2d7931347e60a51c";
                        goto compare;
                      case 677:
                        so=346;
                        resword = "375800883fb91e3e49d7dcf34633fd1e";
                        goto compare;
                      case 680:
                        so=68;
                        resword = "e34affbc57dd069d89ff51723605e0c4";
                        goto compare;
                      case 686:
                        so=99;
                        resword = "faa835d177c31bb26e6c5d36321567e3";
                        goto compare;
                      case 697:
                        so=52;
                        resword = "a5516436b34afea565e4ac1599f4cb8a";
                        goto compare;
                      case 701:
                        so=148;
                        resword = "80b0c27618b69d21a818af2bbeed783d";
                        goto compare;
                      case 710:
                        so=329;
                        resword = "3e6a375fa0924b061d2b2a9283ed3dfb";
                        goto compare;
                      case 717:
                        so=88;
                        resword = "a6544f719a6354a803e8581965447e05";
                        goto compare;
                      case 721:
                        so=71;
                        resword = "396170c36af68c6aa7aab073e7316c04";
                        goto compare;
                      case 736:
                        so=120;
                        resword = "6be7e5bd70d7968d8ea142aba13a534a";
                        goto compare;
                      case 740:
                        so=310;
                        resword = "57bc9fc8efabd2204e6eb98204417e81";
                        goto compare;
                      case 757:
                        so=47;
                        resword = "af124ad880039ba7d1fceb561d70bd7d";
                        goto compare;
                      case 760:
                        so=323;
                        resword = "9d710d8f00b46bebec965f3d9aee0fca";
                        goto compare;
                      case 762:
                        so=273;
                        resword = "4754c644dcba9b797ccd3730ccb97783";
                        goto compare;
                      case 765:
                        so=244;
                        resword = "3a509329412c24187ca0e2b7d5d3eda3";
                        goto compare;
                      case 770:
                        so=276;
                        resword = "640cffac2664b6c6fe2cf583f61e9c48";
                        goto compare;
                      case 772:
                        so=136;
                        resword = "a6442654e4d46b0797a44eb2b397e6c0";
                        goto compare;
                      case 792:
                        so=337;
                        resword = "a7142c1f80f9813193777525ab54710a";
                        goto compare;
                      case 813:
                        so=356;
                        resword = "ddbb06297c55bdc57d3aede774e0d3aa";
                        goto compare;
                      case 814:
                        so=108;
                        resword = "5f2861f5ece27c9e7bc2986de8b3ea38";
                        goto compare;
                      case 816:
                        so=108;
                        resword = "e6735c5c4bcaa6fcfd5366eb8723289f";
                        goto compare;
                      case 825:
                        so=139;
                        resword = "42566de41f88b05c45ce5eaae88f4d2d";
                        goto compare;
                      case 826:
                        so=19;
                        resword = "e7c68255e55212aa5593efee40496299";
                        goto compare;
                      case 832:
                        so=218;
                        resword = "a387e41f1afd5887d030ea0da2f92e49";
                        goto compare;
                      case 837:
                        so=24;
                        resword = "9b6c8bf481f164be6d00a910abeb1958";
                        goto compare;
                      case 846:
                        so=29;
                        resword = "718c57234b676f4fcc838427165f3530";
                        goto compare;
                      case 849:
                        so=121;
                        resword = "af6b7d575a6dbb185587454d1ac72b0d";
                        goto compare;
                      case 861:
                        so=116;
                        resword = "965d9bb802d0e1ae8565d3732d4a2dbe";
                        goto compare;
                      case 862:
                        so=311;
                        resword = "35486a473d13d0d859d56f9e5a1f58dd";
                        goto compare;
                      case 865:
                        so=242;
                        resword = "3b925483eb2da7956a7646f97eaeb0ee";
                        goto compare;
                      case 868:
                        so=217;
                        resword = "fdd4116a1d8ae1f8d2534da99d6d4c43";
                        goto compare;
                      case 878:
                        so=141;
                        resword = "3a43cbf67b62cc20ac2fb8c1770b98fb";
                        goto compare;
                      case 885:
                        so=53;
                        resword = "e1c38da9bb844a245caa4b1cd1f541be";
                        goto compare;
                      case 888:
                        so=172;
                        resword = "79141b8cf620a618a18d1c810114770d";
                        goto compare;
                      case 890:
                        so=251;
                        resword = "db125f7c410cf2ea2591a62eb2fe1518";
                        goto compare;
                      case 916:
                        so=283;
                        resword = "3d6795129412131a4a889d781c3de0da";
                        goto compare;
                      case 921:
                        so=118;
                        resword = "37ab0bbaa649df6cf875be303defe0d7";
                        goto compare;
                      case 927:
                        so=241;
                        resword = "6e9575adf0541976e966346a0bf84a8f";
                        goto compare;
                      case 929:
                        so=356;
                        resword = "a9a387197383cac5e6e5bbf0c3f23fe3";
                        goto compare;
                      case 931:
                        so=213;
                        resword = "6218f023eca3501aeaccf18a5a5a65ca";
                        goto compare;
                      case 941:
                        so=225;
                        resword = "657d496080840ad98641ca9c280004b3";
                        goto compare;
                      case 945:
                        so=358;
                        resword = "4266167d0d0572d1507fde0d6c7eaf9c";
                        goto compare;
                      case 946:
                        so=313;
                        resword = "e8c5b29380350b87869357dc507372b2";
                        goto compare;
                      case 960:
                        so=140;
                        resword = "a017a865b0e68b769a0515b10c7623f6";
                        goto compare;
                      case 961:
                        so=197;
                        resword = "801bd891b776a29ef7db78b699a2c517";
                        goto compare;
                      case 967:
                        so=131;
                        resword = "40f4aabedad9091250900f2da0d5d7a8";
                        goto compare;
                      case 970:
                        so=161;
                        resword = "4f9c37ae895dc4adcc8fbf461949171f";
                        goto compare;
                      case 976:
                        so=53;
                        resword = "e585acbb23c6ed098ea3f1d79be754d9";
                        goto compare;
                      case 985:
                        so=10;
                        resword = "57dcf5c4893581b7a683f11cc6c862bc";
                        goto compare;
                      case 991:
                        so=26;
                        resword = "30e25f9a741640bbf82ab95311d42cc2";
                        goto compare;
                      case 996:
                        so=41;
                        resword = "5a80ee8ad1098c93b6468dab6309f427";
                        goto compare;
                      case 1008:
                        so=297;
                        resword = "5afabbeb1c319240b4da1d2a9d99014d";
                        goto compare;
                      case 1015:
                        so=57;
                        resword = "724ca7f3d9caecd2aaf1dd253d65277c";
                        goto compare;
                      case 1017:
                        so=298;
                        resword = "54bae99c69be6532ea7bd5ddbb1a2fb3";
                        goto compare;
                      case 1021:
                        so=305;
                        resword = "e573849a73c753b8f7ab9d9f84b6d63a";
                        goto compare;
                      case 1023:
                        so=317;
                        resword = "3013895c5b8cbbab5650415bee1a496e";
                        goto compare;
                      case 1024:
                        so=100;
                        resword = "47740e4443dd4f87777e12f3ce21a606";
                        goto compare;
                      case 1025:
                        so=34;
                        resword = "8a06f0a33facab0b0fe0824a439f1ac4";
                        goto compare;
                      case 1026:
                        so=206;
                        resword = "8d73b7eaf138bdda890c5157f86a9330";
                        goto compare;
                      case 1033:
                        so=279;
                        resword = "3072c0d2f22c133e4a467fb23effc98e";
                        goto compare;
                      case 1041:
                        so=130;
                        resword = "e2d11c3bce05ffbbfa83b8ee2dbf28da";
                        goto compare;
                      case 1045:
                        so=327;
                        resword = "3984dbef832c0b6e5c60c366d3527e68";
                        goto compare;
                      case 1046:
                        so=31;
                        resword = "70dd1ad58b8263129f01386f67bd4918";
                        goto compare;
                      case 1053:
                        so=260;
                        resword = "d3ea585bc35f4de73a80c5352c155bdf";
                        goto compare;
                      case 1064:
                        so=129;
                        resword = "63e09511198f7e2f125b4a55e9bb8954";
                        goto compare;
                      case 1068:
                        so=220;
                        resword = "eca431ebe436a6978b81c2e9fa718cb6";
                        goto compare;
                      case 1070:
                        so=76;
                        resword = "8f0bf02e6f2c8501da1e330782ed9b79";
                        goto compare;
                      case 1071:
                        so=221;
                        resword = "34b55b47d2d52eaef41930e86018c31f";
                        goto compare;
                      case 1081:
                        so=188;
                        resword = "9da2553a4b3309f5866b9af682a72477";
                        goto compare;
                      case 1093:
                        so=38;
                        resword = "e6f0d63b392c2c829dc462cfb816cd9a";
                        goto compare;
                      case 1096:
                        so=158;
                        resword = "6b50f83715a2f88ffb87723c41ae02da";
                        goto compare;
                      case 1106:
                        so=1;
                        resword = "fb371c115fc5c53af002b0329ab95669";
                        goto compare;
                      case 1118:
                        so=204;
                        resword = "ea60d2f47c7e06685c211747abf32d3a";
                        goto compare;
                      case 1128:
                        so=230;
                        resword = "ff9a1cf60affad744d890966687a1e8d";
                        goto compare;
                      case 1130:
                        so=34;
                        resword = "efa6c0bb4a6d18359723b91f23b13bbc";
                        goto compare;
                      case 1134:
                        so=64;
                        resword = "4f249713d927999dd5ba761920bf0eb6";
                        goto compare;
                      case 1136:
                        so=353;
                        resword = "5a91580cca9486f4bbb8893cd5225348";
                        goto compare;
                      case 1141:
                        so=255;
                        resword = "483c9cb142e6c8b96763111996cdc8bc";
                        goto compare;
                      case 1161:
                        so=158;
                        resword = "8df6149202966a6a19a9c88d28c074b0";
                        goto compare;
                      case 1166:
                        so=164;
                        resword = "8bcb0c9d2154b5008ec5316ae7457ca4";
                        goto compare;
                      case 1172:
                        so=115;
                        resword = "e8b8b41d26c72f415bdc4241029858b8";
                        goto compare;
                      case 1176:
                        so=130;
                        resword = "90ebbb7944c0337ca68baeaa83948554";
                        goto compare;
                      case 1186:
                        so=159;
                        resword = "659a0ca788252132bf6ce3f26fbd76d3";
                        goto compare;
                      case 1191:
                        so=24;
                        resword = "92873377677f3fccccfc25d6fc9a234c";
                        goto compare;
                      case 1214:
                        so=191;
                        resword = "69a7b9ac4b78b483b112f57606753869";
                        goto compare;
                      case 1218:
                        so=357;
                        resword = "f6bde814e99c82be02ed53b0b4994f6f";
                        goto compare;
                      case 1227:
                        so=61;
                        resword = "8b18b05bbbe9ab65571aad6b7778b17b";
                        goto compare;
                      case 1228:
                        so=129;
                        resword = "e7caac9741e43fffab23d6ba8ba510b2";
                        goto compare;
                      case 1229:
                        so=196;
                        resword = "8af85ad65e98db178672e4d6b1f64c51";
                        goto compare;
                      case 1233:
                        so=216;
                        resword = "6616c4c6512cf7967e2138fcc819fc00";
                        goto compare;
                      case 1239:
                        so=330;
                        resword = "51d4300733e2866f6c759c58002d5f79";
                        goto compare;
                      case 1241:
                        so=46;
                        resword = "9613dac8b25dcd22b4be0c05559b6ab4";
                        goto compare;
                      case 1244:
                        so=103;
                        resword = "a37bdf44974a7b05e15009b8d97b24d4";
                        goto compare;
                      case 1248:
                        so=238;
                        resword = "dbf0f4dfefb54341a5c25197459c08a5";
                        goto compare;
                      case 1252:
                        so=281;
                        resword = "4e60542b59366f620dc6f5395546c4f4";
                        goto compare;
                      case 1258:
                        so=113;
                        resword = "5e214be6ef09b83bf3001e362cc77c59";
                        goto compare;
                      case 1266:
                        so=85;
                        resword = "76e6512add5b7e3705300f51df59378a";
                        goto compare;
                      case 1271:
                        so=253;
                        resword = "5005ee556942eb54a2645bf16c49556b";
                        goto compare;
                      case 1273:
                        so=6;
                        resword = "eb5113427480b83967d0235f395ff2d4";
                        goto compare;
                      case 1276:
                        so=277;
                        resword = "f26dcd06329be08c45846a308942ec52";
                        goto compare;
                      case 1283:
                        so=262;
                        resword = "dc9d456ca65b0d1952b22516f9c0ff3a";
                        goto compare;
                      case 1286:
                        so=83;
                        resword = "454cb8bc5a88ff0a668e974fcc630083";
                        goto compare;
                      case 1287:
                        so=35;
                        resword = "afe37a4f0400b2e38cd2fe88e5909096";
                        goto compare;
                      case 1288:
                        so=318;
                        resword = "f21d000855bc8b9f1c438eb17dc656be";
                        goto compare;
                      case 1289:
                        so=190;
                        resword = "f875c442489fd0284c5790e4963418a5";
                        goto compare;
                      case 1291:
                        so=114;
                        resword = "e6e76487b61b39d03d9fb26b47174cfc";
                        goto compare;
                      case 1292:
                        so=21;
                        resword = "4dba29819b082a9c5e38a191b785447a";
                        goto compare;
                      case 1302:
                        so=262;
                        resword = "4ef345d1317a0b4b1dc8f6e866b19fe7";
                        goto compare;
                      case 1317:
                        so=135;
                        resword = "6738604181236caa88b24541613d619b";
                        goto compare;
                      case 1323:
                        so=286;
                        resword = "dd3d2f78cbf182db2bf137892a2481d0";
                        goto compare;
                      case 1326:
                        so=316;
                        resword = "e490e8ce6cfbc0b1358d38bb90d34778";
                        goto compare;
                      case 1327:
                        so=259;
                        resword = "8e3ade00aacc075e2590e49e05327892";
                        goto compare;
                      case 1329:
                        so=180;
                        resword = "59f101f86d9fa76f929837c5154eb90b";
                        goto compare;
                      case 1331:
                        so=318;
                        resword = "d9b27f644a3212beb9c39c8e574cf9a7";
                        goto compare;
                      case 1333:
                        so=199;
                        resword = "57860065412c56c57d6ac710f50482cc";
                        goto compare;
                      case 1339:
                        so=63;
                        resword = "677736878857d9d7bafe75ea46ae92cf";
                        goto compare;
                      case 1340:
                        so=152;
                        resword = "d63ad0723f7b9928f738432176ae8eeb";
                        goto compare;
                      case 1351:
                        so=139;
                        resword = "281aee163d39efd245a3146cd6743559";
                        goto compare;
                      case 1353:
                        so=71;
                        resword = "9e1d8a8c8e5479751b1d16a21921ad43";
                        goto compare;
                      case 1364:
                        so=256;
                        resword = "94005f15b01fdf49185a24d826c4c96a";
                        goto compare;
                      case 1378:
                        so=308;
                        resword = "ee22ab397506e10cd05e979da4485b56";
                        goto compare;
                      case 1384:
                        so=185;
                        resword = "e3d856e9c3626a38c3789419c01e2573";
                        goto compare;
                      case 1391:
                        so=21;
                        resword = "af35ef475a041c13e986f316d7563615";
                        goto compare;
                      case 1395:
                        so=92;
                        resword = "4357a814f191d699fa8b3a02d8f3ecc7";
                        goto compare;
                      case 1401:
                        so=184;
                        resword = "f6bd212257be8711463a3888a572bd1c";
                        goto compare;
                      case 1402:
                        so=116;
                        resword = "34986c12f353c4707e9258afa4a43c4d";
                        goto compare;
                      case 1417:
                        so=69;
                        resword = "7e7bd09b4ad5be76e33e27eed6cb2c64";
                        goto compare;
                      case 1420:
                        so=23;
                        resword = "4d82a999592a218a18b923ebf99404c9";
                        goto compare;
                      case 1429:
                        so=305;
                        resword = "84411b1fb5cffdd6449c4eeb9b05f8d0";
                        goto compare;
                      case 1432:
                        so=262;
                        resword = "333a0763474e6754e37082a7e100b5c1";
                        goto compare;
                      case 1442:
                        so=39;
                        resword = "df00676b986ce312fe7077a6f7f895b8";
                        goto compare;
                      case 1446:
                        so=205;
                        resword = "75109c3ae6eeb31587b163195115dbbe";
                        goto compare;
                      case 1449:
                        so=130;
                        resword = "2cd023533cf6f0673c9e3bcb443bc436";
                        goto compare;
                      case 1459:
                        so=52;
                        resword = "67c5edb9a1f12dd1b78e0f82b63e30ca";
                        goto compare;
                      case 1460:
                        so=346;
                        resword = "9e14c5d24a5afcae86da7e8a6d21d764";
                        goto compare;
                      case 1461:
                        so=170;
                        resword = "e75df5a5d4b316ef7fdfa9fc69096293";
                        goto compare;
                      case 1467:
                        so=266;
                        resword = "5238fc0537697a3afdd612d15ecd93b1";
                        goto compare;
                      case 1476:
                        so=242;
                        resword = "8b9d82991a6973b1d4865ca97bc76b77";
                        goto compare;
                      case 1483:
                        so=254;
                        resword = "6610d939480c873baf6efaba30865640";
                        goto compare;
                      case 1495:
                        so=222;
                        resword = "4392ab8c20aedb68049101d5a280e052";
                        goto compare;
                      case 1501:
                        so=169;
                        resword = "6b2d18451c339c24d589898a97547e0c";
                        goto compare;
                      case 1510:
                        so=155;
                        resword = "ad036e694a99b095476da30b758aa70a";
                        goto compare;
                      case 1511:
                        so=168;
                        resword = "578c63cf117cf073edfa16e0d3d877b3";
                        goto compare;
                      case 1513:
                        so=33;
                        resword = "957b3c9d363cacb8808e652480c4edbb";
                        goto compare;
                      case 1514:
                        so=119;
                        resword = "25900ecd6f583c1b59996907e76e8727";
                        goto compare;
                      case 1517:
                        so=302;
                        resword = "abf3b490d93d30359e6ee6a45bf243b4";
                        goto compare;
                      case 1518:
                        so=103;
                        resword = "d66d2aa546940556afc630dc0f1ddef8";
                        goto compare;
                      case 1519:
                        so=89;
                        resword = "5e582ab9afe0787f4885952b90227810";
                        goto compare;
                      case 1524:
                        so=148;
                        resword = "92c87ad2e1ac9e98419781244e988d00";
                        goto compare;
                      case 1526:
                        so=323;
                        resword = "3215a99da44e9705ddb8776c1ac0d7c9";
                        goto compare;
                      case 1538:
                        so=74;
                        resword = "5e43911dfcfb283a9864a0e93babe4a4";
                        goto compare;
                      case 1540:
                        so=64;
                        resword = "9d2ad2f2ff8c204c9a625e600684a69a";
                        goto compare;
                      case 1543:
                        so=46;
                        resword = "9da3f6f991dc11f1960d8a54e51ea6d5";
                        goto compare;
                      case 1551:
                        so=179;
                        resword = "fd03d2e5b4b05905ac98690a94ac7b09";
                        goto compare;
                      case 1571:
                        so=236;
                        resword = "5d029cb5728e1b9b27711946740ac38b";
                        goto compare;
                      case 1581:
                        so=40;
                        resword = "d97be38af19f74965ca63c33e93b48e0";
                        goto compare;
                      case 1589:
                        so=112;
                        resword = "268253781e372568378e103486398093";
                        goto compare;
                      case 1594:
                        so=340;
                        resword = "a03c04d007451b030be3ebcb5094c611";
                        goto compare;
                      case 1606:
                        so=181;
                        resword = "58544a08938f9b1c27532f67b291a4b7";
                        goto compare;
                      case 1607:
                        so=328;
                        resword = "ad4076cc18c793eac32cbbcad6aed70f";
                        goto compare;
                      case 1609:
                        so=26;
                        resword = "d81889a8d3bbf8b12a87e1e4fcc8be9e";
                        goto compare;
                      case 1613:
                        so=272;
                        resword = "e3d40cd775cb07125643f87c8202ea2b";
                        goto compare;
                      case 1616:
                        so=8;
                        resword = "9496aff0d0aba0fb77fe1d3820c26863";
                        goto compare;
                      case 1617:
                        so=322;
                        resword = "43e05dc91adc06d37837694059866190";
                        goto compare;
                      case 1618:
                        so=90;
                        resword = "dcf44ab63ff169e4b8a9236f01d5f521";
                        goto compare;
                      case 1621:
                        so=154;
                        resword = "6bfb7cf86f29d99baa73ab2c78df711c";
                        goto compare;
                      case 1623:
                        so=224;
                        resword = "3fdbdd9354328a54ad68b2f6075aa83e";
                        goto compare;
                      case 1626:
                        so=295;
                        resword = "2342446861bd868a53f88df1d6d70b40";
                        goto compare;
                      case 1638:
                        so=232;
                        resword = "9e21f7a36fae4f8e313f08533d6bb74e";
                        goto compare;
                    }
                }
            }
          else
            {
              if (key < 5502)
                {
                  switch (key - 3751)
                    {
                      case 0:
                        so=32;
                        resword = "acad69a997725f6647dd6c99ced1adbf";
                        goto compare;
                      case 3:
                        so=220;
                        resword = "eab501bd6e6ee6b51e804ef0a0c65bcd";
                        goto compare;
                      case 10:
                        so=157;
                        resword = "4a982e13e7e391e1c8c47da905b4b4b5";
                        goto compare;
                      case 11:
                        so=12;
                        resword = "2ff3dc4b41d9e9a70667e22fad34677f";
                        goto compare;
                      case 16:
                        so=236;
                        resword = "7fd4bfaa247c0c43edd8df0864901a2f";
                        goto compare;
                      case 33:
                        so=38;
                        resword = "8d0a9cca8fb68e7fab1821ba5481322d";
                        goto compare;
                      case 35:
                        so=138;
                        resword = "ac93232974de599a0c6015fa5a583d7f";
                        goto compare;
                      case 39:
                        so=13;
                        resword = "295152d77d07f484061a59529699a357";
                        goto compare;
                      case 41:
                        so=82;
                        resword = "a41ab7c45efc6f1dc53b02ecb25bfa2a";
                        goto compare;
                      case 48:
                        so=159;
                        resword = "4ca8bd03cfcd4ab045f8a9ddeda10a6a";
                        goto compare;
                      case 53:
                        so=305;
                        resword = "4ff84278b1d8f90c55fa3990393a76aa";
                        goto compare;
                      case 61:
                        so=134;
                        resword = "2f53f5d2d4203cd50f07b8b5bb89a7a0";
                        goto compare;
                      case 65:
                        so=162;
                        resword = "7023f4eed5ae4386ed846860ad9d4c5b";
                        goto compare;
                      case 66:
                        so=354;
                        resword = "62e5f28d4b2b59e7f393534d3f9fbb88";
                        goto compare;
                      case 70:
                        so=319;
                        resword = "a6b7867a22379a51fc62c1dbaf1a4fd0";
                        goto compare;
                      case 73:
                        so=76;
                        resword = "eacb8016f2be278905fe66f3d946c337";
                        goto compare;
                      case 79:
                        so=273;
                        resword = "d418b81a409a00aef9dbcb4de4ae2f51";
                        goto compare;
                      case 93:
                        so=214;
                        resword = "e3231830e51e2e1569912700239f835a";
                        goto compare;
                      case 99:
                        so=328;
                        resword = "24219cdcdb2818eb4af569a502da43d0";
                        goto compare;
                      case 101:
                        so=44;
                        resword = "79ed940afc8e3105477552014948ea74";
                        goto compare;
                      case 116:
                        so=290;
                        resword = "7d9becfc17304bf586eb858fd2697aed";
                        goto compare;
                      case 119:
                        so=63;
                        resword = "a183ee2599222ce00f7734b3b3a8e037";
                        goto compare;
                      case 120:
                        so=186;
                        resword = "ade3975fa32362d1369fea1c580dd78d";
                        goto compare;
                      case 121:
                        so=162;
                        resword = "a1a3be1a485de77c32b09a1f261e4aff";
                        goto compare;
                      case 134:
                        so=65;
                        resword = "d4583f502600b4a7f1d3c189e647de40";
                        goto compare;
                      case 139:
                        so=2;
                        resword = "585b2be80312ac7dbcbed03512748955";
                        goto compare;
                      case 144:
                        so=20;
                        resword = "55054cd41e52b01bbc7d6d7dbf1a27d7";
                        goto compare;
                      case 147:
                        so=145;
                        resword = "4612e7205c2c4425d58ffc21d6debed5";
                        goto compare;
                      case 153:
                        so=117;
                        resword = "4a8865a8f0a253ec47d06ee5c77dadb0";
                        goto compare;
                      case 158:
                        so=258;
                        resword = "ece4a870640eaeaf3f8503621fa6aeb8";
                        goto compare;
                      case 171:
                        so=172;
                        resword = "27879d343f051168c8ef3e8f74fb2a6e";
                        goto compare;
                      case 172:
                        so=179;
                        resword = "9428de4f74275472fdbc95aa2811bf34";
                        goto compare;
                      case 175:
                        so=294;
                        resword = "7eca91e6965ec84a138a1de29b172155";
                        goto compare;
                      case 187:
                        so=5;
                        resword = "84286cf3bb68604dfaf3e18b867cd331";
                        goto compare;
                      case 188:
                        so=309;
                        resword = "efeb6d064e7b8dce325c6f737d779a11";
                        goto compare;
                      case 190:
                        so=210;
                        resword = "5e1794ae042c19387eb070105d5bd9e6";
                        goto compare;
                      case 191:
                        so=44;
                        resword = "48e86369eb2291a3384ee912a2a048bb";
                        goto compare;
                      case 194:
                        so=37;
                        resword = "633e3b194891062516a401911d0a085e";
                        goto compare;
                      case 195:
                        so=114;
                        resword = "44f5e46f0128c4c2fb66f9dac3c696a1";
                        goto compare;
                      case 202:
                        so=288;
                        resword = "f11d68239de45aa26f3dac3147c72933";
                        goto compare;
                      case 203:
                        so=19;
                        resword = "f07dec6f58cc174d526070703eddef02";
                        goto compare;
                      case 206:
                        so=336;
                        resword = "4acc38a6fd25ff0a8899ebbc801476d8";
                        goto compare;
                      case 207:
                        so=90;
                        resword = "513db4b45a18a8cd62fded26396b3cb0";
                        goto compare;
                      case 210:
                        so=321;
                        resword = "df0b6fac03ae08dd8ea62607eda1c7ac";
                        goto compare;
                      case 219:
                        so=32;
                        resword = "e1bc90f639158f8b205f992a34639235";
                        goto compare;
                      case 220:
                        so=210;
                        resword = "a8a07dc9356eba31948a85177ba4214b";
                        goto compare;
                      case 221:
                        so=272;
                        resword = "509defedfa068250f401866d902d2ee0";
                        goto compare;
                      case 227:
                        so=148;
                        resword = "aa05041d06f46e95f356f313cab00855";
                        goto compare;
                      case 233:
                        so=252;
                        resword = "e542311482ae65d8667c49bbb3edf84c";
                        goto compare;
                      case 234:
                        so=247;
                        resword = "657e06d44910c242241b4d14a66eb2ea";
                        goto compare;
                      case 241:
                        so=80;
                        resword = "e0b27fd278cb83179a3078b1d01cb6a6";
                        goto compare;
                      case 247:
                        so=12;
                        resword = "59f85564efc72b56a8a9f8438eb575b0";
                        goto compare;
                      case 249:
                        so=61;
                        resword = "a127a4e04e90d72b9869ef5ce3510b19";
                        goto compare;
                      case 250:
                        so=91;
                        resword = "a5a731cdd02bbb4828e248c59cdd8a58";
                        goto compare;
                      case 261:
                        so=337;
                        resword = "2fd2cf11b562c1de439eaf5971d6976f";
                        goto compare;
                      case 265:
                        so=269;
                        resword = "a29df5121b32515b9f001269abe80af0";
                        goto compare;
                      case 275:
                        so=348;
                        resword = "a5b35fe8522e71461bc57f84712a9a7f";
                        goto compare;
                      case 309:
                        so=283;
                        resword = "8e7879f508c34d92984f27c069ff12eb";
                        goto compare;
                      case 312:
                        so=326;
                        resword = "d7bc9a27450f5203c12117de4807c178";
                        goto compare;
                      case 316:
                        so=342;
                        resword = "2a40be6b9d1ab208d943dd1ff98c8fe2";
                        goto compare;
                      case 321:
                        so=114;
                        resword = "dc88cff55acdf045a55a140023a1f9c5";
                        goto compare;
                      case 322:
                        so=7;
                        resword = "adc5557952b4712fcef4601aa7283ad5";
                        goto compare;
                      case 328:
                        so=202;
                        resword = "2af77fe0848dcf4d39d034b52284e187";
                        goto compare;
                      case 331:
                        so=213;
                        resword = "7724eb194a661eabb69e6fc5aa9a5ab7";
                        goto compare;
                      case 341:
                        so=258;
                        resword = "aa96af5bb200f439ef8a125300c116a8";
                        goto compare;
                      case 371:
                        so=270;
                        resword = "5b0df46b12e96dd28ca5efc2a9b867a4";
                        goto compare;
                      case 377:
                        so=264;
                        resword = "a8bd51cdc4699b9268754e401ade7c1c";
                        goto compare;
                      case 384:
                        so=92;
                        resword = "570e16db4f331acc0f32db3173c8008f";
                        goto compare;
                      case 385:
                        so=65;
                        resword = "05621583e226c5d5c1296a16861f71ce";
                        goto compare;
                      case 388:
                        so=239;
                        resword = "05c08bda7ac86d67567e981ae465fddf";
                        goto compare;
                      case 389:
                        so=97;
                        resword = "87fefccb4ee4e1be043edd06e6e94b23";
                        goto compare;
                      case 391:
                        so=168;
                        resword = "d2ce8048b613e6ce17aa455380e2de1d";
                        goto compare;
                      case 392:
                        so=66;
                        resword = "3498956801e944e08d9d2f79912339c2";
                        goto compare;
                      case 396:
                        so=332;
                        resword = "e328588f02849217e8df88d421bd8d0e";
                        goto compare;
                      case 403:
                        so=92;
                        resword = "05822de81481168556adc1eddf3f5554";
                        goto compare;
                      case 410:
                        so=225;
                        resword = "d70167ccfc6f1eb1ed3d5e3bb81924b4";
                        goto compare;
                      case 425:
                        so=281;
                        resword = "4d612a2271b5f6d0d5868918b960b1e4";
                        goto compare;
                      case 430:
                        so=97;
                        resword = "497d1eee7f222b76dd3a42d216bbe787";
                        goto compare;
                      case 434:
                        so=24;
                        resword = "273b52e252b45d8f518c978ad75f51bf";
                        goto compare;
                      case 439:
                        so=212;
                        resword = "466d9d87f5c8c179ee793969d3e20db3";
                        goto compare;
                      case 450:
                        so=165;
                        resword = "069aa2d099e54b890ce2973a7130aef4";
                        goto compare;
                      case 453:
                        so=261;
                        resword = "071132657606a5af424439477a194826";
                        goto compare;
                      case 454:
                        so=266;
                        resword = "27b747daddb8f64d79cd14db7d9d08fd";
                        goto compare;
                      case 459:
                        so=182;
                        resword = "a1abdc8d0a4569e72dfcb081c66fc799";
                        goto compare;
                      case 461:
                        so=80;
                        resword = "7db20c8f9e32f764a5acd6f10255017d";
                        goto compare;
                      case 464:
                        so=163;
                        resword = "ae748558ec00048e5083114166d81264";
                        goto compare;
                      case 465:
                        so=106;
                        resword = "45357fc6671e79b01d86c6e3be6ba525";
                        goto compare;
                      case 476:
                        so=187;
                        resword = "a13a4d509cb3587edf437961bc183e92";
                        goto compare;
                      case 482:
                        so=354;
                        resword = "69ed0b0861ac1749e0fd284d226af36e";
                        goto compare;
                      case 484:
                        so=152;
                        resword = "42cc661505741dedf59b1d264ff58d67";
                        goto compare;
                      case 492:
                        so=62;
                        resword = "31d29acdaf6c39aa91c93a2f5419ea8b";
                        goto compare;
                      case 495:
                        so=152;
                        resword = "a9a56a8b01e676bea93d28cd4604aa34";
                        goto compare;
                      case 497:
                        so=151;
                        resword = "0a3729d95e66685dc39159387aba330b";
                        goto compare;
                      case 499:
                        so=219;
                        resword = "75f55050679fd67e7c26496a10b6dc03";
                        goto compare;
                      case 508:
                        so=13;
                        resword = "03b2ae42d7b0fd3e925810dcf67dc45c";
                        goto compare;
                      case 513:
                        so=96;
                        resword = "288aa82fc5bda38fd81a96a83361508d";
                        goto compare;
                      case 514:
                        so=111;
                        resword = "f0a37c6b21bf252ad00b8625f44d2d9c";
                        goto compare;
                      case 519:
                        so=287;
                        resword = "6866e9b2a12fb1d0035d2af3a5d464f2";
                        goto compare;
                      case 525:
                        so=133;
                        resword = "40922278f4428126fc795b47fb9ff9ad";
                        goto compare;
                      case 540:
                        so=264;
                        resword = "0f207ad10f10c4cb2a604d73651c2a50";
                        goto compare;
                      case 546:
                        so=240;
                        resword = "39ad1912b28ec9ff2cc6c6b867553a1e";
                        goto compare;
                      case 549:
                        so=359;
                        resword = "f88ef7396728ac69db6a483a95921369";
                        goto compare;
                      case 556:
                        so=201;
                        resword = "89ae1ea2aded96210eec0486edd09a9c";
                        goto compare;
                      case 557:
                        so=35;
                        resword = "f1045df4e2be11881b7d85d861ba7076";
                        goto compare;
                      case 558:
                        so=226;
                        resword = "7427a5d16ddcd968a5fd19b94b6b1fbf";
                        goto compare;
                      case 571:
                        so=92;
                        resword = "ec01cdb48d6be0f589aa90addc1eff5b";
                        goto compare;
                      case 573:
                        so=208;
                        resword = "8d3b27716a4e15b6c0584939b9c46088";
                        goto compare;
                      case 574:
                        so=47;
                        resword = "45d46649afacba5c9490ed86885e0f0c";
                        goto compare;
                      case 576:
                        so=323;
                        resword = "2cd7742aabf8d64d653ea4aa3163eacc";
                        goto compare;
                      case 578:
                        so=222;
                        resword = "07e137b3b016f83d170590054b283805";
                        goto compare;
                      case 580:
                        so=10;
                        resword = "9dac05e9e3e012d2f69f3bab28a18907";
                        goto compare;
                      case 581:
                        so=180;
                        resword = "7442e010463e62e1a44c4dc0289807ae";
                        goto compare;
                      case 600:
                        so=22;
                        resword = "a20da7e39f22ddeedfbe5a72a587497e";
                        goto compare;
                      case 603:
                        so=70;
                        resword = "02c76d9cd0ca85cd1b485b01e2469271";
                        goto compare;
                      case 605:
                        so=198;
                        resword = "fb14972e6ccbf42760a2c573067fd0f4";
                        goto compare;
                      case 634:
                        so=320;
                        resword = "f286b64eeb13a863b179e33f761e6732";
                        goto compare;
                      case 638:
                        so=305;
                        resword = "2c621230c750cd8fe65850eabf21e57e";
                        goto compare;
                      case 639:
                        so=210;
                        resword = "82562e518b7f174c5c7ea9218d19c150";
                        goto compare;
                      case 644:
                        so=291;
                        resword = "74defc405f96e05a0ce6ce72f6a1f9ea";
                        goto compare;
                      case 646:
                        so=188;
                        resword = "25b4058636aa9333129d51edac10e635";
                        goto compare;
                      case 650:
                        so=203;
                        resword = "6fbd4c25b1ee20396f6faf53f8ba8a99";
                        goto compare;
                      case 664:
                        so=297;
                        resword = "4d6c3f4222ca7e961bbadb32170febee";
                        goto compare;
                      case 668:
                        so=38;
                        resword = "fe8d477a4d48621a80579229174eafec";
                        goto compare;
                      case 675:
                        so=102;
                        resword = "e97c7c07559b3e607970e87e0f6f82b7";
                        goto compare;
                      case 684:
                        so=113;
                        resword = "e76299246f1473bcbf8a7c541febcda6";
                        goto compare;
                      case 688:
                        so=15;
                        resword = "295253712c2956fbe9966818d7ba62cf";
                        goto compare;
                      case 689:
                        so=166;
                        resword = "200327cf5cd3f8413b0e339be27f9476";
                        goto compare;
                      case 699:
                        so=186;
                        resword = "817ca35617737e99f3598a0cdad232d4";
                        goto compare;
                      case 715:
                        so=261;
                        resword = "02f596dd2d608bc7c8675eae4d324bc2";
                        goto compare;
                      case 718:
                        so=278;
                        resword = "f6ad4259714c1383819eff3e9eb37f3e";
                        goto compare;
                      case 723:
                        so=44;
                        resword = "23ec5e9aa7c4c12401150cbeb2e59000";
                        goto compare;
                      case 728:
                        so=251;
                        resword = "08b1ec2e4fa833987f34fa90c19c5c46";
                        goto compare;
                      case 731:
                        so=36;
                        resword = "53ee5a55c5b89165649e71f056be844a";
                        goto compare;
                      case 733:
                        so=341;
                        resword = "0c71201b68d120827f7ef406290a4346";
                        goto compare;
                      case 734:
                        so=127;
                        resword = "db78ec4b75508b178f0661ac12401f58";
                        goto compare;
                      case 739:
                        so=183;
                        resword = "f61e09f5e3c27e697e955bf6d8c125d7";
                        goto compare;
                      case 745:
                        so=49;
                        resword = "e19d26ff192a7087509e94d1fb4fbb05";
                        goto compare;
                      case 753:
                        so=274;
                        resword = "3c7d6c6bef6ca88dd2a490e4a39f4a40";
                        goto compare;
                      case 754:
                        so=118;
                        resword = "8bd2027dbc2f60fd32dea05d70cce13c";
                        goto compare;
                      case 759:
                        so=17;
                        resword = "8856e5fabad38cd7b6914cb9ba4f0b1e";
                        goto compare;
                      case 760:
                        so=70;
                        resword = "42287f75c59d6d666ee82f9d7eacc490";
                        goto compare;
                      case 761:
                        so=48;
                        resword = "52fee18c1c66fff1605ed4419adb3c18";
                        goto compare;
                      case 763:
                        so=221;
                        resword = "0c93e6bb6b681322d2d6dfbcfdb94e41";
                        goto compare;
                      case 770:
                        so=256;
                        resword = "2ad1cc1068f113eeedbea43af90b1400";
                        goto compare;
                      case 772:
                        so=22;
                        resword = "ee6c01baa5d379dddb5f1687ee054f57";
                        goto compare;
                      case 774:
                        so=320;
                        resword = "654676de75e399d1ba6e922bd610d641";
                        goto compare;
                      case 783:
                        so=336;
                        resword = "d40a20570affa73d8e826b2cc77b1b3c";
                        goto compare;
                      case 784:
                        so=84;
                        resword = "602e041ddc91ff6e2db2fd1ad2a25560";
                        goto compare;
                      case 796:
                        so=269;
                        resword = "d01b0e270fbf89139ab4dbe3ef400bdc";
                        goto compare;
                      case 811:
                        so=128;
                        resword = "346aa759444f2578d6929db3fac31263";
                        goto compare;
                      case 819:
                        so=124;
                        resword = "319b61f1827c4d0ec2efa6df8322102d";
                        goto compare;
                      case 832:
                        so=165;
                        resword = "d4bc64cfbc8bf2d6ff23962b58b5e486";
                        goto compare;
                      case 833:
                        so=106;
                        resword = "3ea7514482cec4d419847a7c31665480";
                        goto compare;
                      case 846:
                        so=17;
                        resword = "e5ed47848449f723f4b2f6a6975f8f05";
                        goto compare;
                      case 852:
                        so=101;
                        resword = "905865bc4cee3cb202864fc0ba4a674d";
                        goto compare;
                      case 856:
                        so=252;
                        resword = "ef1103d6a89f17f32489d997dd5c4efd";
                        goto compare;
                      case 858:
                        so=216;
                        resword = "6d4253bbeefc712f8e86d98a68c4ff7c";
                        goto compare;
                      case 866:
                        so=236;
                        resword = "eded2ef61956f25e29b9d999c3c2f1ec";
                        goto compare;
                      case 910:
                        so=150;
                        resword = "0f577f732e4700d6198b29f7da9dc2c8";
                        goto compare;
                      case 911:
                        so=233;
                        resword = "a51a600174fb405fe2641e70be4996e0";
                        goto compare;
                      case 921:
                        so=303;
                        resword = "50ada9d8193b7e83d02888fb0b4f4297";
                        goto compare;
                      case 926:
                        so=123;
                        resword = "3ddb432a1f54ad63f16c89dda0920b39";
                        goto compare;
                      case 931:
                        so=0;
                        resword = "fe210e54d03910f7bc5539d9e5fa6131";
                        goto compare;
                      case 932:
                        so=300;
                        resword = "02fa8dc153162f3960d83f65f6217f52";
                        goto compare;
                      case 934:
                        so=265;
                        resword = "34c82836e27c60e11567fdeccba4cfa0";
                        goto compare;
                      case 937:
                        so=173;
                        resword = "497aecb9a85b65e38f17d41794ec02ca";
                        goto compare;
                      case 944:
                        so=279;
                        resword = "24458a5e02ba7d50d0dcb44e8c30c963";
                        goto compare;
                      case 946:
                        so=225;
                        resword = "f2f65b56eb0edd83f0a3b88c52dc865a";
                        goto compare;
                      case 964:
                        so=114;
                        resword = "330ee9f4f289d33897efa219d8bdf49f";
                        goto compare;
                      case 966:
                        so=327;
                        resword = "f793e00c6dec8e34b48895e9ec684a58";
                        goto compare;
                      case 968:
                        so=137;
                        resword = "936e3c58dd0601bfec3b1628f5931a47";
                        goto compare;
                      case 970:
                        so=348;
                        resword = "0f155d143489e52f3e2d4153e4de88b3";
                        goto compare;
                      case 974:
                        so=194;
                        resword = "334e427659852ae43b9a14cbc2ce3f38";
                        goto compare;
                      case 979:
                        so=95;
                        resword = "725e3fba8977b929db318680102686a4";
                        goto compare;
                      case 995:
                        so=248;
                        resword = "ddc41206244ec5987e8ac7a258c47565";
                        goto compare;
                      case 997:
                        so=36;
                        resword = "462d6b29564df1448bb6f5278d1c21c0";
                        goto compare;
                      case 998:
                        so=110;
                        resword = "0791a8d91db6cd80d3e6823e4c0d3491";
                        goto compare;
                      case 1012:
                        so=109;
                        resword = "42ca55880f9e15808fff69c059a5620c";
                        goto compare;
                      case 1015:
                        so=38;
                        resword = "a988ad640a412942e51e10c802fdcda7";
                        goto compare;
                      case 1019:
                        so=28;
                        resword = "9d7368610e8609e2b4a009df51b9ecbc";
                        goto compare;
                      case 1020:
                        so=315;
                        resword = "d8768a8e235c0d08af663087bfde4650";
                        goto compare;
                      case 1047:
                        so=75;
                        resword = "e748d8b85de2a3bf80f24f2ca486a96d";
                        goto compare;
                      case 1050:
                        so=279;
                        resword = "843cd0d159ee9f1df2a7a976abd13a09";
                        goto compare;
                      case 1053:
                        so=56;
                        resword = "04833b03df7a2ab4d889a99a7c9cf8be";
                        goto compare;
                      case 1055:
                        so=77;
                        resword = "a72d971ca181feea8686635058c04d66";
                        goto compare;
                      case 1066:
                        so=296;
                        resword = "255b8777f6fa238565fb0fef344db463";
                        goto compare;
                      case 1075:
                        so=53;
                        resword = "00caa21b2dd9b74515828cc75d5ece5f";
                        goto compare;
                      case 1080:
                        so=288;
                        resword = "7f8402e91b7b4b06a34e56ff0b6d15f6";
                        goto compare;
                      case 1084:
                        so=72;
                        resword = "20f2923d7337ba40da1bf37989d53dd0";
                        goto compare;
                      case 1088:
                        so=41;
                        resword = "7e78e65ba355564ce402c980253e09c2";
                        goto compare;
                      case 1104:
                        so=110;
                        resword = "207b99773e312f0634f219caab24909f";
                        goto compare;
                      case 1108:
                        so=186;
                        resword = "8e93a2ee9bbeb1f48a33534196db5e48";
                        goto compare;
                      case 1109:
                        so=180;
                        resword = "f33da081080205e4b90d1964cd763e6f";
                        goto compare;
                      case 1113:
                        so=209;
                        resword = "edf7064062cceb334fe0921266dceb54";
                        goto compare;
                      case 1122:
                        so=202;
                        resword = "5d5b483591fcb3dce192657a3f7061c8";
                        goto compare;
                      case 1129:
                        so=160;
                        resword = "741e279d27a9aaecd7f0ef2ea926a80b";
                        goto compare;
                      case 1151:
                        so=273;
                        resword = "9b2d533329cecbd913509808818b4cc2";
                        goto compare;
                      case 1152:
                        so=60;
                        resword = "ac062b37a59df2d0f7010092f88c3263";
                        goto compare;
                      case 1176:
                        so=144;
                        resword = "41528943593c30c42739bfb7e0d12ea4";
                        goto compare;
                      case 1189:
                        so=253;
                        resword = "2596d7d62e7825621df9151d93d80737";
                        goto compare;
                      case 1191:
                        so=349;
                        resword = "e49684edc0d2b90cad9ccf42c5513c0b";
                        goto compare;
                      case 1195:
                        so=300;
                        resword = "64cc687b288e94dfa29659451405c012";
                        goto compare;
                      case 1204:
                        so=215;
                        resword = "26614bd588a3d5498ab198130498658c";
                        goto compare;
                      case 1245:
                        so=82;
                        resword = "9938b7519e4f6840576e832d1dc82e5e";
                        goto compare;
                      case 1247:
                        so=58;
                        resword = "027c732f6b99716836098292fc061d44";
                        goto compare;
                      case 1261:
                        so=357;
                        resword = "2082a03a9b43a3c96c37cdb3a8891941";
                        goto compare;
                      case 1264:
                        so=147;
                        resword = "2c426924cf381984f42e1538ff9170eb";
                        goto compare;
                      case 1297:
                        so=82;
                        resword = "003a09bc170d0fcb3c789b48da8eddc6";
                        goto compare;
                      case 1310:
                        so=344;
                        resword = "86f8eaf9f5cf6a6e53b1b61d623ee82a";
                        goto compare;
                      case 1312:
                        so=6;
                        resword = "ed58f0b0641360ae40cafef835ff85e4";
                        goto compare;
                      case 1315:
                        so=164;
                        resword = "a6ed3a3920fa2eeafbed37b2dd33a167";
                        goto compare;
                      case 1326:
                        so=2;
                        resword = "e5e4d7e9de5630ecbafb969a82d57040";
                        goto compare;
                      case 1329:
                        so=23;
                        resword = "6b4e02e5fb192bf208cd84ad78807219";
                        goto compare;
                      case 1342:
                        so=169;
                        resword = "63f95f1bbd841ad83185652ba7ad2e49";
                        goto compare;
                      case 1343:
                        so=73;
                        resword = "d14844c6656235a989ec02b77ec58cf1";
                        goto compare;
                      case 1344:
                        so=230;
                        resword = "56ae48e1c1b4f96083c72106e433e964";
                        goto compare;
                      case 1345:
                        so=328;
                        resword = "486d3858ad089339a711f909d08d692d";
                        goto compare;
                      case 1346:
                        so=239;
                        resword = "3a88abf995db309c60726b90c37a3fa0";
                        goto compare;
                      case 1350:
                        so=177;
                        resword = "8d843577d08efcbf6b6ee01229529657";
                        goto compare;
                      case 1356:
                        so=270;
                        resword = "3a4678c97bcf7ce311e94cdf33926089";
                        goto compare;
                      case 1360:
                        so=43;
                        resword = "af82486aa121ebbdb3c3e7e0bcd728e7";
                        goto compare;
                      case 1364:
                        so=18;
                        resword = "f8f5cdb0c75bb034b0faec3f29adcc21";
                        goto compare;
                      case 1376:
                        so=308;
                        resword = "2fc1e51f9a755c11882381482f1311d9";
                        goto compare;
                      case 1390:
                        so=25;
                        resword = "4c86c2fb63eb7b9fda2cde13fbbfc941";
                        goto compare;
                      case 1412:
                        so=315;
                        resword = "e174bf7067e9896df1438ddf21a8d236";
                        goto compare;
                      case 1424:
                        so=81;
                        resword = "2c23ff8716cbaa1a246d09acf0e02d8a";
                        goto compare;
                      case 1443:
                        so=351;
                        resword = "e6024ef1a96fc973e9410a9a0f357a32";
                        goto compare;
                      case 1444:
                        so=278;
                        resword = "f517b290f8ffa359a972254ed30155b4";
                        goto compare;
                      case 1446:
                        so=273;
                        resword = "2f86baf7c692ed235ea5a7e9a770f0cd";
                        goto compare;
                      case 1452:
                        so=298;
                        resword = "78c96e0ad09925884243979e71791598";
                        goto compare;
                      case 1454:
                        so=190;
                        resword = "6e988bea2927a79ff554d0a9ed857f26";
                        goto compare;
                      case 1457:
                        so=37;
                        resword = "9589b17f3617eee44fb5b2aa43de0910";
                        goto compare;
                      case 1464:
                        so=71;
                        resword = "7913b1f0646fdb8eace7eeca08d17271";
                        goto compare;
                      case 1465:
                        so=234;
                        resword = "0216b82417d6e488ce05da8cc4e1bad9";
                        goto compare;
                      case 1468:
                        so=303;
                        resword = "20416c5efa60a8c3e40868cfde3dab02";
                        goto compare;
                      case 1474:
                        so=42;
                        resword = "8367be7da95fbce3a0641cb60dc81d46";
                        goto compare;
                      case 1478:
                        so=30;
                        resword = "08861086ad6850800acfb4b25bcea789";
                        goto compare;
                      case 1479:
                        so=13;
                        resword = "57093ab9fa93a74ac4701cbd084e46dd";
                        goto compare;
                      case 1480:
                        so=135;
                        resword = "a6114b102b2d647db1d0088c4f183c5a";
                        goto compare;
                      case 1484:
                        so=80;
                        resword = "313bb718afdc296f63b5a0b8c487fb68";
                        goto compare;
                      case 1486:
                        so=241;
                        resword = "fd68d78a5f0c9f1ec930a8cdb2031ed8";
                        goto compare;
                      case 1490:
                        so=161;
                        resword = "4fe72de331a38f29bc2a2458e4804453";
                        goto compare;
                      case 1496:
                        so=145;
                        resword = "5e2b4eeee5a4ff59b158813a3e9afda0";
                        goto compare;
                      case 1499:
                        so=61;
                        resword = "41a126e4064ec51d29262e54a0a0ecab";
                        goto compare;
                      case 1503:
                        so=280;
                        resword = "009b409dba18937c59a888e0f925242c";
                        goto compare;
                      case 1509:
                        so=166;
                        resword = "230d295c30a720861a53573b01b1de37";
                        goto compare;
                      case 1521:
                        so=19;
                        resword = "df597163ade8855f069ec101b2c71780";
                        goto compare;
                      case 1526:
                        so=322;
                        resword = "ed759e9df07ab0b6ae3977bfeb50477f";
                        goto compare;
                      case 1527:
                        so=58;
                        resword = "f469165ee9c94baa3c437618fe302478";
                        goto compare;
                      case 1533:
                        so=66;
                        resword = "da49852e9f3d346529a3fc2ba45db7f6";
                        goto compare;
                      case 1534:
                        so=324;
                        resword = "2c2bacf37da7942582158de1454323db";
                        goto compare;
                      case 1535:
                        so=325;
                        resword = "5438bd93ef0f4f263465c36356d20bc1";
                        goto compare;
                      case 1552:
                        so=307;
                        resword = "23cc08ec18200585e8d8342a637f47d6";
                        goto compare;
                      case 1553:
                        so=36;
                        resword = "2111fdb91255557545f87e5f1ad99e0c";
                        goto compare;
                      case 1561:
                        so=149;
                        resword = "dc8ba5cde36b7140b99289c0d8358b9d";
                        goto compare;
                      case 1566:
                        so=59;
                        resword = "40e5c4e86bbc0abee63e8d0adb32078b";
                        goto compare;
                      case 1569:
                        so=81;
                        resword = "0cdc1c9d1acdf9439141717a36a44e32";
                        goto compare;
                      case 1574:
                        so=359;
                        resword = "23020e66bdc819aaa6dc914d4f8bbb83";
                        goto compare;
                      case 1579:
                        so=332;
                        resword = "2416a8c5972259b234ef5cee90952f5e";
                        goto compare;
                      case 1583:
                        so=125;
                        resword = "dd9dcfc1a9ae70ab33238464554e879d";
                        goto compare;
                      case 1588:
                        so=226;
                        resword = "302c533998eac5c3bf5bd22e5d91606a";
                        goto compare;
                      case 1593:
                        so=33;
                        resword = "31f3fc77753fc2355a1c7e0d2c5ae902";
                        goto compare;
                      case 1594:
                        so=358;
                        resword = "380d9f7e5c2fda6a06dcd3f075db9077";
                        goto compare;
                      case 1612:
                        so=268;
                        resword = "82296fd90815f83d11d6562625b18ef9";
                        goto compare;
                      case 1618:
                        so=233;
                        resword = "dd9d138bb3259acaa595002706614db4";
                        goto compare;
                      case 1619:
                        so=112;
                        resword = "2336412c3cc23fba7a5f9baaa185a51d";
                        goto compare;
                      case 1622:
                        so=304;
                        resword = "078cd49934524846396ea48de483abb6";
                        goto compare;
                      case 1631:
                        so=278;
                        resword = "f1e8bf86aed8610ca920d921160b7425";
                        goto compare;
                      case 1632:
                        so=194;
                        resword = "27dc4e9501f1ce00e111e58ff99eb136";
                        goto compare;
                      case 1641:
                        so=49;
                        resword = "2ef7002bbda1182935b9ef49be3d4538";
                        goto compare;
                      case 1643:
                        so=41;
                        resword = "a3cb6b42f95a87beb202c4f1319e051b";
                        goto compare;
                      case 1646:
                        so=199;
                        resword = "9c0e14d7e32cc47854377f66b9e33609";
                        goto compare;
                      case 1650:
                        so=182;
                        resword = "eeb185f62b0bda796f83de04a3e409ac";
                        goto compare;
                      case 1655:
                        so=287;
                        resword = "45b2655ff22be889aa656eec94c83987";
                        goto compare;
                      case 1671:
                        so=237;
                        resword = "61a82841851294a3f22af35f2fd0fa2b";
                        goto compare;
                      case 1676:
                        so=147;
                        resword = "ed936a826d2eabefd9512c89650ca7d3";
                        goto compare;
                      case 1677:
                        so=171;
                        resword = "6429caf70773ae860b437fb111048910";
                        goto compare;
                      case 1681:
                        so=205;
                        resword = "20aa4a2b0b14b6c585887be7d33ac12a";
                        goto compare;
                      case 1682:
                        so=36;
                        resword = "79d9d438bdf43b48355d3b06d2faeeec";
                        goto compare;
                      case 1686:
                        so=39;
                        resword = "2b8459dd8c2670d305fb6197dff771d1";
                        goto compare;
                      case 1715:
                        so=213;
                        resword = "51bef6e318541b9cc5710e9c968108f7";
                        goto compare;
                      case 1717:
                        so=17;
                        resword = "da8e779fdcdc61eec4ad04b0cb7b3a29";
                        goto compare;
                      case 1718:
                        so=342;
                        resword = "5aaeb6a6c0cc7d8e2280e43341f01500";
                        goto compare;
                      case 1724:
                        so=146;
                        resword = "220211de10256828ad28cbdcf5da971f";
                        goto compare;
                      case 1725:
                        so=3;
                        resword = "a29d0f5bf61ec610158db9087882c3c5";
                        goto compare;
                      case 1739:
                        so=311;
                        resword = "240b553a4b892f3c82f1d4803700feb7";
                        goto compare;
                      case 1747:
                        so=29;
                        resword = "3b98cae8efc18ca1f11127145f5d3489";
                        goto compare;
                      case 1749:
                        so=5;
                        resword = "2806ee421af2a8dad4cd24abccf22b1c";
                        goto compare;
                    }
                }
              else
                {
                  if (key < 8105)
                    {
                      switch (key - 5502)
                        {
                          case 0:
                            so=5;
                        resword = "6e3e0a3e9eb564da598c5c3b0ed766f9";
                            goto compare;
                          case 4:
                            so=243;
                        resword = "0c21e26deb5da2448a3e94250479baa4";
                            goto compare;
                          case 6:
                            so=45;
                        resword = "83392887ee8111987641c904116abe87";
                            goto compare;
                          case 12:
                            so=59;
                        resword = "49eee104b70076c44afa8bcee016549e";
                            goto compare;
                          case 21:
                            so=187;
                        resword = "9889da96b8c31ecb7800e9274549d058";
                            goto compare;
                          case 22:
                            so=89;
                        resword = "47ee19ec1e0180b84a020ba1a239260f";
                            goto compare;
                          case 23:
                            so=49;
                        resword = "41657f0916bba09b3b31eb316833e17c";
                            goto compare;
                          case 24:
                            so=244;
                        resword = "2eaae026686d385794caf38f8d97746a";
                            goto compare;
                          case 25:
                            so=35;
                        resword = "73fd7e226abfc65065fef56379662c1f";
                            goto compare;
                          case 35:
                            so=16;
                        resword = "a19636056033811e6895762930148bab";
                            goto compare;
                          case 43:
                            so=93;
                        resword = "5759c06c202d654a951c6a0aa10831ca";
                            goto compare;
                          case 53:
                            so=91;
                        resword = "94e991adb4fd6dec05520a35c27e6502";
                            goto compare;
                          case 60:
                            so=331;
                        resword = "374e84c903e2db1f6c1199af0d0e38e8";
                            goto compare;
                          case 61:
                            so=65;
                        resword = "ae279a8d0c68aa31a5d23dad652cac08";
                            goto compare;
                          case 80:
                            so=78;
                        resword = "e00d288492a53c96a691c7eba0fd6978";
                            goto compare;
                          case 117:
                            so=322;
                        resword = "206b14795f2a6044e2347668fa8a4059";
                            goto compare;
                          case 133:
                            so=23;
                        resword = "9ceec11eaa385076aba348f5dcfb9a75";
                            goto compare;
                          case 134:
                            so=167;
                        resword = "0e8002c946244bd95adc2c5a26c2e21f";
                            goto compare;
                          case 139:
                            so=297;
                        resword = "4fbe32ff0cb61ba229fd4d03a591065d";
                            goto compare;
                          case 146:
                            so=307;
                        resword = "74992f9c2dc3363249223e84e0712fdd";
                            goto compare;
                          case 151:
                            so=294;
                        resword = "451ca60db21ac690bd27e6219359e0f5";
                            goto compare;
                          case 153:
                            so=164;
                        resword = "e58640b84c9f2b100c58ed1a600abd55";
                            goto compare;
                          case 154:
                            so=310;
                        resword = "0e22bda9dff179db075c83ae26d006ef";
                            goto compare;
                          case 156:
                            so=69;
                        resword = "c3a3495646e85d9a467a9bd5c210fac1";
                            goto compare;
                          case 166:
                            so=350;
                        resword = "c273dbaa97baac7756a47fd60cb97867";
                            goto compare;
                          case 167:
                            so=156;
                        resword = "0cad31bee7f7b6f40cceba8a8a1718a2";
                            goto compare;
                          case 170:
                            so=122;
                        resword = "8d1e4f68b974f7fccc5ad8b17a6f4587";
                            goto compare;
                          case 179:
                            so=300;
                        resword = "2378cd03aef5b48395c02e285cdf0688";
                            goto compare;
                          case 186:
                            so=289;
                        resword = "0e31b6049ad1f537c8eef158251ea71f";
                            goto compare;
                          case 196:
                            so=162;
                        resword = "c3136b9b404a6ed2018f81246f91e61b";
                            goto compare;
                          case 198:
                            so=224;
                        resword = "3a09ae986e0873ee446068355563231d";
                            goto compare;
                          case 202:
                            so=139;
                        resword = "9d3cfd2af05ffe9e06abaa0e32017830";
                            goto compare;
                          case 203:
                            so=231;
                        resword = "536ef311d38040a6a2bc556843dd1d22";
                            goto compare;
                          case 210:
                            so=48;
                        resword = "5454721e386bafb3bfd69ec8c87bf81e";
                            goto compare;
                          case 211:
                            so=174;
                        resword = "6069858435a80205067f2325c47136f9";
                            goto compare;
                          case 221:
                            so=290;
                        resword = "95e87572014f968e69dca43ab6b25f44";
                            goto compare;
                          case 224:
                            so=115;
                        resword = "0acd4d8b5d6609c419451afd1e30173e";
                            goto compare;
                          case 228:
                            so=130;
                        resword = "36b9237a69b0042ec6eb23dcbfd471d9";
                            goto compare;
                          case 231:
                            so=58;
                        resword = "cc7241545f2493f406e43872cdb1db7a";
                            goto compare;
                          case 241:
                            so=54;
                        resword = "a3aca8e8eaaf7b4b4b0d60383d046eaf";
                            goto compare;
                          case 245:
                            so=215;
                        resword = "a928b2e49bae2bc60b6b7976ee6f1d58";
                            goto compare;
                          case 246:
                            so=283;
                        resword = "3cd9309adaba8df31de0b67d61361c7c";
                            goto compare;
                          case 252:
                            so=361;
                        resword = "0250e364feab76932d19bacd6e260921";
                            goto compare;
                          case 253:
                            so=351;
                        resword = "23903f1aed4bfecbd77af46e94258ae5";
                            goto compare;
                          case 264:
                            so=265;
                        resword = "8e9dd8a0237b9e9b677de5c846f7134e";
                            goto compare;
                          case 268:
                            so=292;
                        resword = "a175d39efd7e25b14bfd7a3780cfbca8";
                            goto compare;
                          case 281:
                            so=275;
                        resword = "32499fe76040560f0839767643afc289";
                            goto compare;
                          case 282:
                            so=176;
                        resword = "21a33eb21b03fff1d8494d4c312d0a5c";
                            goto compare;
                          case 298:
                            so=150;
                        resword = "77bb9c04383e42b3b60a2b2a92de8d31";
                            goto compare;
                          case 300:
                            so=290;
                        resword = "d51993b8f16102d16e3a1036919ea2ed";
                            goto compare;
                          case 315:
                            so=138;
                        resword = "cabac006f4854bdf4f6883223f4522de";
                            goto compare;
                          case 320:
                            so=327;
                        resword = "269d474b6547ae566d1bdcada778a5ae";
                            goto compare;
                          case 336:
                            so=234;
                        resword = "ccf3bba6b6f84df99f2716cea5f3c300";
                            goto compare;
                          case 339:
                            so=192;
                        resword = "056a86bf3a0b637e5bfcb7342f300741";
                            goto compare;
                          case 340:
                            so=321;
                        resword = "2df411e697a9183b2f66cac16f6bf68d";
                            goto compare;
                          case 341:
                            so=229;
                        resword = "47c77281c14fbeb6e2ffb710cdcef371";
                            goto compare;
                          case 353:
                            so=126;
                        resword = "ec4df72966544f41bbb04f5c4517aa66";
                            goto compare;
                          case 358:
                            so=286;
                        resword = "04eae078831c63b1c115a24ec475a616";
                            goto compare;
                          case 360:
                            so=291;
                        resword = "4fcc871edc1e94ce8ca188acc63db620";
                            goto compare;
                          case 365:
                            so=89;
                        resword = "87deb45c7cae094ec6034d5c84f7c2c6";
                            goto compare;
                          case 370:
                            so=300;
                        resword = "cc93867b64bd2951c6b9a24d5ef59e90";
                            goto compare;
                          case 377:
                            so=224;
                        resword = "048d58b8465475b4413490a333235155";
                            goto compare;
                          case 383:
                            so=156;
                        resword = "f36ef1d379eb276477e7e57779309122";
                            goto compare;
                          case 387:
                            so=87;
                        resword = "a64e840d48d3f26f3667d90bd889d0f5";
                            goto compare;
                          case 390:
                            so=332;
                        resword = "d09e24a8c483744987ce68836c9ef1f3";
                            goto compare;
                          case 392:
                            so=276;
                        resword = "9d247ae17e0eb35bffc610635988e7bf";
                            goto compare;
                          case 394:
                            so=250;
                        resword = "ad8bde4a5ecbc45425a291c50adbd557";
                            goto compare;
                          case 403:
                            so=105;
                        resword = "e9a247481fdffbe0f1735d1c94d476fe";
                            goto compare;
                          case 412:
                            so=284;
                        resword = "08910ea02d3e0732461992ba4ffcc51a";
                            goto compare;
                          case 422:
                            so=248;
                        resword = "f16eb48ba743bd92786b0d7a05cefa61";
                            goto compare;
                          case 433:
                            so=55;
                        resword = "3b4b65e766ffbd3073de7c56bcad90e8";
                            goto compare;
                          case 438:
                            so=287;
                        resword = "e76d494b45586e9fbe3a3ee9ea42074a";
                            goto compare;
                          case 439:
                            so=222;
                        resword = "a5941f1fcc32e2d7b50ef2cb58aa2a6b";
                            goto compare;
                          case 441:
                            so=262;
                        resword = "3848c996b1ab4021ffb5af2ede78cf88";
                            goto compare;
                          case 445:
                            so=293;
                        resword = "0a382913e2f46dc84cdcffd0ae90f1b6";
                            goto compare;
                          case 455:
                            so=55;
                        resword = "ad3cc18ecedd086188226f075872eb4a";
                            goto compare;
                          case 473:
                            so=175;
                        resword = "e7c5b203631fa23d8e239e374d685f98";
                            goto compare;
                          case 499:
                            so=285;
                        resword = "da1975b3ba17370eee3dda47c00736fe";
                            goto compare;
                          case 503:
                            so=298;
                        resword = "82ee20edb08e527697613c9850c3f015";
                            goto compare;
                          case 522:
                            so=254;
                        resword = "6d3c6b82269f6b4e7daf74420f7036ea";
                            goto compare;
                          case 536:
                            so=87;
                        resword = "c6f78437b340922d3a5da92b544882cf";
                            goto compare;
                          case 541:
                            so=337;
                        resword = "c3c2487e4a721d34351fa35cbc83fa66";
                            goto compare;
                          case 546:
                            so=144;
                        resword = "3559f215a48512b9160d1dffb5f2f675";
                            goto compare;
                          case 556:
                            so=189;
                        resword = "c4e3b9d33de605f61bdee1f3c1c4d8d9";
                            goto compare;
                          case 570:
                            so=338;
                        resword = "ef106fa1cd5f99cefb40cc0a8c402594";
                            goto compare;
                          case 578:
                            so=151;
                        resword = "d0294158ee522a11358218ecb0fc8eae";
                            goto compare;
                          case 584:
                            so=301;
                        resword = "f2f866cf8cef359e898f1443ca75a12f";
                            goto compare;
                          case 587:
                            so=249;
                        resword = "0c521050b2db989f74e8325d4f8c1770";
                            goto compare;
                          case 591:
                            so=255;
                        resword = "4678bc14234c8597edd5480adfb06fcb";
                            goto compare;
                          case 593:
                            so=77;
                        resword = "2be6b700b577361e3f5ed81fd4d3e720";
                            goto compare;
                          case 603:
                            so=245;
                        resword = "0a8cf0b0e9da3dbc8f120fae1c403f4d";
                            goto compare;
                          case 605:
                            so=308;
                        resword = "31ac6b76cfec9db38b5a22493a2e4c4a";
                            goto compare;
                          case 610:
                            so=142;
                        resword = "7809c13b0fb1c32ee9239f16809f674b";
                            goto compare;
                          case 633:
                            so=192;
                        resword = "c40a583cf478f02c9e8581a4f9276563";
                            goto compare;
                          case 649:
                            so=141;
                        resword = "2ce8c66c0a12db9fd874564e64249d5e";
                            goto compare;
                          case 670:
                            so=316;
                        resword = "e01620c1523f0f60ca0dc84630be20da";
                            goto compare;
                          case 676:
                            so=266;
                        resword = "c2856ffa6df8231d31c8071fada1355e";
                            goto compare;
                          case 683:
                            so=122;
                        resword = "61dc37c85a2fc3be6666e11fc753324b";
                            goto compare;
                          case 688:
                            so=98;
                        resword = "34b9a00e788d9d532e05dbc206e95f06";
                            goto compare;
                          case 691:
                            so=217;
                        resword = "0a30ab7807ecb208d49f29f849f82e47";
                            goto compare;
                          case 693:
                            so=189;
                        resword = "f8ffc792fea86769cf07431b2178f950";
                            goto compare;
                          case 694:
                            so=355;
                        resword = "a01250d089ebe7f9a6721ea89562c8e2";
                            goto compare;
                          case 696:
                            so=1;
                        resword = "e948df98759fd62fc7b82a3903635cc7";
                            goto compare;
                          case 708:
                            so=73;
                        resword = "5dfeb2d6ea927c5f7df5ac4abbf02d58";
                            goto compare;
                          case 711:
                            so=228;
                        resword = "f470ddf88f1f6628ba256a54ab69ef1e";
                            goto compare;
                          case 722:
                            so=303;
                        resword = "860e5cdb3eece0126c118fec34a5b782";
                            goto compare;
                          case 723:
                            so=158;
                        resword = "04f84c2cc2f603f13a2667f50a1a4db5";
                            goto compare;
                          case 736:
                            so=207;
                        resword = "4142b474b88f1c935ca39ec3756fd770";
                            goto compare;
                          case 741:
                            so=95;
                        resword = "f1de98c2fe7a04efec2f010f9e1d9698";
                            goto compare;
                          case 751:
                            so=109;
                        resword = "e9c9632cbcfa47192cb86d3fabe30388";
                            goto compare;
                          case 753:
                            so=56;
                        resword = "2dfb83bec4054158794621e895337535";
                            goto compare;
                          case 788:
                            so=171;
                        resword = "63df5b506e9463f6ce465fa4e696b885";
                            goto compare;
                          case 789:
                            so=50;
                        resword = "a37e66e3c671e9dd63979accea90c84c";
                            goto compare;
                          case 797:
                            so=67;
                        resword = "4bd7d690a0af00ac9a5ad38ee36a1ac4";
                            goto compare;
                          case 798:
                            so=330;
                        resword = "88ce9214815e4e40d7a060c99ba6689f";
                            goto compare;
                          case 811:
                            so=126;
                        resword = "c72b300c1e5996592ff85a060bf0563b";
                            goto compare;
                          case 822:
                            so=229;
                        resword = "04f7272670cbef6b1e93804ecd284ec9";
                            goto compare;
                          case 836:
                            so=134;
                        resword = "057c12bcc115a5b181fbdfa3885f6628";
                            goto compare;
                          case 843:
                            so=125;
                        resword = "c69378ff9b78cc2f6bfe0953a5a2550c";
                            goto compare;
                          case 873:
                            so=155;
                        resword = "328e4f284aee07eb2a21b82aeb5e7365";
                            goto compare;
                          case 881:
                            so=16;
                        resword = "e7d9476f98e844733b6d5de3e8c8b0c1";
                            goto compare;
                          case 901:
                            so=13;
                        resword = "c6f7a11e9ba2c3579cb807f215d106e6";
                            goto compare;
                          case 915:
                            so=216;
                        resword = "2d6647120bc4dfaccf1d448c259662ec";
                            goto compare;
                          case 916:
                            so=135;
                        resword = "fccfbd5ca871ba389769ba0716fb28f4";
                            goto compare;
                          case 921:
                            so=311;
                        resword = "c05250ec06e417eb40a517301eb411b8";
                            goto compare;
                          case 924:
                            so=75;
                        resword = "acb35fe1ec8c7f21b9e7dab656eaa82f";
                            goto compare;
                          case 938:
                            so=196;
                        resword = "260af15059ff12b2261536c8fca90e5e";
                            goto compare;
                          case 951:
                            so=143;
                        resword = "7ba932775af85883546831912c8540fc";
                            goto compare;
                          case 953:
                            so=69;
                        resword = "2de13452b15a3f3784a6b645cef434fd";
                            goto compare;
                          case 972:
                            so=9;
                        resword = "4333649b9f4feeb8a857e2417088f31a";
                            goto compare;
                          case 974:
                            so=252;
                        resword = "0f85e38cddfe10be2a1c4249dfdd2b59";
                            goto compare;
                          case 977:
                            so=2;
                        resword = "0df130a097b2645470f24907dcd59b51";
                            goto compare;
                          case 988:
                            so=166;
                        resword = "c3faf6c44192ee6adc40628da9f89cab";
                            goto compare;
                          case 997:
                            so=309;
                        resword = "de12fbd65f2ecc7fb4e08483b0d75166";
                            goto compare;
                          case 1013:
                            so=12;
                        resword = "5bc990f7cd8d447a05103b3141d1fcf3";
                            goto compare;
                          case 1016:
                            so=177;
                        resword = "829f610d4821785e3821546eab785bd4";
                            goto compare;
                          case 1021:
                            so=83;
                        resword = "827f7abaeadae2821c3d82c05ea54f6e";
                            goto compare;
                          case 1026:
                            so=82;
                        resword = "83ffade12761f8c81a1c82587fdba1bc";
                            goto compare;
                          case 1028:
                            so=291;
                        resword = "d57fc1fba971303a321346adaba11e0c";
                            goto compare;
                          case 1056:
                            so=50;
                        resword = "1c30e7d76a566c672242537db53e5053";
                            goto compare;
                          case 1067:
                            so=360;
                        resword = "61b1ec51022e3c98b9a42fd9cd9d99a7";
                            goto compare;
                          case 1087:
                            so=88;
                        resword = "1a2a4c5dcd392c6acd30177bb5318380";
                            goto compare;
                          case 1088:
                            so=120;
                        resword = "0e7cc3c1a64928af1ba0e8866ec8cbbb";
                            goto compare;
                          case 1103:
                            so=265;
                        resword = "0a1cf2c4fd95a15cf4a6dab073c20ae5";
                            goto compare;
                          case 1118:
                            so=167;
                        resword = "27f68a923688da3daf0e34da90f5eaf7";
                            goto compare;
                          case 1142:
                            so=350;
                        resword = "048b16ec6d1a2a83aeb75b23a2b3f8e2";
                            goto compare;
                          case 1155:
                            so=84;
                        resword = "1a80626861945adec3aca4f2a4ef1800";
                            goto compare;
                          case 1157:
                            so=326;
                        resword = "9bce1486ee6c005ac15592091a072098";
                            goto compare;
                          case 1164:
                            so=355;
                        resword = "a4f63057ae7b4ee7f5e0b1d5264e1d4d";
                            goto compare;
                          case 1165:
                            so=65;
                        resword = "47b9acd1bac630012d0f0f9f357fceec";
                            goto compare;
                          case 1191:
                            so=11;
                        resword = "1990fce57630ae9a4fe7308caf15c29a";
                            goto compare;
                          case 1193:
                            so=135;
                        resword = "a858f87ee179b4a1bb304d925ca80218";
                            goto compare;
                          case 1201:
                            so=240;
                        resword = "1552e78c0868d346502abcad6fef4bff";
                            goto compare;
                          case 1213:
                            so=212;
                        resword = "e3def73d6705e058f65be00b1496e051";
                            goto compare;
                          case 1233:
                            so=309;
                        resword = "1a725d33bbf5e78f4a8250061640e4b9";
                            goto compare;
                          case 1243:
                            so=23;
                        resword = "27d65481178e87941f153ec548b343b9";
                            goto compare;
                          case 1279:
                            so=52;
                        resword = "455545daca1c6013b2a4198407cfa231";
                            goto compare;
                          case 1281:
                            so=208;
                        resword = "839f1c7d5b485b337b839e9fea240e53";
                            goto compare;
                          case 1295:
                            so=175;
                        resword = "1feae6d38e4602125caaf67d26e4336d";
                            goto compare;
                          case 1297:
                            so=54;
                        resword = "ea4ef4f3779c8d2e110e91ad633c8a45";
                            goto compare;
                          case 1301:
                            so=12;
                        resword = "f3d973d290b00945a6a930b71605c31a";
                            goto compare;
                          case 1303:
                            so=310;
                        resword = "c7242f1d9a924772366c5e17a249402e";
                            goto compare;
                          case 1313:
                            so=167;
                        resword = "925903f12f1d82f0f71ee6d71848fcee";
                            goto compare;
                          case 1318:
                            so=251;
                        resword = "f5defcbd10df50adce069b855810a2fc";
                            goto compare;
                          case 1353:
                            so=181;
                        resword = "74ed1c8565fb0328b712506b52072286";
                            goto compare;
                          case 1355:
                            so=214;
                        resword = "4bc8f3f9a39ef76a9680d0417c707b28";
                            goto compare;
                          case 1357:
                            so=316;
                        resword = "a7e944746919dae7c960a6a8414a5379";
                            goto compare;
                          case 1367:
                            so=260;
                        resword = "4e78d2f804836fe9f7a4a983ae2d8fa5";
                            goto compare;
                          case 1372:
                            so=52;
                        resword = "0ff804595a5545cc6ded22c4dab6a886";
                            goto compare;
                          case 1391:
                            so=270;
                        resword = "f5f90489ce18064aa93aa74f8dd176cd";
                            goto compare;
                          case 1416:
                            so=249;
                        resword = "7d1947665628379644ef94c45a7f1878";
                            goto compare;
                          case 1421:
                            so=257;
                        resword = "2cc8e087699c5293249a9e597a3b1f1d";
                            goto compare;
                          case 1431:
                            so=346;
                        resword = "88deeb045a4f39e0307c1fcb66aed2c1";
                            goto compare;
                          case 1433:
                            so=148;
                        resword = "3b8ebafd2c48d2d38ffb249d6a57324e";
                            goto compare;
                          case 1438:
                            so=185;
                        resword = "666f8fcbe4262ed962d67fa263b3122b";
                            goto compare;
                          case 1440:
                            so=264;
                        resword = "c4826853643541d9e09db71475972a2f";
                            goto compare;
                          case 1447:
                            so=334;
                        resword = "c28c268a516d2a4c1756836aeecacaa0";
                            goto compare;
                          case 1452:
                            so=93;
                        resword = "0b9dab6272b377c925ca787ceb10ac3c";
                            goto compare;
                          case 1460:
                            so=225;
                        resword = "d3af242bbdc1ff76693be3224b9d7cd1";
                            goto compare;
                          case 1461:
                            so=232;
                        resword = "5219e33a0995ec92af61a31b348d81af";
                            goto compare;
                          case 1464:
                            so=314;
                        resword = "3e4e3cce80aad628e0da4032f0a83dda";
                            goto compare;
                          case 1468:
                            so=238;
                        resword = "ff6ed376a080b929b954c2e87b01bd07";
                            goto compare;
                          case 1474:
                            so=193;
                        resword = "4eae6b10158aaf8829384004f394718b";
                            goto compare;
                          case 1476:
                            so=204;
                        resword = "95deaa7c6ae78b8fb48dd6fd65dba2af";
                            goto compare;
                          case 1478:
                            so=108;
                        resword = "12ea991a88ea72ec74e7a6668d4fb17a";
                            goto compare;
                          case 1487:
                            so=326;
                        resword = "dd8d23be10afa062691fbfb73306ce1d";
                            goto compare;
                          case 1488:
                            so=199;
                        resword = "12959bd0d7f8a73fc9618b8750b7345d";
                            goto compare;
                          case 1490:
                            so=174;
                        resword = "d34f0ca2c94441b56ee0891b044257f2";
                            goto compare;
                          case 1493:
                            so=188;
                        resword = "e7a918e2b9a04d1e690634429de5ac7c";
                            goto compare;
                          case 1501:
                            so=28;
                        resword = "15e161cbbc036e70012cb0ee03c1fa03";
                            goto compare;
                          case 1506:
                            so=190;
                        resword = "28d797901abfd3eb7431368ee7e7aeab";
                            goto compare;
                          case 1518:
                            so=267;
                        resword = "c082bfc63efa70fa68abeefc61de4e53";
                            goto compare;
                          case 1521:
                            so=153;
                        resword = "1711578881e077b293eafb76cf1dec90";
                            goto compare;
                          case 1523:
                            so=277;
                        resword = "1837cc74930d03342efe173f52715875";
                            goto compare;
                          case 1524:
                            so=136;
                        resword = "426e675296ac46ad499c2d3f1b7d32d8";
                            goto compare;
                          case 1547:
                            so=338;
                        resword = "0c4661c1448e013402494fb1be90cd33";
                            goto compare;
                          case 1563:
                            so=102;
                        resword = "238420c5765f2f55515ab3c2f94cb233";
                            goto compare;
                          case 1591:
                            so=238;
                        resword = "1295264631a0215b0211b02e7f3a9883";
                            goto compare;
                          case 1603:
                            so=32;
                        resword = "21d8a15be753e2912768a3b380e4135c";
                            goto compare;
                          case 1606:
                            so=68;
                        resword = "1457631267961fae0a6003c4552f0263";
                            goto compare;
                          case 1646:
                            so=4;
                        resword = "14a73cb61b570322254584eb924770b9";
                            goto compare;
                          case 1658:
                            so=47;
                        resword = "16eac0f3c4313ddade5d96f1b8de6528";
                            goto compare;
                          case 1686:
                            so=115;
                        resword = "79aed662b6953797b974c157e2fd63b9";
                            goto compare;
                          case 1695:
                            so=274;
                        resword = "e529d71b5afae372e63c5fc7d651eb9b";
                            goto compare;
                          case 1709:
                            so=74;
                        resword = "61ce64c1d79c971997671b6f80349f2a";
                            goto compare;
                          case 1735:
                            so=223;
                        resword = "07d30d9fa14f1dce9a5e03b22e3338ab";
                            goto compare;
                          case 1738:
                            so=287;
                        resword = "c5a249934d7d71a08df072371a3cf610";
                            goto compare;
                          case 1740:
                            so=217;
                        resword = "dd1e7795ce2b8a32529e901e81ca903f";
                            goto compare;
                          case 1741:
                            so=220;
                        resword = "1c0b00a2ce33dfd74905edc239d2396d";
                            goto compare;
                          case 1748:
                            so=93;
                        resword = "d449f705ec7377e4a17041b44a6e93a1";
                            goto compare;
                          case 1764:
                            so=128;
                        resword = "715e55c5abcca88e5847b5fb1c05d90e";
                            goto compare;
                          case 1771:
                            so=159;
                        resword = "79ee87c7db5f21359846270cd39d97b2";
                            goto compare;
                          case 1783:
                            so=169;
                        resword = "f0a9297412cc503e086550ff59e3e615";
                            goto compare;
                          case 1792:
                            so=359;
                        resword = "40cea7df87a9ee9a8a4b90f29bc3e063";
                            goto compare;
                          case 1806:
                            so=137;
                        resword = "18772d6a9d3967efd5cb509826a5c910";
                            goto compare;
                          case 1812:
                            so=156;
                        resword = "21ab6dc091c5aa12fec8d96a7002e29c";
                            goto compare;
                          case 1813:
                            so=59;
                        resword = "135480582ca7b1855fee52398375d12a";
                            goto compare;
                          case 1828:
                            so=208;
                        resword = "25d42d64da656bfbb2aacafcfb89e23e";
                            goto compare;
                          case 1861:
                            so=131;
                        resword = "dba826923ddf132480f4bb37ba68bf2b";
                            goto compare;
                          case 1863:
                            so=42;
                        resword = "cec3ca9c9b580d3a18a71a6da12b2d37";
                            goto compare;
                          case 1885:
                            so=14;
                        resword = "ca436baa8c1cd5ae305a09f21d5d0503";
                            goto compare;
                          case 1904:
                            so=195;
                        resword = "a81ee43a94cd96cbf8e6200086f92bcc";
                            goto compare;
                          case 1931:
                            so=37;
                        resword = "cc8da11adfe3d2963c4a798457b32cc0";
                            goto compare;
                          case 1935:
                            so=318;
                        resword = "8dee23a3f98d5e12f7ff50b187d2dd45";
                            goto compare;
                          case 1939:
                            so=299;
                        resword = "cf94711dae069c64ece9fa9d62a96207";
                            goto compare;
                          case 1942:
                            so=259;
                        resword = "138a1fef74c99a5febcc1532e807d3a8";
                            goto compare;
                          case 1954:
                            so=79;
                        resword = "2458f7c429ce66ac29bd11a5f9aa3005";
                            goto compare;
                          case 1968:
                            so=198;
                        resword = "3a1e735fa18fce4945d20aff6ad39c59";
                            goto compare;
                          case 1983:
                            so=137;
                        resword = "1cb4bf717702ffda59d5717592599dfe";
                            goto compare;
                          case 1990:
                            so=147;
                        resword = "a2d9b49c3923e110d035981227727972";
                            goto compare;
                          case 2000:
                            so=345;
                        resword = "7d04c83e23efecbdac6735a15950b1a4";
                            goto compare;
                          case 2004:
                            so=138;
                        resword = "4269376b59d01979e14e150ac45bc640";
                            goto compare;
                          case 2041:
                            so=179;
                        resword = "1245031206f897ccdd5b8ee6054bcbe2";
                            goto compare;
                          case 2042:
                            so=338;
                        resword = "7aaeca0a471c1254a5f8357cd798081c";
                            goto compare;
                          case 2065:
                            so=276;
                        resword = "0c2b94b8194fe73314e1b0adc96baf89";
                            goto compare;
                          case 2070:
                            so=308;
                        resword = "a0b9c999a1264ce13c53cb3ad30dfba1";
                            goto compare;
                          case 2080:
                            so=306;
                        resword = "19fc8be5a0b6255400bd5266b704f6d9";
                            goto compare;
                          case 2088:
                            so=143;
                        resword = "012b0a7ab8cd04f684e74112acd74f58";
                            goto compare;
                          case 2091:
                            so=133;
                        resword = "ecafd39970a42ce43bc6b6a48bd84c1e";
                            goto compare;
                          case 2093:
                            so=237;
                        resword = "1944cc7f3a32528d2d41c6bd3140956a";
                            goto compare;
                          case 2112:
                            so=275;
                        resword = "0003b517320b13f080c719433768a5ae";
                            goto compare;
                          case 2113:
                            so=264;
                        resword = "aabc0c0d9c6ee4e2b2c3459ec62200c3";
                            goto compare;
                          case 2147:
                            so=1;
                        resword = "20a61a03405cd7ae6bc9eabaa61e96fb";
                            goto compare;
                          case 2153:
                            so=212;
                        resword = "e22fbe24d6533c6dc52fba4415714c40";
                            goto compare;
                          case 2156:
                            so=76;
                        resword = "c962a4dd7727fa22aa99ba8d6a9f3b78";
                            goto compare;
                          case 2211:
                            so=17;
                        resword = "4f792bda2ef01970e3b40f04de1b396e";
                            goto compare;
                          case 2216:
                            so=176;
                        resword = "eec8cc99575f673645ce582bd4157001";
                            goto compare;
                          case 2233:
                            so=215;
                        resword = "0da8edbecf776e17318928fc5c9981fd";
                            goto compare;
                          case 2236:
                            so=91;
                        resword = "7bc920386bd7bbab8d70fae15189a881";
                            goto compare;
                          case 2241:
                            so=14;
                        resword = "c607819f8bfe2e5323ba5d343d7019df";
                            goto compare;
                          case 2246:
                            so=307;
                        resword = "376e3fe850dffaa69df1e18800c6f564";
                            goto compare;
                          case 2248:
                            so=40;
                        resword = "1f1b7b25c50872c076d16a369c87e95a";
                            goto compare;
                          case 2263:
                            so=178;
                        resword = "e599f3db341d8bed824297876fbd93a6";
                            goto compare;
                          case 2281:
                            so=222;
                        resword = "229e211a87d0bb0bdc141d9f753aff88";
                            goto compare;
                          case 2298:
                            so=121;
                        resword = "362f9eb423d332906eee71f40def250f";
                            goto compare;
                          case 2306:
                            so=226;
                        resword = "c723c5a6757e59a99bc4b8dec639f806";
                            goto compare;
                          case 2336:
                            so=15;
                        resword = "12d27d36e0b4bcaf88d4b42ef82c306b";
                            goto compare;
                          case 2339:
                            so=168;
                        resword = "0ea3811a8bdbc4e4d2fd020bf3fe5262";
                            goto compare;
                          case 2343:
                            so=0;
                        resword = "2fce67d867e080e6730c2bee7bf730dd";
                            goto compare;
                          case 2346:
                            so=146;
                        resword = "c0a3f6b77d625ed88a0c8e24d70024f5";
                            goto compare;
                          case 2356:
                            so=219;
                        resword = "1350678e7407221180ca2bf3f369d209";
                            goto compare;
                          case 2357:
                            so=160;
                        resword = "0454a087e6865144b36ccb411d35601e";
                            goto compare;
                          case 2375:
                            so=247;
                        resword = "a0091c93c8f8ff697919df4229967570";
                            goto compare;
                          case 2380:
                            so=51;
                        resword = "f95fcfa0c39c0e8fc533211439c0f720";
                            goto compare;
                          case 2386:
                            so=322;
                        resword = "1b21e9fdae6aae7f4adb78819735cc5e";
                            goto compare;
                          case 2390:
                            so=24;
                        resword = "c70c5284e134c2c38d06db17aff7a7d1";
                            goto compare;
                          case 2399:
                            so=100;
                        resword = "66792c3e4c3fd490556b5eb6e40d54be";
                            goto compare;
                          case 2400:
                            so=116;
                        resword = "121c811bf2d18cbc7000bc99992729bb";
                            goto compare;
                          case 2405:
                            so=119;
                        resword = "0b18099daa134de764bd535720961ac2";
                            goto compare;
                          case 2406:
                            so=3;
                        resword = "181010479c032523814990b784e64226";
                            goto compare;
                          case 2413:
                            so=86;
                        resword = "3dbe9fa7c4abde865f55958562c70ba0";
                            goto compare;
                          case 2426:
                            so=183;
                        resword = "7b1f32739294528112a8cd240ce1630d";
                            goto compare;
                          case 2430:
                            so=319;
                        resword = "a85913741cba8153858286a81513e908";
                            goto compare;
                          case 2437:
                            so=120;
                        resword = "0443ffaa1b6e9d27a11375c56f43bc2b";
                            goto compare;
                          case 2442:
                            so=227;
                        resword = "910db24391cb7139be2dca7e248b25ac";
                            goto compare;
                          case 2443:
                            so=227;
                        resword = "b303dc6e12d39ab9c86dd0d3ec09ead6";
                            goto compare;
                          case 2451:
                            so=245;
                        resword = "15960b64e6c6a59a041a79d3fc2fd771";
                            goto compare;
                          case 2454:
                            so=11;
                        resword = "ed5809767d852386bcce8d81be6cf22e";
                            goto compare;
                          case 2466:
                            so=231;
                        resword = "1686d7193df55c4409d739874a68a97e";
                            goto compare;
                          case 2476:
                            so=57;
                        resword = "ec5f806e2375ca8573b93422a3af7ae7";
                            goto compare;
                          case 2510:
                            so=118;
                        resword = "514f30229797bbda09034e5894c359c1";
                            goto compare;
                          case 2528:
                            so=241;
                        resword = "fb6e79f1f38ea3dd8f0c0e4b3c74e94d";
                            goto compare;
                          case 2536:
                            so=125;
                        resword = "1b02f2a481c13f3b9581e3876ba0e4e5";
                            goto compare;
                          case 2556:
                            so=200;
                        resword = "308f39450bda40ba72db49f601e39093";
                            goto compare;
                          case 2565:
                            so=257;
                        resword = "353f0a08764737d5e22f7b6b3a44d13d";
                            goto compare;
                          case 2583:
                            so=312;
                        resword = "2ec1c9fb8d085188bd9bd3ec712d3b7e";
                            goto compare;
                          case 2589:
                            so=334;
                        resword = "cae8f8a14c5a236ad1cb5452ff8ab69d";
                            goto compare;
                          case 2591:
                            so=266;
                        resword = "aee84a54499e8145e1ffdefd1f48ea3f";
                            goto compare;
                          case 2601:
                            so=334;
                        resword = "b5d391c8e3e0fa11178bd6c4dca12b5d";
                            goto compare;
                        }
                    }
                  else
                    {
                      switch (key - 8105)
                        {
                          case 0:
                            so=326;
                        resword = "959f9bc84b7ca3ea324234565dbed4be";
                            goto compare;
                          case 25:
                            so=70;
                        resword = "b5172b7110faf2c4cf909b789ecb0e51";
                            goto compare;
                          case 30:
                            so=182;
                        resword = "141bbc490807e37b6c42cc4542e237cc";
                            goto compare;
                          case 34:
                            so=223;
                        resword = "0b9654d5c8cb355150947fe111045695";
                            goto compare;
                          case 50:
                            so=104;
                        resword = "db7fffb6e897f45bdc4154949f129322";
                            goto compare;
                          case 58:
                            so=301;
                        resword = "b971ff594d9a89de9124cb7afe29be0c";
                            goto compare;
                          case 67:
                            so=234;
                        resword = "eaaf096768ed3a1b75f86676eb8e501c";
                            goto compare;
                          case 77:
                            so=341;
                        resword = "070e4a1eaed9721b7a51ebbff8dd2c9a";
                            goto compare;
                          case 80:
                            so=109;
                        resword = "ee68610b790e43c0fd70a809b9950150";
                            goto compare;
                          case 92:
                            so=30;
                        resword = "2e7aaad2c92f60dc92cf0235a050c85d";
                            goto compare;
                          case 103:
                            so=7;
                        resword = "16c6849038e2c84811b456856ea0dc64";
                            goto compare;
                          case 118:
                            so=219;
                        resword = "727fc050523533f9f87b225d57d2f88b";
                            goto compare;
                          case 120:
                            so=185;
                        resword = "bf91110d2a34cfd50e52fc9d12cc81c9";
                            goto compare;
                          case 132:
                            so=26;
                        resword = "1e32566173c7c4aec109a98000062d0f";
                            goto compare;
                          case 137:
                            so=123;
                        resword = "3db94eaaa298bcece1883085d35eb8f2";
                            goto compare;
                          case 138:
                            so=73;
                        resword = "69afb68dadfb8be49701f7c69b2383dd";
                            goto compare;
                          case 153:
                            so=277;
                        resword = "c4d12cadf2ee2bcd786bc9567d8444e7";
                            goto compare;
                          case 156:
                            so=241;
                        resword = "c1dc1a73877a47991e01048ddd17ae95";
                            goto compare;
                          case 158:
                            so=329;
                        resword = "925fe919d20e3dbd178aaab42c2d8666";
                            goto compare;
                          case 170:
                            so=103;
                        resword = "1ba01c2e4c5d8a4f93627eccf66f277f";
                            goto compare;
                          case 175:
                            so=94;
                        resword = "c5545e38320a1b6fa4e1f6706831bb31";
                            goto compare;
                          case 188:
                            so=323;
                        resword = "c0831ca54a4be20f9f94c7648343c866";
                            goto compare;
                          case 204:
                            so=75;
                        resword = "1aaa3925771b976cca52e10d1508751d";
                            goto compare;
                          case 212:
                            so=22;
                        resword = "cab4c4802985a044ad29794883072645";
                            goto compare;
                          case 220:
                            so=72;
                        resword = "168345b9f6cc2f701c168446947c41e3";
                            goto compare;
                          case 226:
                            so=131;
                        resword = "0f9b23a8044b64cea42663ccb47e7aef";
                            goto compare;
                          case 255:
                            so=48;
                        resword = "1e3260491443c1b60b3c7770a2c17626";
                            goto compare;
                          case 266:
                            so=227;
                        resword = "ade669af773bbbaaa7cbd0a1ba31c121";
                            goto compare;
                          case 278:
                            so=243;
                        resword = "b2cbcebba25638cc28db4c0bfa70f3f2";
                            goto compare;
                          case 331:
                            so=239;
                        resword = "1278814f592a2779c3122fd196b9aee1";
                            goto compare;
                          case 335:
                            so=325;
                        resword = "3d2e23c311eeff7a7f6ca9e312d0f85a";
                            goto compare;
                          case 338:
                            so=212;
                        resword = "9d6eb442e14f0cf755317a3c75573b41";
                            goto compare;
                          case 340:
                            so=248;
                        resword = "c830e4c37f8ce9518a05696cf7543a65";
                            goto compare;
                          case 350:
                            so=157;
                        resword = "00a8e87ded84bd21a6ad678a94647b76";
                            goto compare;
                          case 360:
                            so=304;
                        resword = "cbfd3f860c3156a6cc94d0a8c99d38fc";
                            goto compare;
                          case 368:
                            so=220;
                        resword = "c0e8013646ed466ec3634434f73bebe7";
                            goto compare;
                          case 372:
                            so=201;
                        resword = "dfdf28a282eee5c61743857a6a938e18";
                            goto compare;
                          case 376:
                            so=143;
                        resword = "28c98d2b3e744b34168d899dbba3ea82";
                            goto compare;
                          case 382:
                            so=150;
                        resword = "0c1ec6a1cfa26b97d4d6b669c822dafe";
                            goto compare;
                          case 388:
                            so=257;
                        resword = "b4b289ca6bc1eb24766e6100473c6909";
                            goto compare;
                          case 394:
                            so=211;
                        resword = "cf80cd340c3b00beec26a9e43e7a556a";
                            goto compare;
                          case 396:
                            so=240;
                        resword = "1564c04dc61d9c76e67cc5780e0a1481";
                            goto compare;
                          case 398:
                            so=95;
                        resword = "721f8248f8aea2a111c2998225c1e09a";
                            goto compare;
                          case 405:
                            so=94;
                        resword = "10c66a2f98f0bf08c903008b9d0af3f6";
                            goto compare;
                          case 423:
                            so=336;
                        resword = "b3214548c727e9aadbe773778c3d6076";
                            goto compare;
                          case 440:
                            so=11;
                        resword = "1bb4f4b669ca8d5c346813c27eb0f26d";
                            goto compare;
                          case 450:
                            so=191;
                        resword = "5edfe206b9e352c9d3a8865518c476c0";
                            goto compare;
                          case 453:
                            so=152;
                        resword = "c33850851e833e0ae1450876a863a1ec";
                            goto compare;
                          case 462:
                            so=348;
                        resword = "bf3b4109b879776dc91d5993c7dcd204";
                            goto compare;
                          case 467:
                            so=186;
                        resword = "c156b32a6079a4eb1a9cbf7fda213a1b";
                            goto compare;
                          case 486:
                            so=184;
                        resword = "1a28c6a00c352d104e0c21200ee5e4fc";
                            goto compare;
                          case 508:
                            so=176;
                        resword = "1da141486c900d3494caf8ab3a60b9d2";
                            goto compare;
                          case 517:
                            so=285;
                        resword = "110072adca106da17ee271414a857d82";
                            goto compare;
                          case 526:
                            so=19;
                        resword = "25e900edfcc50c3105b20ad8b7f61e4c";
                            goto compare;
                          case 545:
                            so=295;
                        resword = "410e738bb92cb04404dfeae10233e469";
                            goto compare;
                          case 556:
                            so=94;
                        resword = "c8a14159200fce41408881a943047c74";
                            goto compare;
                          case 567:
                            so=330;
                        resword = "2e441b5e76b16189b076ba279f0f60e8";
                            goto compare;
                          case 570:
                            so=198;
                        resword = "bc117e4ae783a7ba6cc49488d050eb35";
                            goto compare;
                          case 583:
                            so=144;
                        resword = "c9269cb2a5cb91540ae0b2ac7e739f99";
                            goto compare;
                          case 585:
                            so=168;
                        resword = "b574aa6f6b96a9783079005fa1f58c13";
                            goto compare;
                          case 592:
                            so=200;
                        resword = "b8842545742de3374fa44eb88d27ec3a";
                            goto compare;
                          case 602:
                            so=39;
                        resword = "df3e8793b77b8d74b41de24089301ca3";
                            goto compare;
                          case 607:
                            so=361;
                        resword = "b394f50fa93de6754ce58f9e5b56ecd2";
                            goto compare;
                          case 630:
                            so=216;
                        resword = "b400f72a0198a1dd6adf6e19ac6ef48e";
                            goto compare;
                          case 653:
                            so=286;
                        resword = "1902cdb9d1cb8e6d7d7a9d30eddd071f";
                            goto compare;
                          case 660:
                            so=119;
                        resword = "1fad11598a3671fc7db0586e608fb7f5";
                            goto compare;
                          case 673:
                            so=31;
                        resword = "e70f65af4208df8c80bf575afc4963ca";
                            goto compare;
                          case 674:
                            so=74;
                        resword = "4f2fd3504d83b8a6d96a52dd0b9493f2";
                            goto compare;
                          case 679:
                            so=193;
                        resword = "19782d04554265925e97006391120b28";
                            goto compare;
                          case 687:
                            so=2;
                        resword = "1b0c94013ff428de05c81daae0484e55";
                            goto compare;
                          case 689:
                            so=209;
                        resword = "445f2d0fd4a14b4d6422a29fad24b337";
                            goto compare;
                          case 725:
                            so=327;
                        resword = "cbcdd90d84ad60b61c99486f11d06be1";
                            goto compare;
                          case 764:
                            so=85;
                        resword = "c9c884bc00c7cc6387ce8ce2eaaa997f";
                            goto compare;
                          case 766:
                            so=39;
                        resword = "45cfff85b906db44e16409c5dd204995";
                            goto compare;
                          case 792:
                            so=293;
                        resword = "1f81e3effe1cc629735847b0f15c67dd";
                            goto compare;
                          case 797:
                            so=10;
                        resword = "b35c779fc12753e417ba5ad131e10300";
                            goto compare;
                          case 798:
                            so=338;
                        resword = "0658c5d4503733c7b76f12816caa63f5";
                            goto compare;
                          case 803:
                            so=95;
                        resword = "03b811b93435b92bb5bcea2772566451";
                            goto compare;
                          case 819:
                            so=347;
                        resword = "17a8d4bc332a36ae72d4cfc9f778d5fc";
                            goto compare;
                          case 828:
                            so=274;
                        resword = "b0f596791e519696497bbaa1fa77cfeb";
                            goto compare;
                          case 855:
                            so=157;
                        resword = "0939cb239024124f27fdb3f2751ee930";
                            goto compare;
                          case 875:
                            so=81;
                        resword = "fc1fc36ec96c41fd80e64e2149c89130";
                            goto compare;
                          case 876:
                            so=142;
                        resword = "a84f8ae0a6844089e8577e1a06576fd8";
                            goto compare;
                          case 886:
                            so=275;
                        resword = "f15fe39c56e233f1e446f9fdd1666e33";
                            goto compare;
                          case 890:
                            so=209;
                        resword = "1a6b5ee5b976e28aa8a6185e5984148b";
                            goto compare;
                          case 892:
                            so=258;
                        resword = "a4d938ae0b6e209913360ef15755a09c";
                            goto compare;
                          case 912:
                            so=109;
                        resword = "b9a73f301174fbaee574ab7bd54251c4";
                            goto compare;
                          case 938:
                            so=96;
                        resword = "c7e0a7c7910bdd81f5686ca9b33c8f1a";
                            goto compare;
                          case 943:
                            so=166;
                        resword = "b640f368b2a1fa9086e0342289d6fed5";
                            goto compare;
                          case 975:
                            so=250;
                        resword = "bc2ab0814a25af708fa4d7cf41e716a8";
                            goto compare;
                          case 979:
                            so=282;
                        resword = "c0bc8eff5e5e6e0accc6186927e80fbb";
                            goto compare;
                          case 1000:
                            so=328;
                        resword = "3e7e917d1d477dd3ba3d389a25b3adc2";
                            goto compare;
                          case 1002:
                            so=249;
                        resword = "c1ddd2060eb2cb334854478ed56948bd";
                            goto compare;
                          case 1005:
                            so=185;
                        resword = "cba433229cc8cc36f335cd127e13add6";
                            goto compare;
                          case 1008:
                            so=42;
                        resword = "b6411d19e598a69e80f56759591d0e1b";
                            goto compare;
                          case 1036:
                            so=162;
                        resword = "a94f0eb190750272e74a1e813840115d";
                            goto compare;
                          case 1044:
                            so=160;
                        resword = "baf5c357c10d9833616bd1864a50f644";
                            goto compare;
                          case 1058:
                            so=263;
                        resword = "caa89ff8f3cc5c302c8b1193d6d77ffc";
                            goto compare;
                          case 1064:
                            so=354;
                        resword = "194817cf7b850f3ad2ff9cade9463d51";
                            goto compare;
                          case 1089:
                            so=167;
                        resword = "4de94a6d7c02e167611c46d0531cc46b";
                            goto compare;
                          case 1090:
                            so=265;
                        resword = "cd54c061a41a5ae88d6ac0d16a5f1888";
                            goto compare;
                          case 1091:
                            so=208;
                        resword = "cea8d8bed287b522205d71d1b59aa270";
                            goto compare;
                          case 1095:
                            so=357;
                        resword = "823f9185c70c4ce58d75d5741c94b86e";
                            goto compare;
                          case 1117:
                            so=245;
                        resword = "a0ef860b965469b673ad92f1f0fdcad7";
                            goto compare;
                          case 1124:
                            so=339;
                        resword = "cd584179e0e14d5b59f5f16fc4cb54a3";
                            goto compare;
                          case 1135:
                            so=76;
                        resword = "b0a4de89a78142860b61bb1a904b97d7";
                            goto compare;
                          case 1138:
                            so=293;
                        resword = "508f4187256b2384ddd810ea51bf0cf4";
                            goto compare;
                          case 1150:
                            so=116;
                        resword = "028967035d89766a7f149a730ba76b5a";
                            goto compare;
                          case 1165:
                            so=83;
                        resword = "bf365c5cb4c95b0c0a3bbac648dd11b1";
                            goto compare;
                          case 1173:
                            so=312;
                        resword = "5a7f177b6ba012feb76211965cc821e8";
                            goto compare;
                          case 1215:
                            so=154;
                        resword = "09d8ceb7722ea1aafcce50ff740f597a";
                            goto compare;
                          case 1217:
                            so=14;
                        resword = "a0d98862172234e3fa547423a81ba486";
                            goto compare;
                          case 1225:
                            so=89;
                        resword = "cd54688dbe05d10a8cb33b91c6ce5608";
                            goto compare;
                          case 1228:
                            so=3;
                        resword = "12881f5916593926e27ac5f977b6d3ce";
                            goto compare;
                          case 1233:
                            so=154;
                        resword = "bbb70e21b08839003fe7897a39ee2ff8";
                            goto compare;
                          case 1247:
                            so=271;
                        resword = "11bbf9f9c1a7698bdb1b24fadeb9fd23";
                            goto compare;
                          case 1248:
                            so=267;
                        resword = "e81fccb8308e86080b003eb4602edd13";
                            goto compare;
                          case 1263:
                            so=67;
                        resword = "ff3f9c92e93f358654697c7232a230ae";
                            goto compare;
                          case 1264:
                            so=267;
                        resword = "09242820bc5be98bb9cb10ac74a353dd";
                            goto compare;
                          case 1272:
                            so=324;
                        resword = "be2afb06adc8bc984fe9f6a9b782eea4";
                            goto compare;
                          case 1273:
                            so=282;
                        resword = "1b81ee2c5472ea518ae9ec038ab11d4a";
                            goto compare;
                          case 1296:
                            so=64;
                        resword = "ce68251c5ea7599c946108ced499a66a";
                            goto compare;
                          case 1302:
                            so=149;
                        resword = "b40c637306b487637f6c3fb316257d17";
                            goto compare;
                          case 1333:
                            so=271;
                        resword = "9b1fbd62c9ab4e2b92dfdf5dcd6abaee";
                            goto compare;
                          case 1350:
                            so=72;
                        resword = "c8029f01774f5fb9e1c8f57df37be67a";
                            goto compare;
                          case 1362:
                            so=4;
                        resword = "c1f16275197b7e7273942efd2ccf3c32";
                            goto compare;
                          case 1396:
                            so=48;
                        resword = "c0239a05f84fa8be9d3e4bad1b99e961";
                            goto compare;
                          case 1420:
                            so=299;
                        resword = "2d8e382a2a360f876a8dab38d419c192";
                            goto compare;
                          case 1424:
                            so=29;
                        resword = "4a7fbfd93f2719c1fdcb21ac81d4440e";
                            goto compare;
                          case 1432:
                            so=21;
                        resword = "ba00fc5ce24cb9ff35568754bc67c666";
                            goto compare;
                          case 1435:
                            so=172;
                        resword = "00692f088e8aeab6280e01367e20e3db";
                            goto compare;
                          case 1443:
                            so=145;
                        resword = "10cbea21bd4b5db42c1d981ca6804881";
                            goto compare;
                          case 1474:
                            so=78;
                        resword = "c5b83286686ebd023b6796bda26d6556";
                            goto compare;
                          case 1475:
                            so=3;
                        resword = "c1e842681a7df1249d135c549f947bc7";
                            goto compare;
                          case 1476:
                            so=221;
                        resword = "16405c0332af1d6e0d4c5f0e8ffd0faa";
                            goto compare;
                          case 1512:
                            so=163;
                        resword = "3dd97a45029c76bc6499c435429c0ec1";
                            goto compare;
                          case 1518:
                            so=218;
                        resword = "cfde370e8f0898ef0cbf8f3227ee31b2";
                            goto compare;
                          case 1535:
                            so=201;
                        resword = "1e56a82305f2fd3b20c72a42f7f548b4";
                            goto compare;
                          case 1542:
                            so=57;
                        resword = "a4ef1be4bc85587387b4b22eb92b10fe";
                            goto compare;
                          case 1546:
                            so=351;
                        resword = "110b260c0c14269fee76569638513568";
                            goto compare;
                          case 1555:
                            so=174;
                        resword = "e6fff935bf1c1902dd0079b522be1eb7";
                            goto compare;
                          case 1568:
                            so=213;
                        resword = "b413d8357194cbb7f36ef6a1deda3f3c";
                            goto compare;
                          case 1572:
                            so=344;
                        resword = "bafd5cdfd402bcabc6d62cfcfd095a66";
                            goto compare;
                          case 1613:
                            so=55;
                        resword = "f479436a368c54ecba465e3114b1a7cf";
                            goto compare;
                          case 1635:
                            so=54;
                        resword = "9e9fcc17acd05a67a2491c27c49d019c";
                            goto compare;
                          case 1648:
                            so=319;
                        resword = "b4adffc486a80b911e943d8c852ab6e2";
                            goto compare;
                          case 1650:
                            so=73;
                        resword = "bfd039049a4bb05543c34b5de8e0beb5";
                            goto compare;
                          case 1654:
                            so=320;
                        resword = "bc78df092425d8a922e83b51b9b17f95";
                            goto compare;
                          case 1668:
                            so=28;
                        resword = "b593465032ae42a6243890cc0014df65";
                            goto compare;
                          case 1719:
                            so=306;
                        resword = "b9389b4c1a47587d28c2c07fd2849c8f";
                            goto compare;
                          case 1725:
                            so=347;
                        resword = "bd1a9f1394229fa309d8b998578f0e51";
                            goto compare;
                          case 1730:
                            so=149;
                        resword = "00f96175da22fecf49c2da89e187ed4a";
                            goto compare;
                          case 1764:
                            so=203;
                        resword = "0a16f728255bc67bb73ca34dc6b6ac64";
                            goto compare;
                          case 1773:
                            so=358;
                        resword = "b2d0666f647e81a59aac5c125ce11a21";
                            goto compare;
                          case 1783:
                            so=205;
                        resword = "fda9f47c54bb5751f7d4d8ddb37299f1";
                            goto compare;
                          case 1788:
                            so=228;
                        resword = "bc757a947b2bb199275713ac9e05a3f8";
                            goto compare;
                          case 1797:
                            so=177;
                        resword = "319ffd3b296377288b4e86fa060cdb27";
                            goto compare;
                          case 1798:
                            so=79;
                        resword = "bda5896c7938dd0d2b1e7469b1d042e5";
                            goto compare;
                          case 1800:
                            so=86;
                        resword = "1f3da9e3151a8a3cf843b0791bdd4045";
                            goto compare;
                          case 1815:
                            so=108;
                        resword = "1e47cd6f5658cea2f86ae97cfc4b8615";
                            goto compare;
                          case 1838:
                            so=267;
                        resword = "c0cb5183b12e70cf83d367ce4e5fec55";
                            goto compare;
                          case 1863:
                            so=332;
                        resword = "38ff20ca12ce7d2987fc36e646858714";
                            goto compare;
                          case 1917:
                            so=341;
                        resword = "09966fa8f68fb7b6a8967c4a13af0963";
                            goto compare;
                          case 1921:
                            so=121;
                        resword = "1d4ca206cb0a6a55e5aebbcd59e661ce";
                            goto compare;
                          case 1936:
                            so=211;
                        resword = "09694a3f41fd6c76e0d8c74932aa9b69";
                            goto compare;
                          case 1940:
                            so=27;
                        resword = "21490522dd48d5221f487e964608a975";
                            goto compare;
                          case 1949:
                            so=194;
                        resword = "b438c9a06e95f9a8477ddfa6467392c0";
                            goto compare;
                          case 1951:
                            so=203;
                        resword = "adc975da4c8c0913ca92e0956767fdf7";
                            goto compare;
                          case 1996:
                            so=238;
                        resword = "c95ed3ea1882c9d776057f565c0f6c79";
                            goto compare;
                          case 1997:
                            so=44;
                        resword = "08af976fe009b56ec21dc61b819c9fa6";
                            goto compare;
                          case 2063:
                            so=206;
                        resword = "b8564e1eca1898d287f8bca5a99ffa7c";
                            goto compare;
                          case 2085:
                            so=101;
                        resword = "ca2e777d19a30afd6dfd3e9554454fed";
                            goto compare;
                          case 2102:
                            so=230;
                        resword = "bb13869e49d25673ea8e0804bc4893a6";
                            goto compare;
                          case 2107:
                            so=104;
                        resword = "bbdc03ff66824c374c7019b83dfaa953";
                            goto compare;
                          case 2141:
                            so=164;
                        resword = "c70dd6dd5b68d14cb5ffd50f08a71b6a";
                            goto compare;
                          case 2159:
                            so=226;
                        resword = "40efaad4b41b6bc2c1922b9142eb4a4e";
                            goto compare;
                          case 2196:
                            so=146;
                        resword = "c01e93570ba5f51312360b8fd27edfa7";
                            goto compare;
                          case 2241:
                            so=211;
                        resword = "c01ed0c20212e1bd270c70356fac9791";
                            goto compare;
                          case 2254:
                            so=279;
                        resword = "4389b0042b6f5357ea56085712429df5";
                            goto compare;
                          case 2274:
                            so=329;
                        resword = "bef16a7fcec14ab8e635831d3ffdb324";
                            goto compare;
                          case 2305:
                            so=353;
                        resword = "8b4f51e7421c59a58f5e813483d49762";
                            goto compare;
                          case 2317:
                            so=309;
                        resword = "ba879d75911bb3996e0c2e86b3b34447";
                            goto compare;
                          case 2328:
                            so=153;
                        resword = "198701643cdf06916583af2c60685882";
                            goto compare;
                          case 2360:
                            so=254;
                        resword = "0cdf0510d463d8fa95e11b7d84d39ff1";
                            goto compare;
                          case 2399:
                            so=292;
                        resword = "ad7f0dc880670b0f63e9850adc044ff9";
                            goto compare;
                          case 2401:
                            so=217;
                        resword = "cc09e1b5d6345c93c9effe752a7c93a7";
                            goto compare;
                          case 2449:
                            so=170;
                        resword = "01593a09ddd91fba1b137e208bab1a41";
                            goto compare;
                          case 2477:
                            so=171;
                        resword = "08be346521efc175c35bcb6acbf013d8";
                            goto compare;
                          case 2538:
                            so=211;
                        resword = "eb7f8e7ca14e87123e681aa331fe8af0";
                            goto compare;
                          case 2558:
                            so=31;
                        resword = "2bfe8b7ba8db6711df30960a0ecf4d1c";
                            goto compare;
                          case 2572:
                            so=77;
                        resword = "b131251056696e2f878e047d9fb6b699";
                            goto compare;
                          case 2597:
                            so=306;
                        resword = "b16671b2d951300b37cdb0ca30bd7dc4";
                            goto compare;
                          case 2600:
                            so=349;
                        resword = "b41b400dc25d6243a8ee00592f773a22";
                            goto compare;
                          case 2624:
                            so=188;
                        resword = "0b2e191457dcdd4294539977464a4ff1";
                            goto compare;
                          case 2694:
                            so=87;
                        resword = "f699145cbe1f1afeb2d2bc3d7ee58fe1";
                            goto compare;
                          case 2703:
                            so=242;
                        resword = "ba33af7759bf47ce0376de4ec749d02a";
                            goto compare;
                          case 2704:
                            so=153;
                        resword = "c4798d492fb966d90505ed7b008afe8e";
                            goto compare;
                          case 2710:
                            so=112;
                        resword = "bf25f2c1dffe1793d75064fe36e05c20";
                            goto compare;
                          case 2765:
                            so=129;
                        resword = "bad65fcb2d1666e0acb41da15eb408a5";
                            goto compare;
                          case 2836:
                            so=43;
                        resword = "1b9716d6632f84904bc7d4fcfb8289dc";
                            goto compare;
                          case 2875:
                            so=107;
                        resword = "c5c4c4c2294c232ab4ebc6e60bbab4e9";
                            goto compare;
                          case 2878:
                            so=7;
                        resword = "eab9f4600f9e4007b1e3410dbf830b5a";
                            goto compare;
                          case 2882:
                            so=316;
                        resword = "be138071362cbbf32f114380931f7218";
                            goto compare;
                          case 2891:
                            so=268;
                        resword = "c68b715471ef2e0ba6e449ae34f2cf33";
                            goto compare;
                          case 2929:
                            so=136;
                        resword = "c5e914e327561776796c510d2d3d04a9";
                            goto compare;
                          case 2936:
                            so=110;
                        resword = "10bb841d7c4274f7b06a19b167afb137";
                            goto compare;
                          case 2941:
                            so=278;
                        resword = "14be2f0a5f85b125750ef3c02c6e634b";
                            goto compare;
                          case 2965:
                            so=69;
                        resword = "26590dee188ec019e6964f2b64df5d6f";
                            goto compare;
                          case 2977:
                            so=62;
                        resword = "b15db07349a896111428fb548f5bcd61";
                            goto compare;
                          case 2984:
                            so=96;
                        resword = "06cf9b2f8b803750e557425bf7fb28f9";
                            goto compare;
                          case 3025:
                            so=280;
                        resword = "717f3b7cb53fb9683bcd0d562d293b65";
                            goto compare;
                          case 3077:
                            so=361;
                        resword = "00ef219a61bdca3f3dba43ad9a876e13";
                            goto compare;
                          case 3082:
                            so=140;
                        resword = "0aae401d652f6f27db521d37e346efbc";
                            goto compare;
                          case 3108:
                            so=281;
                        resword = "c5a4b643009ecab5befe5d45957a3dc5";
                            goto compare;
                          case 3341:
                            so=252;
                        resword = "2bcfca94ba548444d246d9b3fe324f29";
                            goto compare;
                          case 3360:
                            so=67;
                        resword = "b745b0d8d62c1387f0b5b0bef7e70ed4";
                            goto compare;
                          case 3362:
                            so=123;
                        resword = "4d8f671416075263aa310298e0eae70d";
                            goto compare;
                          case 3404:
                            so=218;
                        resword = "b5089da6203bea2948f766ce32360f7a";
                            goto compare;
                          case 3406:
                            so=99;
                        resword = "b65e1738d2e66fba5dcede69ecaffe67";
                            goto compare;
                          case 3415:
                            so=71;
                        resword = "be0741993b3ef82d3cb00a55bcc4c0ef";
                            goto compare;
                          case 3443:
                            so=324;
                        resword = "11b4797bce1efe5be3fdc2c7510e97ff";
                            goto compare;
                          case 3448:
                            so=284;
                        resword = "0ec9290e81fdba50ed8bb1be01b838bc";
                            goto compare;
                          case 3532:
                            so=355;
                        resword = "af996938a16b60a2b42e391cf243bdfb";
                            goto compare;
                          case 3533:
                            so=271;
                        resword = "c589f5c666e58e26e23b3647b509ae19";
                            goto compare;
                          case 3535:
                            so=315;
                        resword = "b62c86844f882fd3b944c58929ab8f49";
                            goto compare;
                          case 3579:
                            so=26;
                        resword = "c3b972719cb822c28e53b050e0f65c98";
                            goto compare;
                          case 3581:
                            so=66;
                        resword = "ebff88a3e9206ce3ba665a7ef9f6d608";
                            goto compare;
                          case 3660:
                            so=318;
                        resword = "02293a7f48fba34e8b5434dffa629966";
                            goto compare;
                          case 3661:
                            so=72;
                        resword = "b9fec1bdcbc54d8f39fe9b1b34b65583";
                            goto compare;
                          case 3701:
                            so=255;
                        resword = "bec846ee74711472d432643a77143580";
                            goto compare;
                          case 3793:
                            so=291;
                        resword = "b295ddb0893ead10a5c8d2ae22e4299a";
                            goto compare;
                          case 3823:
                            so=246;
                        resword = "b6fbeb47bc9bb5f6a2814685d46ffa68";
                            goto compare;
                          case 3830:
                            so=75;
                        resword = "ba36dbe196dbbd6b8b19394bcd02b54c";
                            goto compare;
                          case 3898:
                            so=284;
                        resword = "b75b0e0bda1b9a89a0e2481635af89fd";
                            goto compare;
                          case 3915:
                            so=146;
                        resword = "7d7f8f059c8f44d8e9c2d8b0681659fe";
                            goto compare;
                          case 3940:
                            so=159;
                        resword = "21994909447264dda3d8d9919e60b766";
                            goto compare;
                          case 3944:
                            so=349;
                        resword = "c30f6bf9f104edfa98774bb42e7d467c";
                            goto compare;
                          case 3970:
                            so=193;
                        resword = "1d72bc807caf4b13e55fcbc0673f13cf";
                            goto compare;
                          case 3988:
                            so=200;
                        resword = "16ae23ff2dccab419500f0515615c9b0";
                            goto compare;
                          case 4040:
                            so=144;
                        resword = "b555f974045f9abee9a87dec2ed8d5d5";
                            goto compare;
                          case 4084:
                            so=331;
                        resword = "c57bca482fcf3041b54c349501ee375c";
                            goto compare;
                          case 4104:
                            so=352;
                        resword = "10b9a8b2dcd081cf0eaa424ede725c34";
                            goto compare;
                          case 4136:
                            so=98;
                        resword = "01495db0c2dd1902fb97bf0c3161c0ed";
                            goto compare;
                          case 4142:
                            so=67;
                        resword = "0e99c33ad52e087d563d442b7c763621";
                            goto compare;
                          case 4159:
                            so=45;
                        resword = "01df4409d44aefdcd7390f4e6e68e7bd";
                            goto compare;
                          case 4188:
                            so=235;
                        resword = "137946c03ae6f639e7ebc0fe79ac7500";
                            goto compare;
                          case 4195:
                            so=25;
                        resword = "ba5631c339ebee90f9522db02494b58e";
                            goto compare;
                          case 4221:
                            so=97;
                        resword = "c91e13c29c6f5d26c924a81c06e36383";
                            goto compare;
                          case 4395:
                            so=344;
                        resword = "bec7478e8d8b2d1c888e423562d96361";
                            goto compare;
                          case 4520:
                            so=198;
                        resword = "b4be422b909a73ade71e280dab9769c9";
                            goto compare;
                          case 4534:
                            so=15;
                        resword = "1be9f9427ca938c220575212b01ac47a";
                            goto compare;
                          case 4649:
                            so=345;
                        resword = "188f9dc900c1d847077101e0913ea08d";
                            goto compare;
                          case 4669:
                            so=202;
                        resword = "191fcab9e2487ee62e4ac61bf339816d";
                            goto compare;
                          case 4694:
                            so=78;
                        resword = "17efd06a3e898d3a4bcaf62e80b980b2";
                            goto compare;
                          case 4696:
                            so=330;
                        resword = "b818fcd0b07c036dfc8dd111aca38fa7";
                            goto compare;
                          case 4714:
                            so=106;
                        resword = "15ffdf992e3abbc957967a176fc2311c";
                            goto compare;
                          case 4752:
                            so=314;
                        resword = "aa9f8b7224be8b8fbd5f008471e3b8c7";
                            goto compare;
                          case 4805:
                            so=33;
                        resword = "0b8fded92f6a7e73f43cbdb080e82ba4";
                            goto compare;
                          case 4811:
                            so=147;
                        resword = "bfa9583f1908d6540d363d5788a8ccd4";
                            goto compare;
                          case 4838:
                            so=102;
                        resword = "1f6f0b7fd241710bc99f9b828e43b191";
                            goto compare;
                          case 4897:
                            so=113;
                        resword = "c1c93c64151d38de634d20f020b0181c";
                            goto compare;
                          case 4913:
                            so=126;
                        resword = "2defb9c83f1b1f87cb3609a2d6828423";
                            goto compare;
                          case 4914:
                            so=86;
                        resword = "12efd37f03829e1f235f738e5ec9c241";
                            goto compare;
                          case 4948:
                            so=187;
                        resword = "be8819e3df1c2c529ffe4fee029ebc5f";
                            goto compare;
                          case 5092:
                            so=251;
                        resword = "bee0b8c6bcef6534ef4dc7d55929b8c6";
                            goto compare;
                          case 5131:
                            so=183;
                        resword = "ba29093755f1a00ede3a705f641f00b9";
                            goto compare;
                          case 5158:
                            so=258;
                        resword = "031f3ce2fb6fa0e796c2a319ad1315a1";
                            goto compare;
                          case 5249:
                            so=183;
                        resword = "10a9c897c3f49f9f876c18b6289ddcd1";
                            goto compare;
                          case 5681:
                            so=197;
                        resword = "1d2e7188118600c8ad9eb3247a06f5d7";
                            goto compare;
                          case 5779:
                            so=99;
                        resword = "bc899ea6688707908b7228f6660f6b5a";
                            goto compare;
                          case 5793:
                            so=253;
                        resword = "baee258fdf9eccbcd8a512e8bedad6cb";
                            goto compare;
                          case 5875:
                            so=285;
                        resword = "045f312bd33f73cc67d3a27702322fb5";
                            goto compare;
                          case 6036:
                            so=28;
                        resword = "baaf2dccaa947acd189e966b0aabd7c7";
                            goto compare;
                          case 6121:
                            so=142;
                        resword = "16099c83923c29758817e1e388483d8b";
                            goto compare;
                          case 6174:
                            so=204;
                        resword = "126f250229185ac9ff0d75a511cd6e79";
                            goto compare;
                          case 6205:
                            so=196;
                        resword = "ba6e23a9119cca778b6c074aaa469379";
                            goto compare;
                          case 6631:
                            so=331;
                        resword = "b8ee980fbc9bd7a4f7fd9dc9a1a9db11";
                            goto compare;
                          case 6682:
                            so=16;
                        resword = "c84fb2b776c7be34bd01491c75e03484";
                            goto compare;
                          case 6693:
                            so=30;
                        resword = "1e99017c31fc129a951a4a6a2ed5704a";
                            goto compare;
                          case 6697:
                            so=254;
                        resword = "c93f8a16ced17a0eb9124aada1406c07";
                            goto compare;
                          case 6757:
                            so=45;
                        resword = "cb49c566241f50629348c702363df6ed";
                            goto compare;
                          case 6845:
                            so=260;
                        resword = "11dfbfcd6d096c53604049c42fe8e3a8";
                            goto compare;
                          case 6973:
                            so=57;
                        resword = "b45f2f1f5119d480ed078e4f0c7ac441";
                            goto compare;
                          case 7394:
                            so=214;
                        resword = "bb6f53b64105fc5c9e271a6652bad0fd";
                            goto compare;
                          case 7399:
                            so=115;
                        resword = "b63faaa4ac6af891f5ba11071accb6ad";
                            goto compare;
                          case 8101:
                            so=227;
                        resword = "be99d0f4c5432e23a1863411efe91b07";
                            goto compare;
                          case 8242:
                            so=233;
                        resword = "cb4feb78a93f3e49745ac2ec4f435d73";
                            goto compare;
                          case 8884:
                            so=20;
                        resword = "103f0b5e6ecf65ca696f0a43179a46ac";
                            goto compare;
                        }
                    }
                }
            }
          return -1;
        compare:
          if (*str == *resword && !strncmp (str + 1, resword + 1, len - 1) && resword[len] == '\0')
            return scores[so];
        }
    }
  return -1;
}
