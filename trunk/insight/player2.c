/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf --compare-strncmp --seven-bit --readonly-tables --enum --pic --includes --hash-function-name=player2_hash --lookup-function-name=player2_score --language=ANSI-C --switch=5 ./export/hashes2.txt  */
/* Computed positions: -k'1-4,19' */

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
static int scores[419] = {
    0,
    0,
    25,
    0,
    5,
    3,
    1,
    2,
    1,
    509,
    65,
    63,
    61,
    59,
    57,
    55,
    53,
    51,
    49,
    282,
    45,
    43,
    518,
    5,
    3,
    1,
    9,
    7,
    5,
    3,
    1,
    5,
    3,
    1,
    9,
    8,
    7,
    6,
    5,
    4,
    3,
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
    235,
    233,
    231,
    229,
    513,
    511,
    509,
    507,
    505,
    503,
    501,
    499,
    497,
    495,
    493,
    535,
    531,
    527,
    523,
    519,
    515,
    511,
    1184,
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
    65,
    63,
    61,
    59,
    56,
    54,
    52,
    50,
    48,
    46,
    257,
    255,
    253,
    251,
    249,
    247,
    245,
    200,
    200,
    200,
    200,
    200,
    118,
    124,
    0,
    246,
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
    260,
    18,
    16,
    14,
    12,
    10,
    8,
    6,
    4,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    0,
    9,
    8,
    7,
    6,
    5,
    513,
    511,
    509,
    507,
    505,
    503,
    501,
    499,
    497,
    495,
    493,
    491,
    489,
    487,
    485,
    483,
    481,
    479,
    9,
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
    1,
    1,
    1,
    1,
    1,
    1,
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
    129,
    127,
    125,
    123,
    121,
    119,
    117,
    115,
    113,
    111,
    109,
    107,
    105,
    103,
    101,
    99,
    97,
    95,
    93,
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
    2,
    1,
    2,
    1,
    1,
    1,
    6,
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
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
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
    116,
    5,
    4,
    3,
    2,
    1,
    1,
    1,
    1,
    129,
    127,
    125,
    123,
    121,
    119,
    117,
    65,
    63,
    61,
    59,
    57,
    55,
    53,
    51,
    49,
    47,
    45,
    43,
    41,
    39,
    37,
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
    0,
    0,
    0,
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
    1,
    1,
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
    1,
    1,
    1,
    1,
    1,
    0
};

/* maximum key range = 23921, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
player2_hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,  5991,  3617,
       3468,  6706,   100,   475,    65,    40,    15,     5,   135,   711,
         10,    20,    60,     0,     5,  1707,   145,  1230,    27,   395,
       1258, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978,  2393,  1779,  6554,
       4496,   295,   850,  1510,  1820,   247,  1242,  7586,  5451,  7151,
         29,     2,  1690,   630,  1390,  5091, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978, 23978,
      23978
    };
  return len + asso_values[(unsigned char)str[18]] + asso_values[(unsigned char)str[3]+12] + asso_values[(unsigned char)str[2]+6] + asso_values[(unsigned char)str[1]+4] + asso_values[(unsigned char)str[0]+13];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
int player2_score (register const char *str, register unsigned int len)
{
  int so=0;
  enum
    {
      TOTAL_KEYWORDS = 1673,
      MIN_WORD_LENGTH = 32,
      MAX_WORD_LENGTH = 32,
      MIN_HASH_VALUE = 57,
      MAX_HASH_VALUE = 23977
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = player2_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          register const char *resword;

          if (key < 3872)
            {
              if (key < 2069)
                {
                  switch (key - 57)
                    {
                      case 0:
                        so=83;
                        resword = "2893b8586de35d9f968e3b02dfab1c60";
                        goto compare;
                      case 2:
                        so=404;
                        resword = "b8903b4c14f2d36df494c958d68367c5";
                        goto compare;
                      case 12:
                        so=359;
                        resword = "b934f6719a037378ff9b4e1ec1cbe84c";
                        goto compare;
                      case 25:
                        so=132;
                        resword = "396353e155cca3d4de80ad4d4e5e2038";
                        goto compare;
                      case 34:
                        so=235;
                        resword = "a534548658873eeedf8951febc31172a";
                        goto compare;
                      case 50:
                        so=355;
                        resword = "346420b8953ac9ef387d02b724fde43c";
                        goto compare;
                      case 69:
                        so=175;
                        resword = "096b7165ff3bcb1c0c8b17b22322b5e6";
                        goto compare;
                      case 79:
                        so=147;
                        resword = "a503e3e8b3bef5993898c450f1a3f452";
                        goto compare;
                      case 80:
                        so=296;
                        resword = "04328c63865d90d1129afb71d88d5843";
                        goto compare;
                      case 90:
                        so=363;
                        resword = "031079e4bdffe52cf992b5cc1cac225c";
                        goto compare;
                      case 92:
                        so=306;
                        resword = "b81240f4ec0a79bbc69d128b8b254302";
                        goto compare;
                      case 94:
                        so=351;
                        resword = "b908c2fccdf24fe62b993cd3156bf37a";
                        goto compare;
                      case 95:
                        so=401;
                        resword = "3833462e07967177f44606bbe29e5f4e";
                        goto compare;
                      case 104:
                        so=321;
                        resword = "a9009d7702a1cba0979c9ce52895e5f4";
                        goto compare;
                      case 105:
                        so=360;
                        resword = "30631a68647530309e8bf7692bbfe56d";
                        goto compare;
                      case 106:
                        so=73;
                        resword = "a378272a110b41e5d9896e8fef53eb50";
                        goto compare;
                      case 107:
                        so=132;
                        resword = "2398f51080a65af050601b212e3a3cee";
                        goto compare;
                      case 109:
                        so=110;
                        resword = "b58c4a26c5a2c7f4d56b2517e6f61ea7";
                        goto compare;
                      case 115:
                        so=171;
                        resword = "1320bd821b2b009923857cb6bde795e8";
                        goto compare;
                      case 119:
                        so=155;
                        resword = "a5041fbfa8668d5fee72237544bbb708";
                        goto compare;
                      case 120:
                        so=86;
                        resword = "240370647ea4d127146dbf85d52bfdeb";
                        goto compare;
                      case 130:
                        so=296;
                        resword = "19929f42dbdcef36ce84ec71e9c07928";
                        goto compare;
                      case 141:
                        so=66;
                        resword = "788b2f12b44573a01874ba1a66fa4e43";
                        goto compare;
                      case 155:
                        so=250;
                        resword = "1064a28d64cdec5b3b94fddbe4de9c6f";
                        goto compare;
                      case 161:
                        so=213;
                        resword = "b02b5f6a01356d6edc7d0212e4ab19ce";
                        goto compare;
                      case 165:
                        so=50;
                        resword = "3466bd2e87be55f9958af9c363343244";
                        goto compare;
                      case 169:
                        so=8;
                        resword = "b448ab116c10f881478627e7ff80962f";
                        goto compare;
                      case 170:
                        so=410;
                        resword = "5424292fe3f1239e18845722549349e2";
                        goto compare;
                      case 177:
                        so=266;
                        resword = "b383fe4fccb49df5294283ee0118e336";
                        goto compare;
                      case 179:
                        so=386;
                        resword = "a441a6a1feaafa64009271caf55caa9d";
                        goto compare;
                      case 180:
                        so=330;
                        resword = "0822384f816bc28c7b44015c94f8072c";
                        goto compare;
                      case 182:
                        so=66;
                        resword = "b512384c3e3972e6c14bbdb14d4c7d2e";
                        goto compare;
                      case 184:
                        so=48;
                        resword = "084b3d7d3d860028508a20b4589179c9";
                        goto compare;
                      case 185:
                        so=121;
                        resword = "2621efae4a574286167a8870b9e16283";
                        goto compare;
                      case 187:
                        so=302;
                        resword = "321c780b8be6e9fd2c41fde52b527b26";
                        goto compare;
                      case 195:
                        so=60;
                        resword = "06316fa82fd88829dc768107bbe5a858";
                        goto compare;
                      case 200:
                        so=277;
                        resword = "10313012e812436fe37bf778acdfc1be";
                        goto compare;
                      case 210:
                        so=11;
                        resword = "100455f6cefe8c063a97d1d3cb2bc740";
                        goto compare;
                      case 212:
                        so=274;
                        resword = "0288601a90a7c80ac66c8ae6add6ee75";
                        goto compare;
                      case 215:
                        so=76;
                        resword = "261341c256cfce62c16689ba927c5737";
                        goto compare;
                      case 217:
                        so=198;
                        resword = "75960a9d88a7d045666825f1ca2276c4";
                        goto compare;
                      case 220:
                        so=72;
                        resword = "363362cfaad4ac1ddd49fc541384c790";
                        goto compare;
                      case 227:
                        so=264;
                        resword = "b342b823812dd2dfae897d868877ee8e";
                        goto compare;
                      case 234:
                        so=327;
                        resword = "754820fa3a57927ab3657918ac1a4c86";
                        goto compare;
                      case 245:
                        so=108;
                        resword = "00406d1e69215105e1969ad5d2683350";
                        goto compare;
                      case 249:
                        so=0;
                        resword = "be91268b0976a19af5926ce99bfc968c";
                        goto compare;
                      case 252:
                        so=209;
                        resword = "7844d10b874f34336a44ec5609475b65";
                        goto compare;
                      case 254:
                        so=273;
                        resword = "020bbe254d1f6b3ec34c533b86e8165d";
                        goto compare;
                      case 264:
                        so=173;
                        resword = "b5c11e9fa63f1e4de38c4d1d643d72ae";
                        goto compare;
                      case 265:
                        so=118;
                        resword = "36437b39c6adf7336483c82cd5ddc514";
                        goto compare;
                      case 274:
                        so=378;
                        resword = "be90c6ef2478f6a97f74392486e45324";
                        goto compare;
                      case 290:
                        so=136;
                        resword = "3a6304a7b5c7552bf39baa5fe23a8144";
                        goto compare;
                      case 305:
                        so=158;
                        resword = "3002b1deab839fa4fa4ef4c3b664cc41";
                        goto compare;
                      case 316:
                        so=396;
                        resword = "ba9b2aec2b5f65e2d5820d882c643a76";
                        goto compare;
                      case 324:
                        so=408;
                        resword = "a066d0bb28d5c04eb562d7733ea5c40d";
                        goto compare;
                      case 327:
                        so=162;
                        resword = "b036c81761047982ed4245f900e0269a";
                        goto compare;
                      case 330:
                        so=124;
                        resword = "16114c444d53c7666b4ab5c1007c163b";
                        goto compare;
                      case 339:
                        so=256;
                        resword = "7e3135e54c1383b74c62ce3373b20a92";
                        goto compare;
                      case 347:
                        so=52;
                        resword = "b642a0d62355e8009b71219100fb0fe1";
                        goto compare;
                      case 352:
                        so=81;
                        resword = "5608768547f20a1de8976b6172b87d32";
                        goto compare;
                      case 355:
                        so=163;
                        resword = "582663df1e7e9047e06a3c391891c4f7";
                        goto compare;
                      case 365:
                        so=224;
                        resword = "2a61b6217aaaf6e6216d8e4af11dc452";
                        goto compare;
                      case 370:
                        so=102;
                        resword = "2981df80d74e08c27dea4318797b8e74";
                        goto compare;
                      case 372:
                        so=269;
                        resword = "248803965b25c9bdcce54996fe5997bb";
                        goto compare;
                      case 392:
                        so=92;
                        resword = "856c7e00b86852246c922a412b68c968";
                        goto compare;
                      case 397:
                        so=349;
                        resword = "3e66bc3023a65e1de38841e75058073c";
                        goto compare;
                      case 399:
                        so=320;
                        resword = "098b2dac344c19b8bae230cca083956d";
                        goto compare;
                      case 400:
                        so=275;
                        resword = "50443344a33d676e7279e3d90e18cf54";
                        goto compare;
                      case 402:
                        so=351;
                        resword = "b2847f9286c3610f98ee7d9026bfc363";
                        goto compare;
                      case 404:
                        so=93;
                        resword = "ba3812f142f92d2e8f465e427dc4a322";
                        goto compare;
                      case 406:
                        so=247;
                        resword = "aa1c1c8fd973e58b696459a0fe25acf6";
                        goto compare;
                      case 411:
                        so=229;
                        resword = "a6c1316d73d953eeaf99a1124e468c9a";
                        goto compare;
                      case 414:
                        so=192;
                        resword = "aa64dbc45232bbfc80490320d96cec19";
                        goto compare;
                      case 415:
                        so=289;
                        resword = "569628f7d81c34ad3b8a9bbe921cfd8a";
                        goto compare;
                      case 416:
                        so=207;
                        resword = "a3c256b280f7e64c0a6a07ccc947d231";
                        goto compare;
                      case 445:
                        so=71;
                        resword = "3004b753b7b3bf2438e7adb39279b36f";
                        goto compare;
                      case 452:
                        so=228;
                        resword = "3e06bd2310f62e9991875b4d74a80a71";
                        goto compare;
                      case 454:
                        so=344;
                        resword = "553bb5708d14eda2e7e3ff76a37e4a56";
                        goto compare;
                      case 460:
                        so=66;
                        resword = "5044a2ef48a1effd2645cd667e05230f";
                        goto compare;
                      case 465:
                        so=85;
                        resword = "1869d6345b893cf37d84264b51651f9c";
                        goto compare;
                      case 484:
                        so=157;
                        resword = "be267754a51f970edb4c518fabee6acc";
                        goto compare;
                      case 490:
                        so=289;
                        resword = "0909b7b1217e6afd78837fb5db877b13";
                        goto compare;
                      case 495:
                        so=53;
                        resword = "22799d23e2de57835c781104a51798e5";
                        goto compare;
                      case 500:
                        so=19;
                        resword = "8873c157751b9d0b444b8b42dcde3938";
                        goto compare;
                      case 507:
                        so=106;
                        resword = "8038886314b1ff2592951cbff684b2d3";
                        goto compare;
                      case 515:
                        so=318;
                        resword = "839426c028fc9d32904257bd9fa21d6c";
                        goto compare;
                      case 517:
                        so=3;
                        resword = "52c1d7c7dc20b28348637c6f6ad83972";
                        goto compare;
                      case 520:
                        so=306;
                        resword = "33399563e0192911854d77b260df59d8";
                        goto compare;
                      case 522:
                        so=143;
                        resword = "5988e84cb3dd6f7f71e9f5f3e2753742";
                        goto compare;
                      case 525:
                        so=186;
                        resword = "1329db9060453bf94f730f927f2e7c16";
                        goto compare;
                      case 527:
                        so=293;
                        resword = "862cf497671d6382bc9ce8e93cf9a2ba";
                        goto compare;
                      case 532:
                        so=1;
                        resword = "781460ad01200e38645979f2d6a6070a";
                        goto compare;
                      case 540:
                        so=365;
                        resword = "2120e5f7ea562779c96563b8288700cc";
                        goto compare;
                      case 547:
                        so=271;
                        resword = "730638d4e1b6ea4e01e7b55bf458d436";
                        goto compare;
                      case 548:
                        so=283;
                        resword = "a39b19a36c9778522751a77451da8d98";
                        goto compare;
                      case 565:
                        so=315;
                        resword = "5443eb328dcd9be99ee0386d5abbd448";
                        goto compare;
                      case 572:
                        so=387;
                        resword = "3e104d11d2b33a1da4e4fdbbb9443364";
                        goto compare;
                      case 580:
                        so=264;
                        resword = "1849262f6fcc52d15696cf5f9443c5f0";
                        goto compare;
                      case 595:
                        so=399;
                        resword = "1462d4ea1d1ce0c45156c8c23f517105";
                        goto compare;
                      case 602:
                        so=329;
                        resword = "0a2c589f1f1f47fd84ed9cd2697556e6";
                        goto compare;
                      case 610:
                        so=415;
                        resword = "098229c59b29932fac52da9a96b8aeac";
                        goto compare;
                      case 612:
                        so=356;
                        resword = "b196d0c8b5e3ff24118bfc990b319d6e";
                        goto compare;
                      case 627:
                        so=173;
                        resword = "ba83e5bee44c48e94dea8727d7bd41fa";
                        goto compare;
                      case 650:
                        so=104;
                        resword = "1346faacf0e9ff11f5e5686412f91a87";
                        goto compare;
                      case 670:
                        so=133;
                        resword = "523468329ad293b117529beb4b344c8b";
                        goto compare;
                      case 672:
                        so=211;
                        resword = "7141a471458c00997774e69c1e5cd868";
                        goto compare;
                      case 680:
                        so=287;
                        resword = "1080b85173ce36c76e5aca2cc7f021ff";
                        goto compare;
                      case 685:
                        so=328;
                        resword = "3a990238df532fe25a8a15ff2bfc3db5";
                        goto compare;
                      case 690:
                        so=380;
                        resword = "d571b9bcdebb906ec3783e6bfff8938e";
                        goto compare;
                      case 692:
                        so=150;
                        resword = "7a1246aaea6aa3ff3aeab3d7cacefb36";
                        goto compare;
                      case 695:
                        so=78;
                        resword = "1610fcb6d9434d75a65a90e017afe6fe";
                        goto compare;
                      case 705:
                        so=47;
                        resword = "237e45ed2923f7a4597df2f3aeef2f5e";
                        goto compare;
                      case 715:
                        so=310;
                        resword = "d39437f14deba0afd462361e0ba09944";
                        goto compare;
                      case 731:
                        so=2;
                        resword = "75ccc835fdc6943b4a526e86cd92cd48";
                        goto compare;
                      case 735:
                        so=58;
                        resword = "242e703434916287ca4ce1b5a2eb17f8";
                        goto compare;
                      case 757:
                        so=12;
                        resword = "82980d5256eb4ce96bea12f98613bf77";
                        goto compare;
                      case 760:
                        so=73;
                        resword = "273b2f565811f74070766da069428739";
                        goto compare;
                      case 763:
                        so=204;
                        resword = "b790690425dd4d4f9864e0184ebbab7b";
                        goto compare;
                      case 770:
                        so=325;
                        resword = "2120e89544ccdecc7aefb1eec21ca087";
                        goto compare;
                      case 774:
                        so=76;
                        resword = "72c978f41f7e24dec5616b0b753b442d";
                        goto compare;
                      case 775:
                        so=172;
                        resword = "5a03075c17073524dbeb9e34ef48bff5";
                        goto compare;
                      case 778:
                        so=111;
                        resword = "070cf018159c1ddfb59157355f4e2477";
                        goto compare;
                      case 780:
                        so=122;
                        resword = "d936cb6e48593d95b29d6415979174c8";
                        goto compare;
                      case 785:
                        so=293;
                        resword = "551600a7b128a63cb259cd86229e776a";
                        goto compare;
                      case 790:
                        so=169;
                        resword = "546e4cae9ea6ab51bb8a49d421ffb107";
                        goto compare;
                      case 805:
                        so=24;
                        resword = "211117d65271e8e15eea8a6ace0fadb1";
                        goto compare;
                      case 807:
                        so=12;
                        resword = "53c9f2dee1986cc84e95d239f7f559e7";
                        goto compare;
                      case 808:
                        so=407;
                        resword = "372c450573991f012e467d89d563f864";
                        goto compare;
                      case 822:
                        so=404;
                        resword = "b122ff178660b7770ee7e671c7bdabd9";
                        goto compare;
                      case 825:
                        so=161;
                        resword = "a054e570a40631cef89903cc48ec8b1d";
                        goto compare;
                      case 830:
                        so=393;
                        resword = "82127d2cd5eb8c8ee5e24740361f991a";
                        goto compare;
                      case 835:
                        so=373;
                        resword = "8a7698b138d9b425ea92d3c9fc810415";
                        goto compare;
                      case 838:
                        so=161;
                        resword = "579c902aac046df9f091e99a6903a0b7";
                        goto compare;
                      case 839:
                        so=303;
                        resword = "a1320c5027f65b9911ec78a2d7608eb2";
                        goto compare;
                      case 851:
                        so=118;
                        resword = "a1c29c14368a09e7846a86a9fec5b580";
                        goto compare;
                      case 855:
                        so=182;
                        resword = "359118baaeb9f1abf6fd2d7446cfd5a1";
                        goto compare;
                      case 865:
                        so=387;
                        resword = "3930e8c5b98c1a970bf2a2fe0eaa99cc";
                        goto compare;
                      case 872:
                        so=52;
                        resword = "d60c0c20266d64bec06a54dbe8669081";
                        goto compare;
                      case 877:
                        so=174;
                        resword = "b334851d6864568008f4f079e076afb8";
                        goto compare;
                      case 887:
                        so=336;
                        resword = "74737784883d649c3ff5ece66dcf4d66";
                        goto compare;
                      case 905:
                        so=309;
                        resword = "0a4458bf467861fbb85a21ad13fbe067";
                        goto compare;
                      case 920:
                        so=142;
                        resword = "004944b7bda3b63128e062e53402dca2";
                        goto compare;
                      case 923:
                        so=219;
                        resword = "76503c1ce509120dcd693a5aaa7c7369";
                        goto compare;
                      case 935:
                        so=25;
                        resword = "083e9b9662fc57f470e1258ac69c26ea";
                        goto compare;
                      case 939:
                        so=410;
                        resword = "a984ef86041564d35ffe27247d890d93";
                        goto compare;
                      case 940:
                        so=46;
                        resword = "202333b23cc9eefd59f11d0daf075cad";
                        goto compare;
                      case 954:
                        so=397;
                        resword = "de88521f23e08eb87f89c9c1c2ba16ac";
                        goto compare;
                      case 959:
                        so=240;
                        resword = "ab13e71cf5c3b62f7c6ee90179b15584";
                        goto compare;
                      case 960:
                        so=345;
                        resword = "3b701dac8fffb83f9a47ef67f292595a";
                        goto compare;
                      case 972:
                        so=253;
                        resword = "b27259176830fddb89ff40103b4c58ea";
                        goto compare;
                      case 990:
                        so=236;
                        resword = "069054c9afd560a761fd3d93dfc85691";
                        goto compare;
                      case 997:
                        so=106;
                        resword = "58c6e62c7ae48815195407d1c8a5e0ae";
                        goto compare;
                      case 1000:
                        so=314;
                        resword = "862469d9f4f60c3e355de12d566c11fd";
                        goto compare;
                      case 1015:
                        so=51;
                        resword = "251637b288dda37ff6fc337e1e4ee7bc";
                        goto compare;
                      case 1017:
                        so=161;
                        resword = "551c2c61b3bd4742dafaa13d6c9534a6";
                        goto compare;
                      case 1025:
                        so=285;
                        resword = "33496c0f726fb2e01f50793429633629";
                        goto compare;
                      case 1027:
                        so=141;
                        resword = "77ccdcb0256fc4796268667dc6db55c4";
                        goto compare;
                      case 1029:
                        so=227;
                        resword = "d6c889b11a049b626c8b2a663d5bd84b";
                        goto compare;
                      case 1040:
                        so=366;
                        resword = "18402893eba97c75fff3456e5cedb7a6";
                        goto compare;
                      case 1045:
                        so=181;
                        resword = "8603c89c9e8e3fcfd25ceb8b1b040907";
                        goto compare;
                      case 1050:
                        so=239;
                        resword = "0604f83d3d493cc47bf5fd20b4fbb217";
                        goto compare;
                      case 1065:
                        so=262;
                        resword = "814150735038e2372363d2bbe9747ce6";
                        goto compare;
                      case 1074:
                        so=272;
                        resword = "d84be3b7b8317aa577e44e39ebf40783";
                        goto compare;
                      case 1083:
                        so=207;
                        resword = "772240446d440c5adbe6f1755b91bb89";
                        goto compare;
                      case 1089:
                        so=394;
                        resword = "2b4b46a76c2e7b069c4ab6331f401478";
                        goto compare;
                      case 1102:
                        so=263;
                        resword = "28c9b97a2c143468255cd8ff00297857";
                        goto compare;
                      case 1103:
                        so=17;
                        resword = "b459c390d3d8e7c6dd98ef5ecb5c048b";
                        goto compare;
                      case 1115:
                        so=59;
                        resword = "312e95289d78138eb98784bd47039037";
                        goto compare;
                      case 1120:
                        so=162;
                        resword = "5623703b0ad32bbc90f8cfb6fa533725";
                        goto compare;
                      case 1125:
                        so=105;
                        resword = "2b945f2caea5adc6e7ea5d5ad4b94c47";
                        goto compare;
                      case 1140:
                        so=210;
                        resword = "593675cd067753f9ddfbfd21a8a5e732";
                        goto compare;
                      case 1141:
                        so=1;
                        resword = "845434cd117001b26277112fe78fc1b0";
                        goto compare;
                      case 1157:
                        so=199;
                        resword = "bb21db1c34141e3de0ec6fdb2f767dbf";
                        goto compare;
                      case 1159:
                        so=77;
                        resword = "1e98e8d4f1ce22dffefdc259bda1d063";
                        goto compare;
                      case 1168:
                        so=369;
                        resword = "b356ef02cf03079ccceffeb9da10e63b";
                        goto compare;
                      case 1170:
                        so=84;
                        resword = "867eb920610cdde7708f9e886ff65160";
                        goto compare;
                      case 1188:
                        so=6;
                        resword = "b774f3a290cece17a056c111859b042f";
                        goto compare;
                      case 1219:
                        so=145;
                        resword = "01c8fdf7c6e0c3ab2059a28e601ea4d4";
                        goto compare;
                      case 1225:
                        so=375;
                        resword = "0b463dc0b6e7849c8846e8a7cd591fe5";
                        goto compare;
                      case 1231:
                        so=251;
                        resword = "2254b18ce399ed1dbb5d70f8812ce1ed";
                        goto compare;
                      case 1239:
                        so=216;
                        resword = "7e0e6a73ed0f3d7339ea950d0f629254";
                        goto compare;
                      case 1244:
                        so=122;
                        resword = "bf73fdfe3186b845cc97f83edf6f3a69";
                        goto compare;
                      case 1247:
                        so=221;
                        resword = "d118aa57289c5257824e97f36a84aca5";
                        goto compare;
                      case 1258:
                        so=272;
                        resword = "77622249edb2fa69135611ec3fd7fd14";
                        goto compare;
                      case 1260:
                        so=216;
                        resword = "6813dd3f407d6b8e5b9c699388754324";
                        goto compare;
                      case 1266:
                        so=332;
                        resword = "02591b7301b3d8abf24a01c98d1f3515";
                        goto compare;
                      case 1273:
                        so=119;
                        resword = "9560926c97e134602987143a30da44c4";
                        goto compare;
                      case 1275:
                        so=38;
                        resword = "1a7e322d7be2f433f1e68c90da7c553d";
                        goto compare;
                      case 1280:
                        so=326;
                        resword = "d87e4008908dbe3a10878cb63116c6b3";
                        goto compare;
                      case 1282:
                        so=377;
                        resword = "2f206c0a6bcddb91c171478ba83fb285";
                        goto compare;
                      case 1287:
                        so=5;
                        resword = "86c2a9d7b460c3b9e95cf27e3ae377e5";
                        goto compare;
                      case 1300:
                        so=95;
                        resword = "62302e8f0b04c610e18de28d1e6064ac";
                        goto compare;
                      case 1302:
                        so=131;
                        resword = "8e1e21474dec81621a88540396775c41";
                        goto compare;
                      case 1305:
                        so=353;
                        resword = "512eb6fe50d526ba7b68dd4e77251ec4";
                        goto compare;
                      case 1310:
                        so=182;
                        resword = "05092ef31ba22353e9f0d769896a16e3";
                        goto compare;
                      case 1314:
                        so=400;
                        resword = "829bc220e81b41c30bf459c6cd653360";
                        goto compare;
                      case 1320:
                        so=42;
                        resword = "0987a937f879f0603f82734ccc2efea9";
                        goto compare;
                      case 1327:
                        so=117;
                        resword = "6428582a1bcdfabf1569019d445d5bed";
                        goto compare;
                      case 1330:
                        so=372;
                        resword = "69132d53f7dc432d5467db852427eff0";
                        goto compare;
                      case 1331:
                        so=84;
                        resword = "79dc80ed1803553138697e522662d665";
                        goto compare;
                      case 1335:
                        so=195;
                        resword = "6990ab236a2dbea9a9421dc00309a9e9";
                        goto compare;
                      case 1340:
                        so=231;
                        resword = "137992cef912aed76affc085b3f39993";
                        goto compare;
                      case 1347:
                        so=238;
                        resword = "6068f182708774b4fb949a4403783fc4";
                        goto compare;
                      case 1350:
                        so=40;
                        resword = "d48e42038659f659f2763b23f48daf9e";
                        goto compare;
                      case 1352:
                        so=347;
                        resword = "7867a2df6349c8cf754c108e06ab7ab5";
                        goto compare;
                      case 1355:
                        so=16;
                        resword = "520e79eb53efbe00f1524bbffc322efa";
                        goto compare;
                      case 1370:
                        so=287;
                        resword = "5497b44f978675f8989c6e49f86b05d9";
                        goto compare;
                      case 1378:
                        so=217;
                        resword = "9821b8e2b09f977dca42eef40217dbd7";
                        goto compare;
                      case 1381:
                        so=330;
                        resword = "af2129e0a24c6731da4e8db4faf5f5fc";
                        goto compare;
                      case 1385:
                        so=290;
                        resword = "62647716f71777e79f47e27cb437de77";
                        goto compare;
                      case 1387:
                        so=327;
                        resword = "b0078e0cf784f20d3e804942bc3f642a";
                        goto compare;
                      case 1406:
                        so=18;
                        resword = "5746dd5c9f6e0db24de98468e1c0ab57";
                        goto compare;
                      case 1412:
                        so=224;
                        resword = "e87c8316016d0194db8df95baf28b1fb";
                        goto compare;
                      case 1423:
                        so=304;
                        resword = "7acb07f58640f5171efc7d0b23e59530";
                        goto compare;
                      case 1435:
                        so=377;
                        resword = "7e53c79fc66d0bda485f9f39c5b511db";
                        goto compare;
                      case 1438:
                        so=279;
                        resword = "920055f568a25116776e3f740d33a4a1";
                        goto compare;
                      case 1445:
                        so=256;
                        resword = "6671f370e6feabdaba6e60779cdb5160";
                        goto compare;
                      case 1448:
                        so=375;
                        resword = "7f4b1363afadfc16d570d18b6757d21a";
                        goto compare;
                      case 1452:
                        so=88;
                        resword = "5f7474e88556f4a83767dfaeeeab6a31";
                        goto compare;
                      case 1457:
                        so=326;
                        resword = "ae510390af0fef52f757fb45f16b5f05";
                        goto compare;
                      case 1460:
                        so=54;
                        resword = "514e3bbeea56e34fda479a1022f1894c";
                        goto compare;
                      case 1474:
                        so=313;
                        resword = "654b5883374cc447da47fbbf624d417d";
                        goto compare;
                      case 1480:
                        so=196;
                        resword = "e493a013fc3d97087247eefbb18ac194";
                        goto compare;
                      case 1491:
                        so=384;
                        resword = "ae377a8c96ef32a2d19a56ebbebf3e8a";
                        goto compare;
                      case 1492:
                        so=10;
                        resword = "920b163348888152c3456891ca4a481c";
                        goto compare;
                      case 1495:
                        so=236;
                        resword = "77c294e49eada66b765bee601ddc7c2e";
                        goto compare;
                      case 1507:
                        so=148;
                        resword = "30d65506282821daf37f063a23f34029";
                        goto compare;
                      case 1508:
                        so=130;
                        resword = "af484ea3f93d4d56324c5f6280f7367a";
                        goto compare;
                      case 1509:
                        so=366;
                        resword = "e80bb14eeebbaad0317c85393c44e076";
                        goto compare;
                      case 1510:
                        so=63;
                        resword = "25a4cd86bcb688b58483104521ad1403";
                        goto compare;
                      case 1516:
                        so=250;
                        resword = "535e50b18e813a39218fa80b38dc09d5";
                        goto compare;
                      case 1517:
                        so=84;
                        resword = "3f46b217aea1a8adfe81f7f038c71e5b";
                        goto compare;
                      case 1520:
                        so=184;
                        resword = "1b26e21d9f272010d95e4126b760f4a4";
                        goto compare;
                      case 1522:
                        so=342;
                        resword = "5f4170a7050866c78795c92c1aeb6f38";
                        goto compare;
                      case 1525:
                        so=287;
                        resword = "8b3480ef1c5f2e6e27e04f82d2ba75ec";
                        goto compare;
                      case 1530:
                        so=359;
                        resword = "812e42dd324d9bfa8e74614e74672034";
                        goto compare;
                      case 1533:
                        so=35;
                        resword = "9593bbee2a8a8d3d15e95471e33ab112";
                        goto compare;
                      case 1539:
                        so=326;
                        resword = "76d20573ad8139905e41026ba93197c9";
                        goto compare;
                      case 1540:
                        so=88;
                        resword = "24a3fdff881169ac3e754420980a1290";
                        goto compare;
                      case 1545:
                        so=110;
                        resword = "0827dd78203f46e14ee7a09eb09bf9d5";
                        goto compare;
                      case 1550:
                        so=244;
                        resword = "0c33db61d2869fe79e7b1d9739018f4d";
                        goto compare;
                      case 1555:
                        so=42;
                        resword = "9e928fb40c0a83cca28f65cb9f063f9e";
                        goto compare;
                      case 1556:
                        so=272;
                        resword = "38dba5a7025dd25157eb4acaee8ac165";
                        goto compare;
                      case 1561:
                        so=376;
                        resword = "6e0b978e5ed1e415bb8602ed7724328e";
                        goto compare;
                      case 1564:
                        so=92;
                        resword = "35ab28c20faec332ba7b6c7f1e67dd53";
                        goto compare;
                      case 1567:
                        so=176;
                        resword = "2bc9409e475ce6a06f4bbf11ed9dc74c";
                        goto compare;
                      case 1571:
                        so=319;
                        resword = "3761d8e8c91a98d83ffcd2ff9885d679";
                        goto compare;
                      case 1572:
                        so=391;
                        resword = "0c8ccb299d501fe14e950bbfaec7660e";
                        goto compare;
                      case 1575:
                        so=112;
                        resword = "d189eaa63eade207e37936a27bebd827";
                        goto compare;
                      case 1580:
                        so=312;
                        resword = "e24311ccb949eee66f80d4a346f1702b";
                        goto compare;
                      case 1585:
                        so=246;
                        resword = "3c81eee5b690bbf28789629d7160b749";
                        goto compare;
                      case 1592:
                        so=100;
                        resword = "e69880dfe257f803486c1fcf4efd95c3";
                        goto compare;
                      case 1595:
                        so=239;
                        resword = "e202d8301bb55e83827d8c5ae39b512e";
                        goto compare;
                      case 1597:
                        so=206;
                        resword = "763f9233feb86375976bf46683d045db";
                        goto compare;
                      case 1599:
                        so=107;
                        resword = "33abbc956e67b05e0b711233b726eb9b";
                        goto compare;
                      case 1607:
                        so=230;
                        resword = "8e0e98d4f77d7b96d7e1d78effa17622";
                        goto compare;
                      case 1608:
                        so=5;
                        resword = "9371ed7aaed86f0fbaeb4860f0ebf6c1";
                        goto compare;
                      case 1614:
                        so=104;
                        resword = "bad25755e9d70b94e576bae2d4937296";
                        goto compare;
                      case 1617:
                        so=115;
                        resword = "65c2e10093e14123224a6ef5508a72c7";
                        goto compare;
                      case 1620:
                        so=33;
                        resword = "93c2f923f3c68dbab175216135c21f83";
                        goto compare;
                      case 1622:
                        so=66;
                        resword = "3c382046c98265944041e49e78675e16";
                        goto compare;
                      case 1624:
                        so=144;
                        resword = "5fc0b00eed46f4c9c89723996c0595e0";
                        goto compare;
                      case 1625:
                        so=385;
                        resword = "300e3d39227da26da7f169d821842427";
                        goto compare;
                      case 1626:
                        so=144;
                        resword = "bfc2b6963d6e85bbdc45e0f10f0073e9";
                        goto compare;
                      case 1634:
                        so=40;
                        resword = "b9a801632178295f814bd493f143cc75";
                        goto compare;
                      case 1635:
                        so=151;
                        resword = "da0e9f8f9c64f60cc87f250ac777ad84";
                        goto compare;
                      case 1652:
                        so=300;
                        resword = "72a04ae3b168475a0a6b230ce00db43b";
                        goto compare;
                      case 1665:
                        so=76;
                        resword = "e042fd49d69d9cb60e9d144e7b3bd7f6";
                        goto compare;
                      case 1684:
                        so=65;
                        resword = "a6a18acf79d4c803928d926a58a6e1b9";
                        goto compare;
                      case 1689:
                        so=43;
                        resword = "bc483de073ce23fe84721c01ada6852f";
                        goto compare;
                      case 1697:
                        so=125;
                        resword = "8f145f3a7350c9f7af732bc9e1453c3f";
                        goto compare;
                      case 1700:
                        so=89;
                        resword = "6632151918d93b0b68ea2a8e79ba6712";
                        goto compare;
                      case 1701:
                        so=15;
                        resword = "10db95e02c5ab5d92ae04e12d7d3bd2c";
                        goto compare;
                      case 1702:
                        so=332;
                        resword = "c52c4dd72c579ecf81806465b0ded63b";
                        goto compare;
                      case 1705:
                        so=415;
                        resword = "21672d975b65ac294e8a9e37b506ec48";
                        goto compare;
                      case 1712:
                        so=22;
                        resword = "01c6f2516d42f86dc0f16b64a3cec7bb";
                        goto compare;
                      case 1717:
                        so=295;
                        resword = "ba1f41f3f74291de6a8fab6e5bd738c1";
                        goto compare;
                      case 1730:
                        so=369;
                        resword = "2c40b93625f6812ff84c7438e29dfe78";
                        goto compare;
                      case 1735:
                        so=32;
                        resword = "6364e8bc9425ca32ea543a0e8b408714";
                        goto compare;
                      case 1740:
                        so=172;
                        resword = "c561d7e2c3fccd190d73044b9ff783c9";
                        goto compare;
                      case 1742:
                        so=286;
                        resword = "2cc4baa582c248eb999ed700713335c6";
                        goto compare;
                      case 1747:
                        so=339;
                        resword = "619c8bcf1ef6e71685633c1a5f7f5962";
                        goto compare;
                      case 1750:
                        so=206;
                        resword = "3187ddd0fa9f25491b95f26b297a9edc";
                        goto compare;
                      case 1760:
                        so=235;
                        resword = "1137f61915bb39299280f84968327362";
                        goto compare;
                      case 1762:
                        so=114;
                        resword = "c32833156010a9acef8b3ece9d0b6991";
                        goto compare;
                      case 1764:
                        so=111;
                        resword = "ee4cc1ab79ffe43abc8940a5622c99ed";
                        goto compare;
                      case 1765:
                        so=171;
                        resword = "c874b3b941792de60667aa5389aef6fa";
                        goto compare;
                      case 1770:
                        so=332;
                        resword = "c972cb988b3303ed039f59cf6b376c86";
                        goto compare;
                      case 1777:
                        so=204;
                        resword = "c22896cecf2f6c32e09151d42cd65237";
                        goto compare;
                      case 1781:
                        so=21;
                        resword = "282c3bcbe3f00186bcbb7f8c979e35c0";
                        goto compare;
                      case 1782:
                        so=337;
                        resword = "8ac1249783fe1f111af44e6d2a9d268f";
                        goto compare;
                      case 1785:
                        so=230;
                        resword = "812ee9cdb7e16c2e6ce6260413b1de23";
                        goto compare;
                      case 1795:
                        so=23;
                        resword = "c3201fa7a81cdc389b62bffcc10832c4";
                        goto compare;
                      case 1796:
                        so=242;
                        resword = "a98501730519a16d019d09fba820f890";
                        goto compare;
                      case 1802:
                        so=195;
                        resword = "21ceb27963a1051c655217b95df81139";
                        goto compare;
                      case 1810:
                        so=284;
                        resword = "a46cc1854faf3b8a1bbbcdaab056e868";
                        goto compare;
                      case 1811:
                        so=370;
                        resword = "437b95b3ea2715362f7df9dca44e92bc";
                        goto compare;
                      case 1821:
                        so=410;
                        resword = "5654ae97bad9f6d3caf0e3ad2fb0f1e9";
                        goto compare;
                      case 1835:
                        so=7;
                        resword = "ea2243bda7d1018e3044fbac3c579307";
                        goto compare;
                      case 1845:
                        so=393;
                        resword = "2007d5b1fd4362c32d52fea7cca118dc";
                        goto compare;
                      case 1854:
                        so=371;
                        resword = "a5b18aa8e104fdfca19aa304ad570098";
                        goto compare;
                      case 1855:
                        so=128;
                        resword = "e563a5e223d21da69650c93ac0ac7389";
                        goto compare;
                      case 1864:
                        so=386;
                        resword = "bd9cedf2bc0e759e7f64b20b35d5b61a";
                        goto compare;
                      case 1872:
                        so=188;
                        resword = "18750fcd39ab69ba9648414de5941c7b";
                        goto compare;
                      case 1877:
                        so=94;
                        resword = "a29b2909be86c85ae4b2fbd80be2e7c9";
                        goto compare;
                      case 1880:
                        so=202;
                        resword = "596d3b5b56b9f4fa22737f70e79b0e62";
                        goto compare;
                      case 1885:
                        so=203;
                        resword = "e406450bd472385796ecd7263a776436";
                        goto compare;
                      case 1895:
                        so=21;
                        resword = "c50671def04c4c284c8b00e1d7d251db";
                        goto compare;
                      case 1905:
                        so=260;
                        resword = "c002b6b7b13a89884389dd46a123efca";
                        goto compare;
                      case 1910:
                        so=4;
                        resword = "c3769601b51dcda5cb7570b2fcc40c9d";
                        goto compare;
                      case 1911:
                        so=299;
                        resword = "a0957ab7758adcb19b4d8d24e2babb2d";
                        goto compare;
                      case 1912:
                        so=46;
                        resword = "0ea2678e230a1f726341a3a2627f85a1";
                        goto compare;
                      case 1920:
                        so=107;
                        resword = "e130a99763fbe3d5776584e9196303b7";
                        goto compare;
                      case 1922:
                        so=414;
                        resword = "2545aed485ddf495534c1037bfe1ff5c";
                        goto compare;
                      case 1925:
                        so=99;
                        resword = "029f31dc3a1f52201859129052cd2521";
                        goto compare;
                      case 1930:
                        so=388;
                        resword = "e100e88fbe87da589580ea1337b599d8";
                        goto compare;
                      case 1932:
                        so=46;
                        resword = "3d0ca4a4100919e9b26d2148d461e7cb";
                        goto compare;
                      case 1935:
                        so=180;
                        resword = "9e26e4e6b6c582e534eff7af65ba8144";
                        goto compare;
                      case 1943:
                        so=14;
                        resword = "b088f8ee9e1c6587eab9b5063bf00bee";
                        goto compare;
                      case 1949:
                        so=3;
                        resword = "bd88bcf361bd31be71669ff2cc8b28f2";
                        goto compare;
                      case 1950:
                        so=346;
                        resword = "2b7e2743e05448f5d55bfd1364ff74e3";
                        goto compare;
                      case 1954:
                        so=263;
                        resword = "7e6d7ece7905ab6f0297c1aa74a7f48a";
                        goto compare;
                      case 1960:
                        so=289;
                        resword = "d577030bbb715a6f3844e3d1a8fa233a";
                        goto compare;
                      case 1972:
                        so=313;
                        resword = "94cc2d45f2f2cc1a7d50d0cd00190d10";
                        goto compare;
                      case 1985:
                        so=324;
                        resword = "b24b30557808cb8cddb98d4322c96861";
                        goto compare;
                      case 1987:
                        so=1;
                        resword = "1d18b07e104998e0716e67f7b331ffdd";
                        goto compare;
                      case 1993:
                        so=266;
                        resword = "a9c58e6c410684d52288b36680020aa9";
                        goto compare;
                      case 1994:
                        so=257;
                        resword = "3c9bb0465d285b7f3056ff163441cd97";
                        goto compare;
                      case 1998:
                        so=286;
                        resword = "950e777865397e0a9d6805de5cf60ffd";
                        goto compare;
                      case 1999:
                        so=298;
                        resword = "9e2b2f736997b1564c5db7dd4a185ba3";
                        goto compare;
                      case 2000:
                        so=175;
                        resword = "13b442411a0c650b55468ad84a8cb97e";
                        goto compare;
                      case 2002:
                        so=269;
                        resword = "c97c240511040b8c6be420a622016d05";
                        goto compare;
                      case 2003:
                        so=365;
                        resword = "928eccfec5a3887cd18463572f10403e";
                        goto compare;
                      case 2004:
                        so=395;
                        resword = "b465d2067e34e111b5e0ed74abc25f77";
                        goto compare;
                      case 2009:
                        so=114;
                        resword = "9450788bc2daffb88b732c6fc271dcbc";
                        goto compare;
                    }
                }
              else
                {
                  switch (key - 2069)
                    {
                      case 0:
                        so=112;
                        resword = "c3c15bc9d4dc2474ee7ceb34eda0f6fa";
                        goto compare;
                      case 10:
                        so=56;
                        resword = "c8c3065a8fc59b43634f90a09ab87cea";
                        goto compare;
                      case 15:
                        so=28;
                        resword = "e5c97da1fbbabc246785cba6944211fa";
                        goto compare;
                      case 18:
                        so=386;
                        resword = "10b29e72b711eaaa0d80ff3ed1379c2c";
                        goto compare;
                      case 25:
                        so=218;
                        resword = "c5c13ee169a54261f340d5e677c46d9b";
                        goto compare;
                      case 27:
                        so=78;
                        resword = "aa6d5baab9e1588d3870ac17c54ceb22";
                        goto compare;
                      case 35:
                        so=394;
                        resword = "e6c44e63ec2a898994e3cb4846ab59f4";
                        goto compare;
                      case 39:
                        so=341;
                        resword = "52884e18c8f0183c14b8e2e57a527442";
                        goto compare;
                      case 47:
                        so=38;
                        resword = "18ab19f4cdb6be3bf453f1f78e453ca7";
                        goto compare;
                      case 51:
                        so=145;
                        resword = "909e4dc36f2e79a7494c295e129f9a35";
                        goto compare;
                      case 52:
                        so=259;
                        resword = "1216e8b802c65398e0bf6d5c1bed48d4";
                        goto compare;
                      case 55:
                        so=220;
                        resword = "4980094c4f3232eb72e7a8fca895b146";
                        goto compare;
                      case 65:
                        so=370;
                        resword = "ce267c913e138f03559755bd16b5d0a9";
                        goto compare;
                      case 78:
                        so=388;
                        resword = "511f3f4dbdda67a3fd6acd457f99f241";
                        goto compare;
                      case 84:
                        so=321;
                        resword = "59598aa0136e95f5a1f4dac30d8605f7";
                        goto compare;
                      case 85:
                        so=145;
                        resword = "8565f9596e78e304209e2cfea3e250e6";
                        goto compare;
                      case 91:
                        so=186;
                        resword = "9494ad80cefe746ca8f6b1265c2e046d";
                        goto compare;
                      case 94:
                        so=212;
                        resword = "46cc3a045070db446c7fc23992b34a2c";
                        goto compare;
                      case 97:
                        so=51;
                        resword = "1c8b4aea8f96ebe0975ec2b15b4f106f";
                        goto compare;
                      case 98:
                        so=246;
                        resword = "ae7260c4b95ac76415b210b8e498cfb1";
                        goto compare;
                      case 102:
                        so=77;
                        resword = "4e96ef8b9ab3989d477cfa792d0e6ef0";
                        goto compare;
                      case 105:
                        so=347;
                        resword = "4a435f348629400aeb9c5d9e8780b102";
                        goto compare;
                      case 108:
                        so=5;
                        resword = "6583b9290a2f0c5bacf759b9e4fa39f6";
                        goto compare;
                      case 113:
                        so=340;
                        resword = "6169e22004a4aeccb075690f693b88a8";
                        goto compare;
                      case 115:
                        so=125;
                        resword = "75b459c543a914be1ce3660e95eaa5f2";
                        goto compare;
                      case 116:
                        so=101;
                        resword = "a6064890bf08eea2d0be4b4703571d32";
                        goto compare;
                      case 117:
                        so=369;
                        resword = "0f28accc9a4f804eb5faa0be853fc780";
                        goto compare;
                      case 123:
                        so=309;
                        resword = "af6be998b6add1bc27fd3145be14c79c";
                        goto compare;
                      case 124:
                        so=32;
                        resword = "277fa890c133d74962763c7bb9f4420e";
                        goto compare;
                      case 128:
                        so=184;
                        resword = "08b13c88a1910f82e4ec103818591abf";
                        goto compare;
                      case 130:
                        so=176;
                        resword = "88255e3fea784a0d467569db6d9a37b5";
                        goto compare;
                      case 133:
                        so=40;
                        resword = "ea90d79b349e5b4a9158ca0843ad484f";
                        goto compare;
                      case 140:
                        so=57;
                        resword = "bd92b3e4254322b2b2e50d2c4a1a0d3d";
                        goto compare;
                      case 141:
                        so=278;
                        resword = "9b33cb4cc2cab2da856e8142cf588b1a";
                        goto compare;
                      case 147:
                        so=89;
                        resword = "bab829cde6e70f74dd7bb52c0d717389";
                        goto compare;
                      case 155:
                        so=159;
                        resword = "d5d18a0de9b877821ae06d71e126f21c";
                        goto compare;
                      case 159:
                        so=232;
                        resword = "db53d991ac351dee8b9cb8e7d52273dd";
                        goto compare;
                      case 169:
                        so=360;
                        resword = "85987be7a05fd067aab1c67de7a2cc58";
                        goto compare;
                      case 171:
                        so=109;
                        resword = "e35c83d815df5370506b85fe83becb8b";
                        goto compare;
                      case 178:
                        so=381;
                        resword = "dc21718f2f89782da07792bfeb4ea973";
                        goto compare;
                      case 182:
                        so=32;
                        resword = "ad004d6f8f33f44304e0245acd84f8d3";
                        goto compare;
                      case 188:
                        so=175;
                        resword = "32aec0a2d282f471278ad896041cfc07";
                        goto compare;
                      case 191:
                        so=317;
                        resword = "9b24ecb3903ed68ab649ab75e8b006bc";
                        goto compare;
                      case 199:
                        so=117;
                        resword = "1e36d378232429c8a3b8136e4105fc64";
                        goto compare;
                      case 204:
                        so=35;
                        resword = "b58921b140aec49734b5e3182b1c197d";
                        goto compare;
                      case 215:
                        so=168;
                        resword = "3f66f77cbfaef301cafb16de53245708";
                        goto compare;
                      case 222:
                        so=227;
                        resword = "4168e4d83555dd9ece7cc44968075265";
                        goto compare;
                      case 227:
                        so=250;
                        resword = "83108886af0f728916bc3aeee85758a8";
                        goto compare;
                      case 234:
                        so=79;
                        resword = "a8cd921ec96995dc8be1330086037717";
                        goto compare;
                      case 238:
                        so=148;
                        resword = "6341212e409e3d4ab2f75b87b774bd50";
                        goto compare;
                      case 240:
                        so=305;
                        resword = "42060d6b1c9f46d211eed1d8490e3db1";
                        goto compare;
                      case 245:
                        so=214;
                        resword = "4640b1db3355590307ecaea83b4f6f28";
                        goto compare;
                      case 262:
                        so=214;
                        resword = "9451a9978d40ba9b8deeac7a5e6f0cb8";
                        goto compare;
                      case 263:
                        so=288;
                        resword = "88b2c83b89ada1218f83a1f43186cee0";
                        goto compare;
                      case 277:
                        so=58;
                        resword = "822266e0d76c06d6d9b27376d44d96f2";
                        goto compare;
                      case 295:
                        so=273;
                        resword = "41015ce96d4547dd1260cbcba14520a9";
                        goto compare;
                      case 297:
                        so=167;
                        resword = "97627c6081937a83b0e93ac53bc8c945";
                        goto compare;
                      case 298:
                        so=118;
                        resword = "db33511829638b9594fbd7a0c1aeb9f8";
                        goto compare;
                      case 306:
                        so=311;
                        resword = "1ec07bc920a4bf691dba214b2d953b15";
                        goto compare;
                      case 310:
                        so=49;
                        resword = "4003a8c69e27f5a271556d49dc8285c8";
                        goto compare;
                      case 317:
                        so=127;
                        resword = "a2b6dd04dc88920b1eea0ab658273cce";
                        goto compare;
                      case 327:
                        so=154;
                        resword = "b3b878e907691e1db956f2eea1fe2abc";
                        goto compare;
                      case 337:
                        so=261;
                        resword = "4e6922f46c1ec8dbd285faa1cf37d8af";
                        goto compare;
                      case 338:
                        so=249;
                        resword = "812fa7d4b824d0a11143b235dec877e0";
                        goto compare;
                      case 340:
                        so=416;
                        resword = "464994d77d2a47adde99779a543ecfb7";
                        goto compare;
                      case 343:
                        so=377;
                        resword = "5ab176f1f9258de71e4eb535783862b3";
                        goto compare;
                      case 350:
                        so=67;
                        resword = "ce414d8bc3bd9f564bee64027c7cdfae";
                        goto compare;
                      case 367:
                        so=99;
                        resword = "0d8be8ea96a47bebca5845441f16fa23";
                        goto compare;
                      case 370:
                        so=345;
                        resword = "7c2437001bd319c7b9f293c6f19d90c2";
                        goto compare;
                      case 376:
                        so=51;
                        resword = "383355a44177acffdaafb1cc277d0b31";
                        goto compare;
                      case 377:
                        so=299;
                        resword = "4e99713b7a6aa21a706cc6041d08645b";
                        goto compare;
                      case 378:
                        so=212;
                        resword = "c0360a4781a80aabaa51e6a29d48920c";
                        goto compare;
                      case 380:
                        so=270;
                        resword = "b1b1a14aee5fdb29a044884953724529";
                        goto compare;
                      case 385:
                        so=32;
                        resword = "8465e97166b7215dace4f930cd085077";
                        goto compare;
                      case 391:
                        so=363;
                        resword = "382411a3b1690c2765ac00a80aa26a36";
                        goto compare;
                      case 403:
                        so=68;
                        resword = "8c112e2c366248812056558b2d751a5a";
                        goto compare;
                      case 408:
                        so=215;
                        resword = "c82ece85b5d5cd8002499a224371c6b3";
                        goto compare;
                      case 413:
                        so=396;
                        resword = "ee5c2fd407f5bb86724342faacf6edaa";
                        goto compare;
                      case 421:
                        so=150;
                        resword = "3391435f62d57bb138a598a72d267367";
                        goto compare;
                      case 427:
                        so=165;
                        resword = "aba0b665f98d4484a76260c6953d0ad7";
                        goto compare;
                      case 438:
                        so=228;
                        resword = "c1642c53369236651de0a4d9bc15103f";
                        goto compare;
                      case 440:
                        so=394;
                        resword = "dd6c8d2dd8523ccfe88d70e1b507b4d4";
                        goto compare;
                      case 443:
                        so=394;
                        resword = "6599a907038bded0def86e39767a2b21";
                        goto compare;
                      case 444:
                        so=393;
                        resword = "c1cb945e0746baaef77cf2aae1420088";
                        goto compare;
                      case 445:
                        so=173;
                        resword = "454ec9c17a6dc8dadd9ced25c68be653";
                        goto compare;
                      case 446:
                        so=118;
                        resword = "2220d573a430e5a04ca919d0d5102e8f";
                        goto compare;
                      case 450:
                        so=333;
                        resword = "7d768ff674ae827d72597428c6aaa9d7";
                        goto compare;
                      case 459:
                        so=156;
                        resword = "c77259157667b4a660873094676a9a03";
                        goto compare;
                      case 470:
                        so=364;
                        resword = "89d3f6163b50a7e998fb44c5f4aaad96";
                        goto compare;
                      case 473:
                        so=122;
                        resword = "779594e973f5221d706d75e5adaef00e";
                        goto compare;
                      case 481:
                        so=318;
                        resword = "038481472d0101c2eca27c59e5a89324";
                        goto compare;
                      case 483:
                        so=97;
                        resword = "9f330d79d1cf75f3b38c1d421f7a4d6d";
                        goto compare;
                      case 491:
                        so=23;
                        resword = "47623d671c62a795fe7574ba85ad4211";
                        goto compare;
                      case 496:
                        so=207;
                        resword = "4712a6c789278dd5568c54301fe88879";
                        goto compare;
                      case 501:
                        so=398;
                        resword = "915b64d6e71e29551a6cd6118f1a6f31";
                        goto compare;
                      case 502:
                        so=99;
                        resword = "5c3b963d30f4713c40f3d48f93e1e05c";
                        goto compare;
                      case 510:
                        so=407;
                        resword = "88b82db37124661ab3e88b9358dc451f";
                        goto compare;
                      case 512:
                        so=373;
                        resword = "9154d1787cfd34a226465d2862f44edd";
                        goto compare;
                      case 515:
                        so=85;
                        resword = "150b1582e7502702bdad716edaa20954";
                        goto compare;
                      case 520:
                        so=142;
                        resword = "ebc45798a7d11e4a796dd4c22d6d7076";
                        goto compare;
                      case 523:
                        so=198;
                        resword = "308c5e45f42a65bed3a9f8c3765c9466";
                        goto compare;
                      case 526:
                        so=263;
                        resword = "5864b8e01a39bacd04aec53a529bd2ac";
                        goto compare;
                      case 530:
                        so=361;
                        resword = "b25010ab9422ca5e62b8c5f98e89a6d0";
                        goto compare;
                      case 531:
                        so=361;
                        resword = "9b76aa4543963f7d18e7c6ce9164b670";
                        goto compare;
                      case 537:
                        so=281;
                        resword = "c6c8731af4cfc29ed25c27889f444cc6";
                        goto compare;
                      case 549:
                        so=58;
                        resword = "89c6f6a020b751eae5bb55518c42ead2";
                        goto compare;
                      case 554:
                        so=298;
                        resword = "4e489bbfb17cea278e56e9da69426d3e";
                        goto compare;
                      case 555:
                        so=95;
                        resword = "81654de0be75594f7e97a45cb2b6bc24";
                        goto compare;
                      case 558:
                        so=113;
                        resword = "6207d87d562032f18098d8bb06144025";
                        goto compare;
                      case 562:
                        so=133;
                        resword = "a7725674cc2a61259ab8bac28ce80008";
                        goto compare;
                      case 567:
                        so=337;
                        resword = "6f087f1c8a0f0c7db07b65f1ae2c1fbf";
                        goto compare;
                      case 571:
                        so=286;
                        resword = "55326e8cac018c4177afff876d6152de";
                        goto compare;
                      case 574:
                        so=368;
                        resword = "0d51941b80fcc5b460732f8c7e51aa43";
                        goto compare;
                      case 583:
                        so=210;
                        resword = "9f72dbd3a6d2c0d6b675b5c79e20ee16";
                        goto compare;
                      case 589:
                        so=121;
                        resword = "125d9f4464efac942f4ce1db7ed17dbf";
                        goto compare;
                      case 592:
                        so=239;
                        resword = "dd4b507358152e9daa8c16448a399e2c";
                        goto compare;
                      case 600:
                        so=154;
                        resword = "4313e67649a066664bf084aec69cce8b";
                        goto compare;
                      case 603:
                        so=133;
                        resword = "9f7133d0fc42f581b2400548d0f7b055";
                        goto compare;
                      case 606:
                        so=365;
                        resword = "9027e09783b79235be78b051145103e3";
                        goto compare;
                      case 623:
                        so=188;
                        resword = "9f4121b1aea032181797e35401c2f695";
                        goto compare;
                      case 629:
                        so=120;
                        resword = "1d5255c7cf258d9e958f811ab3c58e49";
                        goto compare;
                      case 635:
                        so=368;
                        resword = "5f27f030d33231981d70364039f358de";
                        goto compare;
                      case 645:
                        so=89;
                        resword = "da65ad2ddc5da541ac794625e86eda78";
                        goto compare;
                      case 648:
                        so=18;
                        resword = "e817edbe827208d4c286965793a8ea39";
                        goto compare;
                      case 649:
                        so=388;
                        resword = "d8c1dc29343ab5c85bbfbbb928460206";
                        goto compare;
                      case 657:
                        so=274;
                        resword = "ef7c10065d663c354c7cb7183c24534c";
                        goto compare;
                      case 662:
                        so=9;
                        resword = "935989c90a88432b75eda8f5688b35ee";
                        goto compare;
                      case 663:
                        so=158;
                        resword = "c566402cde472334a5f9cf02f37716f0";
                        goto compare;
                      case 678:
                        so=36;
                        resword = "da8d9dded9fd1fd137768aee3836bf5f";
                        goto compare;
                      case 687:
                        so=307;
                        resword = "6fc31bcf293c2de4ad979ee42ff29e89";
                        goto compare;
                      case 688:
                        so=315;
                        resword = "cb012f52ca7f75dc6843f5fcccd586bc";
                        goto compare;
                      case 692:
                        so=284;
                        resword = "75dfdc3dde58526dd362e1f55c328645";
                        goto compare;
                      case 698:
                        so=101;
                        resword = "c85b320b75a9856e7de67481e7dec255";
                        goto compare;
                      case 703:
                        so=334;
                        resword = "ca095f54df947d2041eb3ed86e790ff3";
                        goto compare;
                      case 713:
                        so=68;
                        resword = "30c4c1c9b2fceb43b0a002941333ed5a";
                        goto compare;
                      case 716:
                        so=293;
                        resword = "949e8872d3f9c79202f8cc2d7aa41706";
                        goto compare;
                      case 717:
                        so=168;
                        resword = "02cbb34f48ba14943ba1ed8269c0ce7e";
                        goto compare;
                      case 720:
                        so=29;
                        resword = "54155bc5164f576047fe5223782b936d";
                        goto compare;
                      case 730:
                        so=105;
                        resword = "4586cb83f0b11ce450f32bb9d66f0da8";
                        goto compare;
                      case 733:
                        so=183;
                        resword = "2656bed46cf84adb7fb39c589181ec2e";
                        goto compare;
                      case 734:
                        so=104;
                        resword = "a8dfdd31b1b5f209d04b880c272564c7";
                        goto compare;
                      case 738:
                        so=407;
                        resword = "da8d97384fea336754483fa58bcaff8a";
                        goto compare;
                      case 740:
                        so=413;
                        resword = "33dfc0a79624db79a84f3792d840fa39";
                        goto compare;
                      case 745:
                        so=72;
                        resword = "ee1e28911002e257005d62c555ae83dc";
                        goto compare;
                      case 753:
                        so=152;
                        resword = "6c6312ea1e4d4abef0702f64119e0079";
                        goto compare;
                      case 758:
                        so=336;
                        resword = "e53f87bb9d38054de198947eecf69350";
                        goto compare;
                      case 760:
                        so=6;
                        resword = "0fa038134bcd8e940f8e3334ae874ea3";
                        goto compare;
                      case 763:
                        so=331;
                        resword = "e83f1e4d01a3275d3d9a5544be09c5ef";
                        goto compare;
                      case 765:
                        so=235;
                        resword = "df815ea9d5841c9969f18e4534e56f48";
                        goto compare;
                      case 771:
                        so=253;
                        resword = "85237d791d79367d5eab58c7808c473a";
                        goto compare;
                      case 772:
                        so=94;
                        resword = "dfc95ca0b3f46ec7f5e1759054218a61";
                        goto compare;
                      case 775:
                        so=174;
                        resword = "1ea6e970ae60afb84af5298cbdd25dd1";
                        goto compare;
                      case 780:
                        so=20;
                        resword = "60d681d06576ef35dd4beec91be1a61e";
                        goto compare;
                      case 783:
                        so=372;
                        resword = "2d36755ada2ca8c93df11d3a1db8266d";
                        goto compare;
                      case 785:
                        so=301;
                        resword = "bba979317f71e4aecf668b324da0ece3";
                        goto compare;
                      case 786:
                        so=44;
                        resword = "85619bed4b96fa4f4fa944611c637af5";
                        goto compare;
                      case 791:
                        so=416;
                        resword = "89243c576f2ae2725aa553372ff5762f";
                        goto compare;
                      case 796:
                        so=316;
                        resword = "7b579b13a6f8101a5a8d1651e8cdb450";
                        goto compare;
                      case 803:
                        so=322;
                        resword = "8ba16b17d52ffa46736e8ea28e53d56f";
                        goto compare;
                      case 819:
                        so=278;
                        resword = "6f8b45cc18d1f27189eb4df27a3057ee";
                        goto compare;
                      case 821:
                        so=33;
                        resword = "4796f625a064f3d37ce4243001b37bc3";
                        goto compare;
                      case 823:
                        so=73;
                        resword = "1e2673fb4bff04d9e0a19d92172c1de0";
                        goto compare;
                      case 825:
                        so=30;
                        resword = "4b638b2f54f99d682ce5b61a05806e4f";
                        goto compare;
                      case 827:
                        so=53;
                        resword = "9f1b9cd18844386c0cea144e3409bc95";
                        goto compare;
                      case 835:
                        so=147;
                        resword = "0e0d152c71a24c73bdf5f5e60ed5ab40";
                        goto compare;
                      case 836:
                        so=98;
                        resword = "908fbdd894e0fed43668abef71e122b8";
                        goto compare;
                      case 838:
                        so=395;
                        resword = "79198c32f671d36b25a46a639135054c";
                        goto compare;
                      case 840:
                        so=222;
                        resword = "d6cfff099fc1fd4c8950f0cb16aee3d6";
                        goto compare;
                      case 846:
                        so=246;
                        resword = "82612f96e3664192fda9d3b4141f6467";
                        goto compare;
                      case 853:
                        so=254;
                        resword = "27395a7b3e0ce849b7b8e26c0cb06503";
                        goto compare;
                      case 861:
                        so=166;
                        resword = "4bcb0c8354a3569a5e65560f30d6ead4";
                        goto compare;
                      case 868:
                        so=324;
                        resword = "85a6a94909df7b5ce3f9533f3a572589";
                        goto compare;
                      case 880:
                        so=259;
                        resword = "7c4947788218e36236f0811bfa7db33b";
                        goto compare;
                      case 887:
                        so=264;
                        resword = "3fcf217699abc0250779219bb765d1a9";
                        goto compare;
                      case 893:
                        so=400;
                        resword = "3c6fa6788fb5de5ca1807a2cec0bde0d";
                        goto compare;
                      case 900:
                        so=26;
                        resword = "e7527d609f57aa79136b165c43ad0cad";
                        goto compare;
                      case 913:
                        so=292;
                        resword = "d31fe2ff6a34e536e6fd5bb22b04b1fa";
                        goto compare;
                      case 919:
                        so=156;
                        resword = "67760144bf8927931bffb1e74276860e";
                        goto compare;
                      case 922:
                        so=6;
                        resword = "b8dd5b10cc0bcb4e9983c524aa0c3856";
                        goto compare;
                      case 928:
                        so=28;
                        resword = "d9b95e528bfbe20c6741f7e38d322032";
                        goto compare;
                      case 933:
                        so=208;
                        resword = "86b6309ad2de147fbf50fe8474fcd4b4";
                        goto compare;
                      case 935:
                        so=300;
                        resword = "45291c47a1b57574b3fac1e31153a79d";
                        goto compare;
                      case 941:
                        so=285;
                        resword = "8336b7af06b51a82d0a584b555cad4b5";
                        goto compare;
                      case 944:
                        so=229;
                        resword = "965805fdb89ccc0389f8d97930e82a75";
                        goto compare;
                      case 975:
                        so=263;
                        resword = "cf032fa42789e75e0d81bb8dcfc30045";
                        goto compare;
                      case 988:
                        so=41;
                        resword = "db77968c7e7957a8caeb0bc0666cc766";
                        goto compare;
                      case 992:
                        so=318;
                        resword = "ec9bf8f675e780a9e54e05a23b75bf00";
                        goto compare;
                      case 1006:
                        so=303;
                        resword = "df5902f8d9a16eb0696facef588df799";
                        goto compare;
                      case 1016:
                        so=411;
                        resword = "a497ffa3f078fa6590b3953a13399a0e";
                        goto compare;
                      case 1019:
                        so=307;
                        resword = "0f23b3c2e70727a232b54929a49882ef";
                        goto compare;
                      case 1022:
                        so=321;
                        resword = "d86edf02dae56af2abbec27eafb21b6b";
                        goto compare;
                      case 1029:
                        so=174;
                        resword = "cf1baab3067b5fad8569fd519c7352d8";
                        goto compare;
                      case 1033:
                        so=313;
                        resword = "58af0b3ea884667cb58d0a19f486a551";
                        goto compare;
                      case 1038:
                        so=44;
                        resword = "23c9ce9b6901d7a9c6ae54321fb40171";
                        goto compare;
                      case 1046:
                        so=159;
                        resword = "af05e8e2b6a92a4d30798528891b9c73";
                        goto compare;
                      case 1052:
                        so=375;
                        resword = "13d561ab1a2cde35457ce388225d2a00";
                        goto compare;
                      case 1053:
                        so=287;
                        resword = "1ca4f5cda7f578aed791d5980c3df784";
                        goto compare;
                      case 1055:
                        so=362;
                        resword = "e9d697ff9adf8e416ce96645297ee59c";
                        goto compare;
                      case 1059:
                        so=92;
                        resword = "8c549d46c04b4e9fa8594dbd8fc68ae0";
                        goto compare;
                      case 1061:
                        so=126;
                        resword = "d765e4ceddbcf01daa7b7687e7a4c690";
                        goto compare;
                      case 1065:
                        so=80;
                        resword = "0fb4d78565c2aacc9188cefa54ab50ad";
                        goto compare;
                      case 1070:
                        so=218;
                        resword = "d19518efe7b1f9bf53e5b5cd7acacd23";
                        goto compare;
                      case 1072:
                        so=224;
                        resword = "5acb2a066c85d208f7aa02145b60a5ee";
                        goto compare;
                      case 1076:
                        so=408;
                        resword = "8735adec8457cfc57deed8b23da7c991";
                        goto compare;
                      case 1089:
                        so=412;
                        resword = "9e526cc7b668fe2b33f12d53885919fe";
                        goto compare;
                      case 1104:
                        so=137;
                        resword = "a1dfa9f5cd3145922d9e158154fa140e";
                        goto compare;
                      case 1123:
                        so=192;
                        resword = "68a9865e1b83aaebca835a0b4d4fe89d";
                        goto compare;
                      case 1126:
                        so=47;
                        resword = "b6d407d0fd8be9ffb8b21c98c3875f86";
                        goto compare;
                      case 1128:
                        so=200;
                        resword = "da9f6b5529eba24923f230fb6e89a7c6";
                        goto compare;
                      case 1133:
                        so=108;
                        resword = "6c791f325c59454a488ead1147a000c9";
                        goto compare;
                      case 1134:
                        so=2;
                        resword = "d7b43bf53c41e0437f935d76a885f009";
                        goto compare;
                      case 1138:
                        so=167;
                        resword = "512dc3885edcebc0fcf64defb42df313";
                        goto compare;
                      case 1151:
                        so=327;
                        resword = "919f12ea6618cd0e1c6e2f0f7e9f702b";
                        goto compare;
                      case 1152:
                        so=226;
                        resword = "075540d0bcede220ce73b08e20d2141a";
                        goto compare;
                      case 1157:
                        so=277;
                        resword = "e524ae4b2f7ccbc762b7db3bd34ef53c";
                        goto compare;
                      case 1161:
                        so=357;
                        resword = "d671f3a61fe80800feab06f947109654";
                        goto compare;
                      case 1162:
                        so=409;
                        resword = "6202be324f1f459ca8b0b2e6a5db2d7f";
                        goto compare;
                      case 1163:
                        so=163;
                        resword = "621f39ae3bbc04ee4f5f9606e28a3b9f";
                        goto compare;
                      case 1168:
                        so=241;
                        resword = "65a9d545127d35e4056659c271963d09";
                        goto compare;
                      case 1170:
                        so=240;
                        resword = "423fda82ec5cc9d8ee74210f11bc97f7";
                        goto compare;
                      case 1175:
                        so=140;
                        resword = "90000efb73d7640732bb9d2595d0cd00";
                        goto compare;
                      case 1176:
                        so=113;
                        resword = "661bcd14e72d7ad63ebd236d8215bb95";
                        goto compare;
                      case 1177:
                        so=149;
                        resword = "16674bc998bc6abb40b70255a31a7628";
                        goto compare;
                      case 1201:
                        so=342;
                        resword = "7ed571d6a3f4b251f086ca56cd2f5e98";
                        goto compare;
                      case 1207:
                        so=181;
                        resword = "156fdc4cc76d017ecab79a409415e379";
                        goto compare;
                      case 1211:
                        so=356;
                        resword = "924d729c6e14ecdbbb42648fba04f2fb";
                        goto compare;
                      case 1225:
                        so=12;
                        resword = "cad1d508a913ef68ca86c29f49a6543c";
                        goto compare;
                      case 1235:
                        so=129;
                        resword = "1fb6dc87d30f483c3b966cb9496d84f5";
                        goto compare;
                      case 1236:
                        so=304;
                        resword = "3795afd539d26317edffd1202565a4aa";
                        goto compare;
                      case 1242:
                        so=388;
                        resword = "2fcd4ce0b34fc3c8cd43bd1002f10252";
                        goto compare;
                      case 1243:
                        so=367;
                        resword = "c09f8eedfc5a7d525a48aafe7f6f55d1";
                        goto compare;
                      case 1248:
                        so=376;
                        resword = "cc14dba3f9dcdf40f8737283f5ad4ed6";
                        goto compare;
                      case 1252:
                        so=97;
                        resword = "e372f25205db430ecab9927804f4d2d1";
                        goto compare;
                      case 1253:
                        so=413;
                        resword = "1ba97beb83211a485c5aa9e6fab7690b";
                        goto compare;
                      case 1256:
                        so=211;
                        resword = "9d06201d33d16746f89d95cea0592c8d";
                        goto compare;
                      case 1259:
                        so=230;
                        resword = "09c7fd90d5416bbf0ab6e253e76350bb";
                        goto compare;
                      case 1260:
                        so=281;
                        resword = "416ef62f2640824ea657d507b2e49b26";
                        goto compare;
                      case 1268:
                        so=214;
                        resword = "e81f2280ff7bc978a05b6bf24c82501d";
                        goto compare;
                      case 1275:
                        so=371;
                        resword = "cc78d769bc37b50e5a693076e5db118f";
                        goto compare;
                      case 1277:
                        so=247;
                        resword = "e7587d967ad0433a3e5a32565874cfc9";
                        goto compare;
                      case 1278:
                        so=260;
                        resword = "d8b4feaf7b4964102ff7d8dab7a070fa";
                        goto compare;
                      case 1280:
                        so=333;
                        resword = "ef1ea94d2707e1fc5d8ae007ca0252d7";
                        goto compare;
                      case 1283:
                        so=212;
                        resword = "cb4ecf18557561bdd0802c6ee34f2ad2";
                        goto compare;
                      case 1292:
                        so=129;
                        resword = "cfc6b9379da0205d5e9cae4482fa662b";
                        goto compare;
                      case 1293:
                        so=367;
                        resword = "e44d715fec7f77b15443fbac991fd982";
                        goto compare;
                      case 1295:
                        so=359;
                        resword = "bc0d3c1b5520815be56e94c516f991c0";
                        goto compare;
                      case 1300:
                        so=177;
                        resword = "2bcf68676f703c4da5fada8e79ba8966";
                        goto compare;
                      case 1312:
                        so=105;
                        resword = "dd7bf3cb4848d03074fe8e88bd3707ad";
                        goto compare;
                      case 1313:
                        so=100;
                        resword = "d13faf770508145316f30e65bdc7cf64";
                        goto compare;
                      case 1318:
                        so=354;
                        resword = "6d3464bd8423ae5779e3806d23087d09";
                        goto compare;
                      case 1323:
                        so=316;
                        resword = "c0a177c7c7e64c35fe7b2d0c4fdbbd33";
                        goto compare;
                      case 1327:
                        so=123;
                        resword = "1c23aa34912733fd3bbf2f7c834f7e30";
                        goto compare;
                      case 1333:
                        so=347;
                        resword = "cc7612e80a99c14fc49f07f78ef39421";
                        goto compare;
                      case 1336:
                        so=371;
                        resword = "992743a61c33d02e0cf2de0a312da099";
                        goto compare;
                      case 1340:
                        so=134;
                        resword = "a7df34d1045297c9519439c4e027691b";
                        goto compare;
                      case 1343:
                        so=96;
                        resword = "cc76c511c22749419786384429ac2c9e";
                        goto compare;
                      case 1348:
                        so=157;
                        resword = "2d17a6f50a3b8e6455e644882160dafd";
                        goto compare;
                      case 1353:
                        so=120;
                        resword = "53adac4f9c1f3be86597b0ad2eca71d5";
                        goto compare;
                      case 1380:
                        so=302;
                        resword = "9046243b1217bb0375b48ed2a9c63924";
                        goto compare;
                      case 1383:
                        so=37;
                        resword = "c51fcf3ec575e5c509e030eb9bd8bc89";
                        goto compare;
                      case 1398:
                        so=323;
                        resword = "1cb417ffd17e968b237d9552d723eb1d";
                        goto compare;
                      case 1410:
                        so=7;
                        resword = "8f7d40d403736dc9e3458681af460fc0";
                        goto compare;
                      case 1414:
                        so=186;
                        resword = "6bdb68796bc2c44a4a4d20b35f9ecfad";
                        goto compare;
                      case 1423:
                        so=125;
                        resword = "6d99d34c2a6df87bfc8b56c3c2f82222";
                        goto compare;
                      case 1447:
                        so=221;
                        resword = "76d7fac34b47c0a0f4f04474195b7aec";
                        goto compare;
                      case 1451:
                        so=71;
                        resword = "aa52ef38fef5bb50e7a50476ca206a52";
                        goto compare;
                      case 1458:
                        so=265;
                        resword = "3da257f719785ef48f4baef4f0c4adb1";
                        goto compare;
                      case 1467:
                        so=4;
                        resword = "3127dc414bf1394f80b4794cf372c077";
                        goto compare;
                      case 1474:
                        so=67;
                        resword = "97c7b6a304564f4e826e428329778f33";
                        goto compare;
                      case 1480:
                        so=98;
                        resword = "eaa8b7db3b60a93078e21ff67b3fdac6";
                        goto compare;
                      case 1481:
                        so=356;
                        resword = "ce59303cb188e3658553a2ae85106606";
                        goto compare;
                      case 1487:
                        so=258;
                        resword = "0559cccc6a9aac0c97adf3068fe528c6";
                        goto compare;
                      case 1502:
                        so=336;
                        resword = "aabf07f35b13044cb49f552524c8907e";
                        goto compare;
                      case 1508:
                        so=315;
                        resword = "e0cb35117d18d9e781ba8b9dbe7671f8";
                        goto compare;
                      case 1510:
                        so=93;
                        resword = "1ccd06ebc108ca87e27a0dd2214128a5";
                        goto compare;
                      case 1517:
                        so=323;
                        resword = "b3a5f93b644c4f4a52e4895c6a912e84";
                        goto compare;
                      case 1518:
                        so=60;
                        resword = "3bc25867e516d7f91fa17312604bfaaa";
                        goto compare;
                      case 1521:
                        so=411;
                        resword = "c91bd89f0db8c4db1db5d603b380c876";
                        goto compare;
                      case 1540:
                        so=260;
                        resword = "222b32dec2a0e9ec5028723e7307ff88";
                        goto compare;
                      case 1545:
                        so=357;
                        resword = "d5d7ffc327f81b6d9956cfc77aa11146";
                        goto compare;
                      case 1547:
                        so=88;
                        resword = "843fdd53b7d6c30130b5440237104f74";
                        goto compare;
                      case 1560:
                        so=37;
                        resword = "ef1e7eb523f9535654e1d5144f02d058";
                        goto compare;
                      case 1566:
                        so=333;
                        resword = "9b2e2b0b35f3e55397f1dd85a4aa7158";
                        goto compare;
                      case 1569:
                        so=147;
                        resword = "ad65c6b4ff8b1db1ce7b6903297afe5d";
                        goto compare;
                      case 1570:
                        so=42;
                        resword = "8bac386c27a55f7d0bf016e8cd2d8c4a";
                        goto compare;
                      case 1575:
                        so=271;
                        resword = "4d04ee84c10a09978181177527077d45";
                        goto compare;
                      case 1582:
                        so=152;
                        resword = "559d92f03cd5d81e7eb4982f37a9459c";
                        goto compare;
                      case 1593:
                        so=152;
                        resword = "6b8fb292c05020d30140b43f0537aba0";
                        goto compare;
                      case 1595:
                        so=183;
                        resword = "7abf0fd4b1d293b4874487598ec015ae";
                        goto compare;
                      case 1598:
                        so=42;
                        resword = "ed29997dd008805a158bd2db235c3970";
                        goto compare;
                      case 1600:
                        so=33;
                        resword = "6bd1ae9b4dbc1a98f1e7f9cf5976569c";
                        goto compare;
                      case 1605:
                        so=151;
                        resword = "bf3384c2bdb0829449ac603d1c9f16f5";
                        goto compare;
                      case 1607:
                        so=89;
                        resword = "b82331eca64aa1cf431fc2983a47cb5b";
                        goto compare;
                      case 1611:
                        so=277;
                        resword = "58746a88d48e18ef172549a4e51250c4";
                        goto compare;
                      case 1620:
                        so=266;
                        resword = "bf607e905b0cf472d3aa5d561a22a64d";
                        goto compare;
                      case 1624:
                        so=141;
                        resword = "4d0bf2958263e6892e7f61de1033598c";
                        goto compare;
                      case 1626:
                        so=6;
                        resword = "b56bf44770c23417bb11dbe3b4599cdb";
                        goto compare;
                      case 1632:
                        so=268;
                        resword = "c3264333701223e62abac21bf5e6c6c2";
                        goto compare;
                      case 1638:
                        so=206;
                        resword = "4f5363606768bd1be88d8301ad91074b";
                        goto compare;
                      case 1639:
                        so=59;
                        resword = "49bb22b601f23f75514ad8ad4b752082";
                        goto compare;
                      case 1644:
                        so=315;
                        resword = "ada8baa3631359c71de949ea7d82ab94";
                        goto compare;
                      case 1645:
                        so=259;
                        resword = "c1c7a5a45eb8d3556e7663bfc726364d";
                        goto compare;
                      case 1646:
                        so=215;
                        resword = "511e65ea80a839205aa81e3c04221748";
                        goto compare;
                      case 1647:
                        so=414;
                        resword = "b410fddd2b6c8e52dd14c8ded45b96b7";
                        goto compare;
                      case 1648:
                        so=223;
                        resword = "b942536e7af344052d2b817f3c3379cd";
                        goto compare;
                      case 1649:
                        so=310;
                        resword = "36854772959d1b91c8beb71aa167f39b";
                        goto compare;
                      case 1656:
                        so=246;
                        resword = "199682f6d869424241261d75b8a3e24e";
                        goto compare;
                      case 1665:
                        so=126;
                        resword = "22dc472889aa9a5e70abbc616f4bded2";
                        goto compare;
                      case 1672:
                        so=140;
                        resword = "318fbbbdcbd1642465b355e5f0018d12";
                        goto compare;
                      case 1683:
                        so=44;
                        resword = "91ac0d8895f99c36ac5299cc0ca7855b";
                        goto compare;
                      case 1689:
                        so=313;
                        resword = "199bc3ab41bc75659f1b7c43b11f80dd";
                        goto compare;
                      case 1690:
                        so=94;
                        resword = "be6357e5a9528ad5e4234225be1a461c";
                        goto compare;
                      case 1694:
                        so=225;
                        resword = "a3144e86bea26c9d3e12df6423d4377f";
                        goto compare;
                      case 1696:
                        so=242;
                        resword = "1842bf64758d87522e2a80dedb6bd034";
                        goto compare;
                      case 1697:
                        so=75;
                        resword = "3aa6bb3d043335a4abbfb6390dca8551";
                        goto compare;
                      case 1699:
                        so=70;
                        resword = "61c4519bbb65fd2708bc09c1049000f8";
                        goto compare;
                      case 1701:
                        so=56;
                        resword = "7f8ea674a0ed08c693bc19a71a51dbdc";
                        goto compare;
                      case 1704:
                        so=223;
                        resword = "7238f4c498c31330791e2b73ca720d60";
                        goto compare;
                      case 1707:
                        so=328;
                        resword = "739258a0ca7af15ae61180fb44aef84b";
                        goto compare;
                      case 1710:
                        so=312;
                        resword = "0362ba8e8f3e6332a51518815738385c";
                        goto compare;
                      case 1722:
                        so=237;
                        resword = "377e28f56f1849c839ad1e75faae188c";
                        goto compare;
                      case 1727:
                        so=300;
                        resword = "8b5b06db803843dfb4b78348fc7944a2";
                        goto compare;
                      case 1733:
                        so=410;
                        resword = "60b6a930deba3fa58a590341208ed2ce";
                        goto compare;
                      case 1743:
                        so=158;
                        resword = "3bbedb82c5bd85987e538480c8170ff8";
                        goto compare;
                      case 1746:
                        so=48;
                        resword = "7645855ebb10b2a324bed6412f7e3136";
                        goto compare;
                      case 1749:
                        so=159;
                        resword = "140b4b22696d3fb7841005d27bb681ae";
                        goto compare;
                      case 1756:
                        so=268;
                        resword = "77b7435532bfef0029996df527126aec";
                        goto compare;
                      case 1759:
                        so=353;
                        resword = "605de1ba0b4c05bbb66108e38ee8a596";
                        goto compare;
                      case 1761:
                        so=226;
                        resword = "9a3f95c43d64c19186f91ca72ac5d933";
                        goto compare;
                      case 1775:
                        so=319;
                        resword = "0a9b04209b7b5268032ff4caf77f8ce3";
                        goto compare;
                      case 1777:
                        so=417;
                        resword = "0d420e624660c6a366b0b469afae1487";
                        goto compare;
                      case 1778:
                        so=397;
                        resword = "2baf1d4080fc3ee80e6b27ec3c35a0d9";
                        goto compare;
                      case 1792:
                        so=208;
                        resword = "3a8df75a0eb17f4512b171fe43aa2e9d";
                        goto compare;
                      case 1801:
                        so=382;
                        resword = "07dfd28eef82cf54e65162bb05c12987";
                        goto compare;
                    }
                }
            }
          else
            {
              if (key < 6347)
                {
                  switch (key - 3872)
                    {
                      case 0:
                        so=357;
                        resword = "d5ad803c0b5c33cdd693f9df7034fbe9";
                        goto compare;
                      case 8:
                        so=382;
                        resword = "9b6d9c605f82d0fff07625fc775159a6";
                        goto compare;
                      case 12:
                        so=82;
                        resword = "70c074548cfa73b0b82238717ecf73bf";
                        goto compare;
                      case 20:
                        so=146;
                        resword = "59d2731d841826e34aab4d50e3380c13";
                        goto compare;
                      case 31:
                        so=34;
                        resword = "e70d4bb4ab423447d480dbf69188c7e0";
                        goto compare;
                      case 35:
                        so=294;
                        resword = "32bdda79199731d921e70d59bc640322";
                        goto compare;
                      case 39:
                        so=168;
                        resword = "3b27cdf90d792da45cbbc83024fa352b";
                        goto compare;
                      case 40:
                        so=36;
                        resword = "960babfa15fe1c3ee9ac01f867a4634b";
                        goto compare;
                      case 47:
                        so=0;
                        resword = "22b546adde47fa2501ec5ba4d10e7cd5";
                        goto compare;
                      case 50:
                        so=218;
                        resword = "c077d5d0d5241286f8f3c6debd07f031";
                        goto compare;
                      case 77:
                        so=257;
                        resword = "e4d7ce209c2f97786a787245612afe61";
                        goto compare;
                      case 81:
                        so=395;
                        resword = "3c5dd3250313c7c9019cfe9babaab817";
                        goto compare;
                      case 87:
                        so=130;
                        resword = "8c759e162114eed241e7ee4e0486f63f";
                        goto compare;
                      case 88:
                        so=37;
                        resword = "34a44f861f07d616c9a9c858ef73927a";
                        goto compare;
                      case 93:
                        so=352;
                        resword = "0a36fe8e6ea5003b4f2dddf2739987ff";
                        goto compare;
                      case 94:
                        so=201;
                        resword = "8ad5bd15c8e1728b31ef27ada28b821b";
                        goto compare;
                      case 98:
                        so=337;
                        resword = "8321146c4e8a11f03d2bcd9fce0fc405";
                        goto compare;
                      case 99:
                        so=418;
                        resword = "5d4232353c629a03d2b80990bf58d35d";
                        goto compare;
                      case 100:
                        so=4;
                        resword = "c53f68ffed4e1ee21ff42ac45f4d8c19";
                        goto compare;
                      case 107:
                        so=65;
                        resword = "8c154b47dc5e65f5c7e1763667bfbd30";
                        goto compare;
                      case 132:
                        so=60;
                        resword = "45b6a3808b02542636ea9e8ad464ecf3";
                        goto compare;
                      case 136:
                        so=193;
                        resword = "212587671b6f26e552bac265f3f1dc39";
                        goto compare;
                      case 138:
                        so=187;
                        resword = "18a41e96d040c09826a00a0303638de4";
                        goto compare;
                      case 140:
                        so=412;
                        resword = "3138bb1a506a9ea4e0204a2474447bc9";
                        goto compare;
                      case 143:
                        so=53;
                        resword = "3c221405c685e5e654ae351452a47873";
                        goto compare;
                      case 144:
                        so=311;
                        resword = "b16be6175df2c78a5120aae5e3eeb563";
                        goto compare;
                      case 155:
                        so=14;
                        resword = "c1b47edf053295d7fa93a8a72a9fb092";
                        goto compare;
                      case 167:
                        so=116;
                        resword = "1c2bc3329038d58fc1ac6bed100a2525";
                        goto compare;
                      case 170:
                        so=50;
                        resword = "5e366cd6f57fcc9d6b2f8e1d02506117";
                        goto compare;
                      case 175:
                        so=91;
                        resword = "0e46c719a6f16fb71d2f4142aa97e11d";
                        goto compare;
                      case 177:
                        so=19;
                        resword = "9fc7c706b5438a18e67e75e8f8a107c2";
                        goto compare;
                      case 182:
                        so=235;
                        resword = "bc516d975ad4e3d59eb99c293ea5b532";
                        goto compare;
                      case 185:
                        so=136;
                        resword = "dc7fad584f41f9807c5933ec1ac63aff";
                        goto compare;
                      case 197:
                        so=134;
                        resword = "8524e716b520327d5f1d06689fc49cd0";
                        goto compare;
                      case 202:
                        so=160;
                        resword = "765f0700ea080e0660bcfafd4a1c3af4";
                        goto compare;
                      case 207:
                        so=280;
                        resword = "0ed6b0b5a18640c5bda0b043d8f2810a";
                        goto compare;
                      case 212:
                        so=57;
                        resword = "c3b89eb15078c5b897526b306f9584d7";
                        goto compare;
                      case 214:
                        so=252;
                        resword = "51a6e410b8fe57f50db880baef3477f7";
                        goto compare;
                      case 227:
                        so=360;
                        resword = "88148f419c9ee4ac8d1ed4c003432d92";
                        goto compare;
                      case 230:
                        so=44;
                        resword = "9cd164c4754a73d108730ef76aa5a779";
                        goto compare;
                      case 243:
                        so=373;
                        resword = "9a4c2deb002bd170a3a471abf50be439";
                        goto compare;
                      case 244:
                        so=54;
                        resword = "efd6375c5f1df572036d3e5874b9462e";
                        goto compare;
                      case 254:
                        so=25;
                        resword = "41de791088051c6991736cc2ea5e92c0";
                        goto compare;
                      case 273:
                        so=78;
                        resword = "393dddd02bcb75fa83af6afec5d19a9b";
                        goto compare;
                      case 285:
                        so=160;
                        resword = "c97c01f2fca0f1e31ba22cea97cac3bb";
                        goto compare;
                      case 317:
                        so=170;
                        resword = "511b4e1f552df88acc27e9b762ea7168";
                        goto compare;
                      case 320:
                        so=374;
                        resword = "5a57f5f34f8d4b5deebd9a8a4ae1a4af";
                        goto compare;
                      case 325:
                        so=222;
                        resword = "31bf3268089afe25605150f137b97fe3";
                        goto compare;
                      case 327:
                        so=31;
                        resword = "862416ec74808d65d215bc088d6cc4a9";
                        goto compare;
                      case 336:
                        so=234;
                        resword = "dcc05723ca49eb8a7ab5d2f8a6f10319";
                        goto compare;
                      case 337:
                        so=319;
                        resword = "6f9781a6f037cacceb5cb698d5c9dafb";
                        goto compare;
                      case 342:
                        so=177;
                        resword = "ee3d0da211c61d5f9af29c4dfa92b0c3";
                        goto compare;
                      case 352:
                        so=249;
                        resword = "ebc70c448c8da613205364f607b62e56";
                        goto compare;
                      case 355:
                        so=21;
                        resword = "c278949b9ac62bacada7f4955d352859";
                        goto compare;
                      case 370:
                        so=48;
                        resword = "e2a781b839c41c86b98015787cd46be1";
                        goto compare;
                      case 372:
                        so=309;
                        resword = "d4b5aa53a9667d55ad7531dc2de69a36";
                        goto compare;
                      case 397:
                        so=104;
                        resword = "800233c856ae231f52159daf974b90a2";
                        goto compare;
                      case 420:
                        so=320;
                        resword = "c952f99e0cd3ba357bbed6de31f62c07";
                        goto compare;
                      case 425:
                        so=24;
                        resword = "9f8741bf4c3aa35b87580fc2b6ed9ad4";
                        goto compare;
                      case 427:
                        so=140;
                        resword = "356eaf7a531f1b370e163d583ab8d478";
                        goto compare;
                      case 431:
                        so=371;
                        resword = "68d07e62411ab4f049b0edf136a32146";
                        goto compare;
                      case 437:
                        so=389;
                        resword = "b8de97511972414499a62100889cc8d8";
                        goto compare;
                      case 446:
                        so=148;
                        resword = "a176e98a90dea7c60a1747394b11f1b2";
                        goto compare;
                      case 447:
                        so=346;
                        resword = "a19ff92a3d8459027aa9e7ccd2367a1c";
                        goto compare;
                      case 449:
                        so=9;
                        resword = "d97c974f86d0594b1c1d0dd4ec059624";
                        goto compare;
                      case 452:
                        so=197;
                        resword = "a00e83491c65e71d2e27a2b6e62c2743";
                        goto compare;
                      case 454:
                        so=155;
                        resword = "8bd5c45a48b3dc1eb94ff25e05186996";
                        goto compare;
                      case 455:
                        so=351;
                        resword = "68b7a61b75541b8b4a98d434edad5ac2";
                        goto compare;
                      case 468:
                        so=143;
                        resword = "9e29e3b779f506e023a41ddd985ac66e";
                        goto compare;
                      case 470:
                        so=198;
                        resword = "cb1d1e08d52897f62579c5d4356aad43";
                        goto compare;
                      case 475:
                        so=140;
                        resword = "6d790a628abc680b4bfb856cc60ee028";
                        goto compare;
                      case 478:
                        so=232;
                        resword = "8a37271ac6e2cebe6da17c5b68011443";
                        goto compare;
                      case 482:
                        so=9;
                        resword = "d483acdde5a49d9ad21bc83a456401b5";
                        goto compare;
                      case 483:
                        so=209;
                        resword = "1d10a6476876791f62aa29a34b652830";
                        goto compare;
                      case 490:
                        so=135;
                        resword = "555da9921c70004153b47bf24eb638bc";
                        goto compare;
                      case 494:
                        so=62;
                        resword = "4b0518bb0f1a1a72749631af13648703";
                        goto compare;
                      case 505:
                        so=173;
                        resword = "c776e08279ed57528cbc9575e5a7b051";
                        goto compare;
                      case 524:
                        so=299;
                        resword = "6287b352397690454ab0363f151afaa2";
                        goto compare;
                      case 530:
                        so=19;
                        resword = "2d6d3d61a616fc2a12f0c8f546a546d1";
                        goto compare;
                      case 537:
                        so=298;
                        resword = "b7dba6b60c07d1cff3a9b3920aa671fa";
                        goto compare;
                      case 538:
                        so=418;
                        resword = "07616404a0aa764f96184140aee43970";
                        goto compare;
                      case 539:
                        so=356;
                        resword = "5d3e140474ad9794cbbf4545d67843de";
                        goto compare;
                      case 542:
                        so=279;
                        resword = "b9bdaafa65a801715bfcae5847dcbbad";
                        goto compare;
                      case 547:
                        so=196;
                        resword = "4e71f62418d4e5be45aa42c34104c3bd";
                        goto compare;
                      case 574:
                        so=83;
                        resword = "7b1bead30cbd84fa00299cea47f7235d";
                        goto compare;
                      case 577:
                        so=399;
                        resword = "4d7905bd87840f886a55a3e9b120b248";
                        goto compare;
                      case 583:
                        so=185;
                        resword = "da70f3884e594f86e520195ea266ad91";
                        goto compare;
                      case 616:
                        so=339;
                        resword = "ae5db39af18e70c93fb534368006450b";
                        goto compare;
                      case 618:
                        so=261;
                        resword = "80a29fbba864d140bba429d2057f8435";
                        goto compare;
                      case 633:
                        so=231;
                        resword = "3b36bf0e12c29ce4952871afd89f071e";
                        goto compare;
                      case 642:
                        so=321;
                        resword = "4c777d1f6d2f96caef8705825d0d16ff";
                        goto compare;
                      case 660:
                        so=221;
                        resword = "0b48ecb5e7ffaf72f121d2876e0a529b";
                        goto compare;
                      case 677:
                        so=62;
                        resword = "edd3fe12c6e2d6e4d461bc4dac898e3a";
                        goto compare;
                      case 698:
                        so=216;
                        resword = "ab284413501f0acf261dab1f0339a489";
                        goto compare;
                      case 720:
                        so=399;
                        resword = "2fab0b58e73be9568fbd85612b52f937";
                        goto compare;
                      case 731:
                        so=398;
                        resword = "0510806c3a0c0706ded7df057ee2ce00";
                        goto compare;
                      case 734:
                        so=127;
                        resword = "c19ebce4b873e68348b56fb23a54f4f8";
                        goto compare;
                      case 735:
                        so=233;
                        resword = "879d103b5719073e04ba4bad5fee5a8b";
                        goto compare;
                      case 748:
                        so=219;
                        resword = "25884cc6e76225ee60d37ab69c3a944f";
                        goto compare;
                      case 757:
                        so=142;
                        resword = "be51dc3f88d6c9f45a1ffac8080c622f";
                        goto compare;
                      case 766:
                        so=198;
                        resword = "ef42b3b87cb4bbdf78b921935e4451d6";
                        goto compare;
                      case 773:
                        so=297;
                        resword = "2d395a2df6da90cb28a240cb3cf34da6";
                        goto compare;
                      case 780:
                        so=343;
                        resword = "9dc758c927020ef2d460869e8d4c446b";
                        goto compare;
                      case 787:
                        so=279;
                        resword = "bbc23b9dffcc5d85f72383683e407950";
                        goto compare;
                      case 788:
                        so=37;
                        resword = "90ce97773662c7b4aba0e154957c25b3";
                        goto compare;
                      case 790:
                        so=414;
                        resword = "a213d3d555c1c354b4d6517603aa0243";
                        goto compare;
                      case 794:
                        so=195;
                        resword = "3e4edb06f95d246287140ec144fac428";
                        goto compare;
                      case 802:
                        so=21;
                        resword = "ad395794f858889c34adbc0b03d16c69";
                        goto compare;
                      case 811:
                        so=48;
                        resword = "02803f6bb8cf588011d25d3fb9f531d1";
                        goto compare;
                      case 819:
                        so=17;
                        resword = "36a7ad3c2edd7d6467b9fed37f2762b7";
                        goto compare;
                      case 840:
                        so=193;
                        resword = "dc9dbceb48f2c22d43f42ccfaa683115";
                        goto compare;
                      case 870:
                        so=253;
                        resword = "5bc33345a0b461b6af2decc251274c5d";
                        goto compare;
                      case 886:
                        so=113;
                        resword = "4537ff6130796db7ffba0182966d1661";
                        goto compare;
                      case 887:
                        so=392;
                        resword = "bf30842580ab04c6ee28df27d2841cd8";
                        goto compare;
                      case 908:
                        so=76;
                        resword = "48d0e1dfdeaa1ff0d8bf366d6abd33d1";
                        goto compare;
                      case 919:
                        so=295;
                        resword = "79dcd8df1661a3e19c28d327a203e3f3";
                        goto compare;
                      case 923:
                        so=211;
                        resword = "c36ec6a30ca5faae21a4991d23425952";
                        goto compare;
                      case 926:
                        so=304;
                        resword = "9870714d80afe3f74024a159ebe5e0fc";
                        goto compare;
                      case 932:
                        so=302;
                        resword = "651bc2266e09bcfeaa22ff10daf0c3f1";
                        goto compare;
                      case 933:
                        so=294;
                        resword = "38877e371631d868c628f732428d9c19";
                        goto compare;
                      case 935:
                        so=352;
                        resword = "81ac46fef7b380d7c1a2ba6fefdc4854";
                        goto compare;
                      case 938:
                        so=257;
                        resword = "18672a3e75196a762a2cae332bae2e4b";
                        goto compare;
                      case 945:
                        so=7;
                        resword = "b3c3541f6e9a055e64d0e5e8d8ca8178";
                        goto compare;
                      case 946:
                        so=30;
                        resword = "3546ad88f1d815ac03de5836fc6d6de7";
                        goto compare;
                      case 948:
                        so=207;
                        resword = "d48dd97dd066531605afbf9d054d6c02";
                        goto compare;
                      case 953:
                        so=70;
                        resword = "23c0bb69e17df6cdbad274711c1fb24b";
                        goto compare;
                      case 963:
                        so=267;
                        resword = "efc6d0180d46da78dab7c71966c76496";
                        goto compare;
                      case 976:
                        so=55;
                        resword = "b55e1fc1ea6730dcb8234ee16be5e92e";
                        goto compare;
                      case 982:
                        so=52;
                        resword = "9ea5f1a9265c7c3ef14a336b562a5a98";
                        goto compare;
                      case 988:
                        so=101;
                        resword = "62322291be606610e92a35c1f9986f22";
                        goto compare;
                      case 1017:
                        so=252;
                        resword = "0e0bd94ebc8906a1f8d32f3a60d7e3f9";
                        goto compare;
                      case 1028:
                        so=237;
                        resword = "ba00ed0d893f8b7b1ed82656a27d16a7";
                        goto compare;
                      case 1041:
                        so=359;
                        resword = "0a80d7e21e79ad061cd9b4c6505a4ed4";
                        goto compare;
                      case 1045:
                        so=38;
                        resword = "dcbed2227c042552a2e42d77e25c1497";
                        goto compare;
                      case 1047:
                        so=181;
                        resword = "8a55de74bf020bf6f1b899add767e8cc";
                        goto compare;
                      case 1050:
                        so=352;
                        resword = "8db4c2d3da1c1cc4d6f1f953fdc4ec0a";
                        goto compare;
                      case 1063:
                        so=199;
                        resword = "dd11716231d81d59bdab0cddd1060d37";
                        goto compare;
                      case 1065:
                        so=243;
                        resword = "6f55b5cc01b97f12458b2acdb73767a8";
                        goto compare;
                      case 1067:
                        so=329;
                        resword = "4d49002395306af72df1a7b0af93b698";
                        goto compare;
                      case 1072:
                        so=231;
                        resword = "cdd2f993e63b26d7d843beb4755b8acd";
                        goto compare;
                      case 1079:
                        so=170;
                        resword = "949bfc130f2142d13812c7e24321a659";
                        goto compare;
                      case 1082:
                        so=120;
                        resword = "1567ec336fc9fc122012b2f2258195c7";
                        goto compare;
                      case 1095:
                        so=409;
                        resword = "99136ead1d2ac018811d1798dc93a492";
                        goto compare;
                      case 1101:
                        so=404;
                        resword = "0f8c4840c36c3e66c5163d92f4ed3e01";
                        goto compare;
                      case 1109:
                        so=155;
                        resword = "878fd162a840c5cc2ea192afdee30156";
                        goto compare;
                      case 1132:
                        so=91;
                        resword = "e4b5fba4f096bff20f78a9b8cd44ad9a";
                        goto compare;
                      case 1156:
                        so=114;
                        resword = "70d0db1ce8d25cea021f3e46e86de00a";
                        goto compare;
                      case 1163:
                        so=362;
                        resword = "91ce4bb11bfff8ce0bad59f12bb932b6";
                        goto compare;
                      case 1164:
                        so=166;
                        resword = "c7065a119f299e70f1abb4a4bde3f123";
                        goto compare;
                      case 1166:
                        so=279;
                        resword = "c70d5e8ef20eae6720f0bf2ed0d38283";
                        goto compare;
                      case 1167:
                        so=150;
                        resword = "001758699d12098e4b1cde24772300db";
                        goto compare;
                      case 1178:
                        so=222;
                        resword = "9c6f09777a9290ea9cff4abb1500a932";
                        goto compare;
                      case 1187:
                        so=17;
                        resword = "61d7da8dedc40445f1fba80337f3119c";
                        goto compare;
                      case 1190:
                        so=396;
                        resword = "ac35bf2f93e0c7df86b7cf7f5938a25b";
                        goto compare;
                      case 1192:
                        so=34;
                        resword = "e560db92e263ea6ddd10304e2bb7450f";
                        goto compare;
                      case 1200:
                        so=150;
                        resword = "cd4f8d6bdc6eb1c06b9f23880fef0ade";
                        goto compare;
                      case 1208:
                        so=326;
                        resword = "9baf332419c742b1617d333a29abac9e";
                        goto compare;
                      case 1209:
                        so=344;
                        resword = "91a8437458b7a51c2cb6ad82a0b7063a";
                        goto compare;
                      case 1235:
                        so=322;
                        resword = "d0ce3a7300d965b7232e1a925bfc75bb";
                        goto compare;
                      case 1256:
                        so=146;
                        resword = "9a224b18edf29285d3283bea808548a9";
                        goto compare;
                      case 1257:
                        so=409;
                        resword = "e87280d2470d46e9ff1834495262dab0";
                        goto compare;
                      case 1261:
                        so=133;
                        resword = "4b4eda4abedc71b7e2bbb3c6b876a9cc";
                        goto compare;
                      case 1271:
                        so=343;
                        resword = "a047094867ac318d461fb5582de471fe";
                        goto compare;
                      case 1276:
                        so=224;
                        resword = "88ddb3ab94d4662accbadc8edf27888e";
                        goto compare;
                      case 1298:
                        so=43;
                        resword = "3148d96e9f860388beda098ee71bbc46";
                        goto compare;
                      case 1305:
                        so=323;
                        resword = "2fa39f48073eb39898a33c540bea5237";
                        goto compare;
                      case 1313:
                        so=396;
                        resword = "29a781a24a187f8a8daf51e369e26935";
                        goto compare;
                      case 1317:
                        so=245;
                        resword = "90d503c35185351ee7fbe1ac321097ca";
                        goto compare;
                      case 1318:
                        so=307;
                        resword = "6a76e6f6c362d1d9632ee3491d0585f0";
                        goto compare;
                      case 1330:
                        so=103;
                        resword = "7e39e58ae1de775d66ddd2a98bc304c4";
                        goto compare;
                      case 1342:
                        so=162;
                        resword = "0c2132e9365823902410e2a808345871";
                        goto compare;
                      case 1352:
                        so=292;
                        resword = "3c11d8e722ed97bfe914b2f8ae9e9574";
                        goto compare;
                      case 1356:
                        so=339;
                        resword = "bc0cdf6da86eb01f6f1643e278025762";
                        goto compare;
                      case 1357:
                        so=252;
                        resword = "533fcae8b0dc6a3d561e4b16ecfce74c";
                        goto compare;
                      case 1360:
                        so=36;
                        resword = "3995b3fcbd3a6b442a2a6e76d1c30e1b";
                        goto compare;
                      case 1365:
                        so=8;
                        resword = "cda6485ff4e00d02c97ae53246470abd";
                        goto compare;
                      case 1367:
                        so=103;
                        resword = "caa5c67a9d018a31909ab10fc8e8c63b";
                        goto compare;
                      case 1368:
                        so=215;
                        resword = "449547320602a0c84ab044948b0c8e37";
                        goto compare;
                      case 1370:
                        so=355;
                        resword = "30d9ba7b8f44d92a8e27707c7541d191";
                        goto compare;
                      case 1371:
                        so=354;
                        resword = "d4628835491a6710ffd5479f208cbbff";
                        goto compare;
                      case 1374:
                        so=213;
                        resword = "c32d5cee95e2d3995bb013673260da09";
                        goto compare;
                      case 1383:
                        so=143;
                        resword = "02c975ee6e1fd38438d65256805d707e";
                        goto compare;
                      case 1399:
                        so=70;
                        resword = "cbbbd4c2c7fc7caa23f15606c9047e9b";
                        goto compare;
                      case 1403:
                        so=154;
                        resword = "c572121bb23f292862282281a7aeedd3";
                        goto compare;
                      case 1418:
                        so=59;
                        resword = "e27fd09bf62194d3f4a3f6530465270d";
                        goto compare;
                      case 1433:
                        so=28;
                        resword = "e646c59905bae784702e950f63a91821";
                        goto compare;
                      case 1439:
                        so=171;
                        resword = "dbd54d05e820ce2a1cff86e2c6eaef26";
                        goto compare;
                      case 1442:
                        so=24;
                        resword = "2c4161de6d4f392d4f1e63b056151c79";
                        goto compare;
                      case 1447:
                        so=333;
                        resword = "6339d05c5989022695186a4943e02081";
                        goto compare;
                      case 1461:
                        so=320;
                        resword = "b8bd1a104e0c5c7bfabd61086780c2a4";
                        goto compare;
                      case 1462:
                        so=338;
                        resword = "6a262e60befd430c7017ed3840346814";
                        goto compare;
                      case 1465:
                        so=408;
                        resword = "6bbf593b7e40fa74668a6276b4f1812d";
                        goto compare;
                      case 1473:
                        so=65;
                        resword = "415882d9ce9ee0fe4da9f6e89622e14b";
                        goto compare;
                      case 1474:
                        so=27;
                        resword = "a759b71206ac36bd35221e832e5000e4";
                        goto compare;
                      case 1477:
                        so=250;
                        resword = "4c77d918bb5dfa72e8fa20f4be03b1c6";
                        goto compare;
                      case 1490:
                        so=378;
                        resword = "44444be458f082c70223f08d25d2ca3d";
                        goto compare;
                      case 1491:
                        so=103;
                        resword = "f986fd1359a13fec68857068d79c9b96";
                        goto compare;
                      case 1492:
                        so=402;
                        resword = "9e063269401e3dd8fb1dca1477b192f5";
                        goto compare;
                      case 1506:
                        so=384;
                        resword = "91969df329fcb79a8223c723162c4529";
                        goto compare;
                      case 1523:
                        so=285;
                        resword = "fe3474d2617d7b6b9f89a5a2fb295efa";
                        goto compare;
                      case 1524:
                        so=202;
                        resword = "eb5104a842e0eb91e6a5d27c004e5bbb";
                        goto compare;
                      case 1534:
                        so=353;
                        resword = "7f35ab10345eac954faccf5fb5619405";
                        goto compare;
                      case 1538:
                        so=81;
                        resword = "bccc5b0fec5477316119635d029c061d";
                        goto compare;
                      case 1540:
                        so=227;
                        resword = "ccae4df582aeb10dd67dbd8e7c9c393d";
                        goto compare;
                      case 1550:
                        so=138;
                        resword = "5ea1289a57ee43cee424eddba355de62";
                        goto compare;
                      case 1552:
                        so=69;
                        resword = "157ddce70115b19b291dd66aa64b5a44";
                        goto compare;
                      case 1553:
                        so=242;
                        resword = "f04ca9bb2b499f78ea6b3433cfe62eac";
                        goto compare;
                      case 1557:
                        so=276;
                        resword = "6fbe166073d32d06c8592d59c7d4ca1b";
                        goto compare;
                      case 1566:
                        so=367;
                        resword = "c50bdd60072eae999c18dde16bde5e9b";
                        goto compare;
                      case 1567:
                        so=403;
                        resword = "c221c79d6d8700b55015e0cebe07e7a3";
                        goto compare;
                      case 1573:
                        so=229;
                        resword = "8c719e75e416ac6f3f2870c157cc961d";
                        goto compare;
                      case 1575:
                        so=346;
                        resword = "cdb1d7129fa9a53e5c6fcbd855fae88b";
                        goto compare;
                      case 1583:
                        so=310;
                        resword = "2ca044879ee50ba57fa4b6ec0d633d71";
                        goto compare;
                      case 1584:
                        so=328;
                        resword = "2aac55e6e1602420e01c363c811ff72d";
                        goto compare;
                      case 1588:
                        so=233;
                        resword = "9e893bcd9a289b54022797ad9d1a7d60";
                        goto compare;
                      case 1606:
                        so=91;
                        resword = "f373ae0d9b0a94c8d4e4f9d0d916371b";
                        goto compare;
                      case 1608:
                        so=334;
                        resword = "7a9e123f71ed490936d0e9e1f6c8d997";
                        goto compare;
                      case 1609:
                        so=187;
                        resword = "0215eb9dd870ff65281b4f4b4cc5bd5e";
                        goto compare;
                      case 1613:
                        so=377;
                        resword = "ad4d065195c57881f5b1b5d4bc158209";
                        goto compare;
                      case 1621:
                        so=227;
                        resword = "f6433eff0007e74abf4038bdf18777c7";
                        goto compare;
                      case 1630:
                        so=408;
                        resword = "1da7ebe9c1cb3aacccf05f7a9aa008ef";
                        goto compare;
                      case 1638:
                        so=297;
                        resword = "b4f4baae7a08e46d239983ef13827a2f";
                        goto compare;
                      case 1646:
                        so=93;
                        resword = "28f1de083ba648d03b9d0bac1d847462";
                        goto compare;
                      case 1667:
                        so=52;
                        resword = "99bed6957baa054ce2b7ef100ea88378";
                        goto compare;
                      case 1670:
                        so=158;
                        resword = "de4cfb7f395717850bdf242fd5841c5b";
                        goto compare;
                      case 1671:
                        so=69;
                        resword = "f439a8b4e00821c0dc9a5fb5021f4a9a";
                        goto compare;
                      case 1673:
                        so=169;
                        resword = "f4c2afc12a001cfd6a495fcd5a68ac42";
                        goto compare;
                      case 1675:
                        so=338;
                        resword = "6dbe1ca31922dc84cb86d4776d10090f";
                        goto compare;
                      case 1681:
                        so=355;
                        resword = "f969e324b3982a6eb39a602a15320184";
                        goto compare;
                      case 1682:
                        so=248;
                        resword = "c67205fe1d278035bb1b7c7cb26f8a79";
                        goto compare;
                      case 1684:
                        so=331;
                        resword = "02bc06f6a40063fb3a125818fef4f49b";
                        goto compare;
                      case 1686:
                        so=280;
                        resword = "434850bb5be8ac73d212bad90f555a89";
                        goto compare;
                      case 1687:
                        so=405;
                        resword = "cd25bfac4fa3e84e01eb27ddc3a8bda8";
                        goto compare;
                      case 1692:
                        so=185;
                        resword = "0d0039fb29480882b0123898575f0ad7";
                        goto compare;
                      case 1693:
                        so=234;
                        resword = "53b205b90a37d03ccc2f3bfed3d8f62d";
                        goto compare;
                      case 1696:
                        so=40;
                        resword = "f246564ea720e8601445587530338bb4";
                        goto compare;
                      case 1715:
                        so=334;
                        resword = "e5858b360ba39a071bae97354fbecdc2";
                        goto compare;
                      case 1721:
                        so=185;
                        resword = "f0002eac9912acec2ded75886c945a85";
                        goto compare;
                      case 1726:
                        so=107;
                        resword = "f489e103b85c738e979f6b8f391a218b";
                        goto compare;
                      case 1728:
                        so=324;
                        resword = "fe76c9e3d0c8f4f1076e3f98d2f0d23a";
                        goto compare;
                      case 1731:
                        so=68;
                        resword = "f22944c071f39b66b09006cad65c3ad9";
                        goto compare;
                      case 1740:
                        so=75;
                        resword = "b777cea52eb8e0ccfe1c1098460fd7de";
                        goto compare;
                      case 1747:
                        so=87;
                        resword = "90bebaac579f5677d5b695a76bcdb8d9";
                        goto compare;
                      case 1749:
                        so=406;
                        resword = "d3d287f7677b7fa46717e0f66134f41e";
                        goto compare;
                      case 1750:
                        so=30;
                        resword = "ecb90d2151b7240f455ec8b4d90f072f";
                        goto compare;
                      case 1752:
                        so=72;
                        resword = "79fb61b0f451fbfe1364942b73a02773";
                        goto compare;
                      case 1761:
                        so=8;
                        resword = "af5c59effd829d312b1051ee0d9c8885";
                        goto compare;
                      case 1762:
                        so=25;
                        resword = "5ddc327ceb867a3b92aaabf328359551";
                        goto compare;
                      case 1783:
                        so=60;
                        resword = "464b23fdefc4e25f5719af3001196973";
                        goto compare;
                      case 1784:
                        so=389;
                        resword = "d5bfc429c458716b5db9dfd3225927a4";
                        goto compare;
                      case 1793:
                        so=348;
                        resword = "fe46542a8a244bcb038793a4e60504b6";
                        goto compare;
                      case 1805:
                        so=31;
                        resword = "dcbfa80204e926e452e4fb3e6972a9f3";
                        goto compare;
                      case 1806:
                        so=237;
                        resword = "a459a130b9dd48aa7ed7a7c0e3466214";
                        goto compare;
                      case 1812:
                        so=90;
                        resword = "dfd61f67f94d858fa6a0ee6880383fc0";
                        goto compare;
                      case 1818:
                        so=57;
                        resword = "135780cdb9fe08351019357ca8f1a273";
                        goto compare;
                      case 1821:
                        so=415;
                        resword = "801e599b569598e2b5d12331c52dd347";
                        goto compare;
                      case 1835:
                        so=26;
                        resword = "f12b9c2b1bfed92e1a6a9230f2e9cae9";
                        goto compare;
                      case 1855:
                        so=181;
                        resword = "3eb75b6387fea34a87ac8c31da1165a7";
                        goto compare;
                      case 1862:
                        so=295;
                        resword = "42a897a46db489a9fdad303d3a9a3149";
                        goto compare;
                      case 1869:
                        so=266;
                        resword = "c6c1ec01a646b1f618173162b8aa08ab";
                        goto compare;
                      case 1872:
                        so=245;
                        resword = "9bb4a63d102242b629bf26d2591d4993";
                        goto compare;
                      case 1874:
                        so=247;
                        resword = "2bd475f2a18b2907e51e8a34e08b72b5";
                        goto compare;
                      case 1906:
                        so=416;
                        resword = "3567b63cbc50704ea0d8797712150ad0";
                        goto compare;
                      case 1921:
                        so=73;
                        resword = "50f2c986abe84c004499c7fd0e6cc51e";
                        goto compare;
                      case 1931:
                        so=202;
                        resword = "9ab4bf1e819de5ff4ea2f16b6a174d7c";
                        goto compare;
                      case 1945:
                        so=404;
                        resword = "a5f44b03ea4f95b306ea3ebb4e38291d";
                        goto compare;
                      case 1961:
                        so=282;
                        resword = "98683a10631f74eeaad66c408c69b04d";
                        goto compare;
                      case 1973:
                        so=191;
                        resword = "fe191d9aca7771f3cb7b24f2c849e1d0";
                        goto compare;
                      case 1976:
                        so=370;
                        resword = "f30635c9d2431899895e9da43230bf4b";
                        goto compare;
                      case 1987:
                        so=397;
                        resword = "215614260faa6bc54bddd134d519a40b";
                        goto compare;
                      case 2002:
                        so=90;
                        resword = "aafca900586cc2b58b698abc35c60d47";
                        goto compare;
                      case 2007:
                        so=341;
                        resword = "f76108a339b6cc847a8043bf1e665f4b";
                        goto compare;
                      case 2016:
                        so=412;
                        resword = "6203524fb134a74a97da9339ea660edc";
                        goto compare;
                      case 2038:
                        so=345;
                        resword = "fac60a84d999db46534d20aaeda52d67";
                        goto compare;
                      case 2043:
                        so=157;
                        resword = "7af025f210cefec91b4a5686ee2c3c66";
                        goto compare;
                      case 2055:
                        so=327;
                        resword = "5f6c0b61efffb9fd7bda3fb0476d1bf5";
                        goto compare;
                      case 2058:
                        so=11;
                        resword = "c28d83bd7d04fb3ee6a0fe868b88cbad";
                        goto compare;
                      case 2061:
                        so=153;
                        resword = "e493e092c62664f034d4a6a6002e27e0";
                        goto compare;
                      case 2071:
                        so=340;
                        resword = "61582a6a41de6c439a2e592dd3b8ab5b";
                        goto compare;
                      case 2078:
                        so=87;
                        resword = "51b06a2dace156c107222fd986155607";
                        goto compare;
                      case 2083:
                        so=402;
                        resword = "f1c0216528651ec84d42198b0502856e";
                        goto compare;
                      case 2101:
                        so=26;
                        resword = "e5107885871a98a532d14d089d75fda0";
                        goto compare;
                      case 2108:
                        so=212;
                        resword = "c61d0100e441ce096fafc6f6fc05d6d6";
                        goto compare;
                      case 2125:
                        so=414;
                        resword = "cd8cf2fd32a9abaa5cad6a437d7c6593";
                        goto compare;
                      case 2130:
                        so=8;
                        resword = "cf2efa37a0807bf70ea78f3d7e948b4f";
                        goto compare;
                      case 2143:
                        so=376;
                        resword = "723f3042cbfa2d364fde325299e952f4";
                        goto compare;
                      case 2148:
                        so=403;
                        resword = "9f24f6a203929ab51020033575341d01";
                        goto compare;
                      case 2151:
                        so=55;
                        resword = "67ad6a5c1b99f5b20ef51303fe677e31";
                        goto compare;
                      case 2156:
                        so=305;
                        resword = "50f4d910eb96885626ea94274a2065e7";
                        goto compare;
                      case 2171:
                        so=55;
                        resword = "22f98301ab8a89f87744692d450e6ae6";
                        goto compare;
                      case 2173:
                        so=264;
                        resword = "286cc465d6e7456864092ed52ef9e5f3";
                        goto compare;
                      case 2179:
                        so=331;
                        resword = "4d5c15c647d2852853b024318565bb10";
                        goto compare;
                      case 2181:
                        so=193;
                        resword = "0594167a96b3b979100c03f8b803e90b";
                        goto compare;
                      case 2183:
                        so=265;
                        resword = "f2c63eb5fd9f89070d52b4fc49c7791d";
                        goto compare;
                      case 2190:
                        so=59;
                        resword = "a2f08ec3494cc0f0f75f567bd0f0830d";
                        goto compare;
                      case 2191:
                        so=169;
                        resword = "9b899592855bb619152aba8acc35ade8";
                        goto compare;
                      case 2193:
                        so=197;
                        resword = "9f84b17f45975d723f2db4b8feb36afe";
                        goto compare;
                      case 2197:
                        so=106;
                        resword = "2ba241ff9b68e4562c1a6c0d9b8eb8b0";
                        goto compare;
                      case 2203:
                        so=257;
                        resword = "377d28a87950e854471ab4d48c1d4017";
                        goto compare;
                      case 2208:
                        so=64;
                        resword = "fe1ece10297be9839671bc08a319b271";
                        goto compare;
                      case 2210:
                        so=204;
                        resword = "742cccff511c4312800e237b204a4bf2";
                        goto compare;
                      case 2235:
                        so=92;
                        resword = "d3cd411e5238ead6422eec2a666707d0";
                        goto compare;
                      case 2248:
                        so=153;
                        resword = "6d2ecd5cc6bc9b53b3a6756c10071241";
                        goto compare;
                      case 2251:
                        so=205;
                        resword = "e842eb9d1d18d83961df6c280cbbc05d";
                        goto compare;
                      case 2256:
                        so=280;
                        resword = "53f983ac1a8b5183376d5b556307a410";
                        goto compare;
                      case 2261:
                        so=306;
                        resword = "ad3e102695694485c71075ea4ecda24e";
                        goto compare;
                      case 2269:
                        so=160;
                        resword = "9a830a1b40d9bfa47dda72d0b1137e4b";
                        goto compare;
                      case 2271:
                        so=291;
                        resword = "8c58030ddca27b77d320a60e04facf26";
                        goto compare;
                      case 2273:
                        so=184;
                        resword = "9f96e531425858c5962c51d4eb1834d0";
                        goto compare;
                      case 2282:
                        so=391;
                        resword = "f551dfd997bad9e41aee85620ebe09f5";
                        goto compare;
                      case 2291:
                        so=175;
                        resword = "d4f15caa596776aa998ec0695ed9ab62";
                        goto compare;
                      case 2295:
                        so=403;
                        resword = "5fc44e522cbb85f06cd38083c5c28133";
                        goto compare;
                      case 2296:
                        so=382;
                        resword = "f149680232a79c636f7d0429900d4e6d";
                        goto compare;
                      case 2306:
                        so=362;
                        resword = "51f2067c0ab0ccd9e7816f4e957c024a";
                        goto compare;
                      case 2308:
                        so=343;
                        resword = "3baf94e2de65f34fe0a7d1d9c6626e7f";
                        goto compare;
                      case 2310:
                        so=147;
                        resword = "ef1045cf5ed035f7d72839a3bc885dd7";
                        goto compare;
                      case 2315:
                        so=182;
                        resword = "00abd965072afb4e30d9dbe2ddaedfb1";
                        goto compare;
                      case 2326:
                        so=248;
                        resword = "f71b1173d199adb7f4e1c56feb1a9b8d";
                        goto compare;
                      case 2346:
                        so=109;
                        resword = "d9f19b78697d6066f06b8b46cdbd6e3f";
                        goto compare;
                      case 2353:
                        so=344;
                        resword = "b59d60a63b1621e2dfd4f70d3b28ede9";
                        goto compare;
                      case 2387:
                        so=83;
                        resword = "5d2e8b31f675244aa615361207198775";
                        goto compare;
                      case 2390:
                        so=358;
                        resword = "a6a22fb41d9315b33dd7bf10ab75b18e";
                        goto compare;
                      case 2391:
                        so=200;
                        resword = "1081ff9d15405e51570574cc9372ad3f";
                        goto compare;
                      case 2412:
                        so=353;
                        resword = "ca7ef2cd28920c34e110cbb2df9bef65";
                        goto compare;
                      case 2420:
                        so=276;
                        resword = "7ef2b6eccf3af4675a51155db1dce6e0";
                        goto compare;
                      case 2425:
                        so=56;
                        resword = "ef7696150ac5651c0d24d8ee2a3146e3";
                        goto compare;
                      case 2428:
                        so=29;
                        resword = "3e741eca3466925e1a0433ad19d3389e";
                        goto compare;
                      case 2430:
                        so=260;
                        resword = "ce5449d26a9a269a581a26253ac8b4fc";
                        goto compare;
                      case 2432:
                        so=178;
                        resword = "497b177f3942c9035bd627bd61167592";
                        goto compare;
                      case 2441:
                        so=35;
                        resword = "528158314d59063d8d00ef60e27061b6";
                        goto compare;
                      case 2442:
                        so=164;
                        resword = "3e6b6e5a5456a0939b0f89e98a8cbdb9";
                        goto compare;
                      case 2451:
                        so=67;
                        resword = "d6f260958d404a75f48dc0a02f78025b";
                        goto compare;
                      case 2469:
                        so=267;
                        resword = "91814121380275aeafdc95e3b4fc16da";
                        goto compare;
                      case 2471:
                        so=4;
                        resword = "d9f68e04ca64997852659929708264fe";
                        goto compare;
                      case 2473:
                        so=390;
                        resword = "43048cceae5066104edf143750b8befe";
                        goto compare;
                    }
                }
              else
                {
                  if (key < 8734)
                    {
                      switch (key - 6347)
                        {
                          case 0:
                            so=318;
                        resword = "cda7f411ed5ed6e3ac6396e1ab2a87e4";
                            goto compare;
                          case 24:
                            so=124;
                        resword = "2da7ff5ddecaae1a22b4040cb1d43c26";
                            goto compare;
                          case 26:
                            so=185;
                        resword = "36066923c7c364abe20376ac8c3f2b04";
                            goto compare;
                          case 34:
                            so=3;
                        resword = "92494c8ef07991eee4db70187d2c2332";
                            goto compare;
                          case 43:
                            so=417;
                        resword = "bd714b55c97aca8cf8d8d45bf971ec3d";
                            goto compare;
                          case 48:
                            so=119;
                        resword = "12c3ad74465bd4738d080f06a107fd5b";
                            goto compare;
                          case 57:
                            so=284;
                        resword = "abfc684b0d0f4e796d7e94bc4888784a";
                            goto compare;
                          case 58:
                            so=0;
                        resword = "85c70ecde45eb00f42d2668e46e1cf97";
                            goto compare;
                          case 60:
                            so=233;
                        resword = "784567a4684e00385edf232c64b8d44a";
                            goto compare;
                          case 61:
                            so=213;
                        resword = "96a42d8aaf9c7c5e71239b02045a9983";
                            goto compare;
                          case 71:
                            so=317;
                        resword = "c7bdc742881565e5dd55e870bae66fe4";
                            goto compare;
                          case 78:
                            so=195;
                        resword = "ff14fe0676cb4c7bbc8f7ffa395400b8";
                            goto compare;
                          case 79:
                            so=401;
                        resword = "989e4f64df8bca333cdccc26485d4ae8";
                            goto compare;
                          case 97:
                            so=201;
                        resword = "a2bcd0fc64c06a2315dd6951333a75dc";
                            goto compare;
                          case 106:
                            so=275;
                        resword = "1155258c126e8625cc2033a58f913109";
                            goto compare;
                          case 116:
                            so=255;
                        resword = "56265621f9699de77e07027eae0622d9";
                            goto compare;
                          case 118:
                            so=101;
                        resword = "d2d33a1c29097572d8d5b217fa859e2b";
                            goto compare;
                          case 121:
                            so=303;
                        resword = "f3897627fc1799355bf12af9ae0f4868";
                            goto compare;
                          case 131:
                            so=354;
                        resword = "502d96096c99f32c3fd0d74bfce9d009";
                            goto compare;
                          case 137:
                            so=217;
                        resword = "9ca9bf7f240ac80445b1b5e1f9be084e";
                            goto compare;
                          case 140:
                            so=384;
                        resword = "2ea7e0c7cb39b234262e729016592c4e";
                            goto compare;
                          case 141:
                            so=358;
                        resword = "775f181a333170b5e815ba11cad34fde";
                            goto compare;
                          case 150:
                            so=383;
                        resword = "f2d8c1293ce4870a817188596b195941";
                            goto compare;
                          case 155:
                            so=120;
                        resword = "4e91abb79dbacff0ccdc6975e65a0bc1";
                            goto compare;
                          case 158:
                            so=372;
                        resword = "ebb16b8ddb9a577916ae66d845084d34";
                            goto compare;
                          case 161:
                            so=149;
                        resword = "f0179858e73483638784b1ed476a3a67";
                            goto compare;
                          case 163:
                            so=187;
                        resword = "5efefe33c676d2747990901b8f21050e";
                            goto compare;
                          case 165:
                            so=179;
                        resword = "41a91664f6052ce618aa320bc3896651";
                            goto compare;
                          case 166:
                            so=216;
                        resword = "5a10301ed2fddb2c640c157d14ffa684";
                            goto compare;
                          case 171:
                            so=191;
                        resword = "85fe0881182959893598c30ac2dca4af";
                            goto compare;
                          case 188:
                            so=399;
                        resword = "3ca0f5c10414d44b5727018811aa50e7";
                            goto compare;
                          case 201:
                            so=63;
                        resword = "938d6383d23c9ce468229e0a31672314";
                            goto compare;
                          case 208:
                            so=153;
                        resword = "4346cf49ba47596cf2d84b8945b66774";
                            goto compare;
                          case 226:
                            so=180;
                        resword = "e46e870eeb395dcec3dfd34b381e153f";
                            goto compare;
                          case 240:
                            so=378;
                        resword = "0fb49d34fce6de8e7927a8ff6a3ce59b";
                            goto compare;
                          case 241:
                            so=348;
                        resword = "9c3fc06b6aff882a88a95aaa21bdc3ea";
                            goto compare;
                          case 246:
                            so=219;
                        resword = "f63760be7b5954381d439598a3624553";
                            goto compare;
                          case 263:
                            so=383;
                        resword = "0d178a4423032978c7267f329d359001";
                            goto compare;
                          case 268:
                            so=83;
                        resword = "2dc12b8993e483ab5bdbb589b7424e9a";
                            goto compare;
                          case 273:
                            so=255;
                        resword = "5e6d3cbb745b200244dcb7c70420f5ae";
                            goto compare;
                          case 288:
                            so=406;
                        resword = "95de87861e34894f6122b9d6883747b1";
                            goto compare;
                          case 289:
                            so=56;
                        resword = "357186d3991bfb6596cfb02e5c9e5dd7";
                            goto compare;
                          case 293:
                            so=330;
                        resword = "b57895c47faf349d0ecd6f77bb7b8bec";
                            goto compare;
                          case 294:
                            so=176;
                        resword = "0831bc0c807b4082d0ce835ca21a0f10";
                            goto compare;
                          case 297:
                            so=163;
                        resword = "c26708f81467b932851c979f43ee7c65";
                            goto compare;
                          case 301:
                            so=398;
                        resword = "d0f98657d46a1ea1f67453209e3788dc";
                            goto compare;
                          case 303:
                            so=219;
                        resword = "e50d8a6c482459939624f2050df4595f";
                            goto compare;
                          case 312:
                            so=82;
                        resword = "93354b10c1f3a0a9f71c1363cc1ee84e";
                            goto compare;
                          case 318:
                            so=349;
                        resword = "9d883b5d6ec78f38fa2fd8a2b2652618";
                            goto compare;
                          case 324:
                            so=102;
                        resword = "15919849b21f34f1d7cb7a003a67ef19";
                            goto compare;
                          case 326:
                            so=138;
                        resword = "9e6e94ad6f45019444dcc1640e042924";
                            goto compare;
                          case 347:
                            so=143;
                        resword = "e7325bf030e90038dcd33a3aeaec83c2";
                            goto compare;
                          case 348:
                            so=15;
                        resword = "f4d10696bec847b8eee801f4df405ab0";
                            goto compare;
                          case 360:
                            so=288;
                        resword = "66455d3be9b36739d324185fb358097f";
                            goto compare;
                          case 372:
                            so=81;
                        resword = "6d60b49b49ad8bb7fb108563a24c0dd4";
                            goto compare;
                          case 376:
                            so=336;
                        resword = "a70f4ee3ffd274ddc6dda2cceaf40d02";
                            goto compare;
                          case 377:
                            so=243;
                        resword = "bc356ef3fbb967e56429466986cbbdfe";
                            goto compare;
                          case 379:
                            so=100;
                        resword = "c6d0e2dfdd3e354bb41ec1bc4aac8cd1";
                            goto compare;
                          case 388:
                            so=412;
                        resword = "43099e862b51e991d4daf0b47bca5cef";
                            goto compare;
                          case 394:
                            so=29;
                        resword = "28967f3c9c1e6b36a3c7791d83fc2744";
                            goto compare;
                          case 403:
                            so=166;
                        resword = "9f4daa1ccdd0d6ce03a63ec813c0ecad";
                            goto compare;
                          case 410:
                            so=282;
                        resword = "7d7ff8a907a71ce1cf2be6bc2f8fa30b";
                            goto compare;
                          case 416:
                            so=80;
                        resword = "04f7a23d06da5278a18162a73b1294d4";
                            goto compare;
                          case 417:
                            so=255;
                        resword = "3d87e6150c21c386ab18f0d58f04c705";
                            goto compare;
                          case 418:
                            so=335;
                        resword = "2c0d93db133704f2a321a7f3077a7385";
                            goto compare;
                          case 423:
                            so=233;
                        resword = "7b473459e11f713f25d72a129f24d45e";
                            goto compare;
                          case 429:
                            so=267;
                        resword = "e2bd9a19038eedf199b81dbf53477605";
                            goto compare;
                          case 439:
                            so=75;
                        resword = "1222901a2488c2191ccf49bd436513e7";
                            goto compare;
                          case 458:
                            so=106;
                        resword = "b5929bf60dd665b6883d536da9050ae5";
                            goto compare;
                          case 459:
                            so=401;
                        resword = "a89b74507dcd0981b235f716c67239ec";
                            goto compare;
                          case 474:
                            so=67;
                        resword = "99f1ee37eb087aaa6673209e123bb74c";
                            goto compare;
                          case 476:
                            so=254;
                        resword = "f49f3370aaa83d2420e70ea33bcc05d1";
                            goto compare;
                          case 480:
                            so=418;
                        resword = "86c873606cdf7b4b70036eee0e58bfaf";
                            goto compare;
                          case 481:
                            so=47;
                        resword = "2b8fb2bbf838012652dabe3b61e6c3bd";
                            goto compare;
                          case 486:
                            so=305;
                        resword = "f197597239e70fa4b2911e1e8b6a74fe";
                            goto compare;
                          case 501:
                            so=390;
                        resword = "ced1876086dd6e0eaf1db4472fd84dc1";
                            goto compare;
                          case 503:
                            so=226;
                        resword = "9bd3edc51f2dc3465f2e29f9986afa12";
                            goto compare;
                          case 512:
                            so=350;
                        resword = "e20d6e6837cdc0313d11317fcdf2dda2";
                            goto compare;
                          case 513:
                            so=310;
                        resword = "7e93bf834ea0e8d118cb8210a1d5d664";
                            goto compare;
                          case 515:
                            so=300;
                        resword = "5fb769ebbc9ebf3d1fa4d3be9de85877";
                            goto compare;
                          case 517:
                            so=350;
                        resword = "1852a815e1473d850c0e3eadd43b040a";
                            goto compare;
                          case 519:
                            so=62;
                        resword = "61ac72f491f9e3660611a9213104704d";
                            goto compare;
                          case 525:
                            so=82;
                        resword = "4ed8704b9cf307062c1c7ea0f1cad6ae";
                            goto compare;
                          case 533:
                            so=135;
                        resword = "33cc93d7d2469797f1ce04402ba9dfa0";
                            goto compare;
                          case 534:
                            so=41;
                        resword = "37d98d6a8eeedd5f2addc71defb41a79";
                            goto compare;
                          case 540:
                            so=335;
                        resword = "94b6e10a59a6bc78311ced5694ceeb84";
                            goto compare;
                          case 542:
                            so=102;
                        resword = "e8b1492f39e88c33dd126d04bd44f136";
                            goto compare;
                          case 543:
                            so=238;
                        resword = "7e700d944bab3808ecc641042588c5a1";
                            goto compare;
                          case 556:
                            so=69;
                        resword = "17dfcd05f07f149ea62b2c5c773c55b0";
                            goto compare;
                          case 563:
                            so=82;
                        resword = "f58568601bd21a71d38f76873686306c";
                            goto compare;
                          case 569:
                            so=379;
                        resword = "16435199a605621ed8c93e099eb3c395";
                            goto compare;
                          case 574:
                            so=116;
                        resword = "e8de542cb2035eaaaa1a0711bd1e210b";
                            goto compare;
                          case 581:
                            so=192;
                        resword = "f6a2564a5e2f939df64e1acd2fa12b76";
                            goto compare;
                          case 585:
                            so=95;
                        resword = "a169db623e9211896f02f71258e567f6";
                            goto compare;
                          case 586:
                            so=392;
                        resword = "13c32a758a3e7e2de8c9a6baf4a404d9";
                            goto compare;
                          case 595:
                            so=85;
                        resword = "0b7ba468291809604001fe8203041034";
                            goto compare;
                          case 605:
                            so=265;
                        resword = "7e083ab355a4955d45cf2ac0d2d860a5";
                            goto compare;
                          case 618:
                            so=237;
                        resword = "7b03677a2f061247e80e7a667db608a2";
                            goto compare;
                          case 626:
                            so=138;
                        resword = "f3a41ccf5a7d7d48b2e78a99ad972616";
                            goto compare;
                          case 630:
                            so=34;
                        resword = "8efc373cedcdffc81ef3b1bbcf7d8930";
                            goto compare;
                          case 635:
                            so=398;
                        resword = "167b9120425cc194673580fd530c98cd";
                            goto compare;
                          case 648:
                            so=172;
                        resword = "9efc8f16f9bfeec30c9ae627a99d6b03";
                            goto compare;
                          case 652:
                            so=51;
                        resword = "6659146650e0188195ddcb5029d16e88";
                            goto compare;
                          case 654:
                            so=292;
                        resword = "25293b211f235d8ef7cfa3f6d89a12bc";
                            goto compare;
                          case 660:
                            so=255;
                        resword = "6c45efc95fcfb3efd9add53a209ec837";
                            goto compare;
                          case 671:
                            so=324;
                        resword = "fd80017c7a37336e53911290a166a212";
                            goto compare;
                          case 676:
                            so=71;
                        resword = "3cf04aac9746cdf9b187549d47e2386b";
                            goto compare;
                          case 680:
                            so=290;
                        resword = "5e7bcaef1868bf2e84c99597155ef030";
                            goto compare;
                          case 682:
                            so=370;
                        resword = "7e2c9b048618ba78bb32eaeb5e846005";
                            goto compare;
                          case 688:
                            so=135;
                        resword = "61b0f12db3bc84ec8b2af78ca6f606a9";
                            goto compare;
                          case 694:
                            so=361;
                        resword = "8810e6caadd7d610e9ce8f2d92551e85";
                            goto compare;
                          case 696:
                            so=112;
                        resword = "61b5c9aac98dcee1a5b774be4a32aa11";
                            goto compare;
                          case 700:
                            so=190;
                        resword = "f5446247d7b33bd9aeb0c4324ea753d3";
                            goto compare;
                          case 704:
                            so=417;
                        resword = "5c15ac6e0e1786b7291e2c59877f6831";
                            goto compare;
                          case 705:
                            so=30;
                        resword = "4d746bf5eccfb5ed79229f289ff494c5";
                            goto compare;
                          case 722:
                            so=242;
                        resword = "ea56714bc4ffeae3b4df283034cc57ad";
                            goto compare;
                          case 725:
                            so=183;
                        resword = "cd8c5e580a01fc02a3263600df9e0539";
                            goto compare;
                          case 736:
                            so=365;
                        resword = "8808c608de9162e96dccd37bda2c40ac";
                            goto compare;
                          case 743:
                            so=405;
                        resword = "dc8ff705efa00f46bd23272796bb6123";
                            goto compare;
                          case 744:
                            so=77;
                        resword = "c5150ca526ac259c4e1ba0f914bd4f9d";
                            goto compare;
                          case 752:
                            so=337;
                        resword = "f7793544daecaf9febfb7a379700e07d";
                            goto compare;
                          case 774:
                            so=99;
                        resword = "ec50c49a11ba4fb30123ba539fde71de";
                            goto compare;
                          case 793:
                            so=57;
                        resword = "fad4fbf588d93947fe532c71a6d50dc4";
                            goto compare;
                          case 796:
                            so=132;
                        resword = "12466f44cbf53ec9f8355e6f67da25c6";
                            goto compare;
                          case 797:
                            so=53;
                        resword = "8c53d08c5f2bc5db69d99e0cb6da9f1d";
                            goto compare;
                          case 800:
                            so=269;
                        resword = "f8ab8a1dcbfcbd8560515429866563b9";
                            goto compare;
                          case 805:
                            so=45;
                        resword = "f4ab6d395f9c26507f56672b82dbaff3";
                            goto compare;
                          case 808:
                            so=33;
                        resword = "3db07b62639016947926d7ec8c658f48";
                            goto compare;
                          case 811:
                            so=109;
                        resword = "2469450eeb6da7d4b63c0d6321fd73f7";
                            goto compare;
                          case 818:
                            so=381;
                        resword = "a100f0ed1142d01562c86e5cbd7a161f";
                            goto compare;
                          case 819:
                            so=139;
                        resword = "8dd2b0601ca26f89621b4a0224d2e7ab";
                            goto compare;
                          case 827:
                            so=63;
                        resword = "7bc851467a8f57c44b0c21469ae6f00f";
                            goto compare;
                          case 838:
                            so=390;
                        resword = "2bfc2861061da73703fb2b63718639b7";
                            goto compare;
                          case 883:
                            so=189;
                        resword = "788987dd7d0cb6667e336ab44e1a6e99";
                            goto compare;
                          case 887:
                            so=302;
                        resword = "fa5ef1243dda943ee55bfe32d6b7fee6";
                            goto compare;
                          case 889:
                            so=139;
                        resword = "715323d5a15d945caa09300c424b6b4d";
                            goto compare;
                          case 891:
                            so=50;
                        resword = "18ffcd336561f49ba3e4e5ee65248cfc";
                            goto compare;
                          case 899:
                            so=238;
                        resword = "50799d38ba34a1c616cc3a8414cb1f23";
                            goto compare;
                          case 901:
                            so=19;
                        resword = "f6a4c9b02ea2fd3ce754d78a903b7541";
                            goto compare;
                          case 908:
                            so=259;
                        resword = "807cfd76479a3459833ec97422de438d";
                            goto compare;
                          case 911:
                            so=145;
                        resword = "b142779040dbea0743c029e04afad977";
                            goto compare;
                          case 913:
                            so=165;
                        resword = "ef12431f86817758bcd9405aaec60311";
                            goto compare;
                          case 916:
                            so=280;
                        resword = "61f277685e5cca60fa88731c8797804e";
                            goto compare;
                          case 921:
                            so=191;
                        resword = "820468120317e074c5328a17cc23a4be";
                            goto compare;
                          case 922:
                            so=363;
                        resword = "7ec0a2e39eab7ca2343a633e3d921057";
                            goto compare;
                          case 931:
                            so=267;
                        resword = "6864fddc803811b32303c7c691276403";
                            goto compare;
                          case 933:
                            so=16;
                        resword = "c2fc860a2bf8c32e7d7eeb8abf0fc8cf";
                            goto compare;
                          case 937:
                            so=39;
                        resword = "bfacbf7f75b7354b0bd493e536a8088b";
                            goto compare;
                          case 940:
                            so=39;
                        resword = "fd7b785b2cb163fc46e334635242c82a";
                            goto compare;
                          case 941:
                            so=391;
                        resword = "0e195d913ef0369dc2c796a05410cb41";
                            goto compare;
                          case 946:
                            so=139;
                        resword = "153ad9b5fe6443625d7b3a71c70b8499";
                            goto compare;
                          case 968:
                            so=170;
                        resword = "23d08b36f54081570d05f4a164497eb2";
                            goto compare;
                          case 994:
                            so=78;
                        resword = "93916c17d4aea115a8015167a69a376b";
                            goto compare;
                          case 995:
                            so=116;
                        resword = "33535326e908a9369bc2cd772374730b";
                            goto compare;
                          case 996:
                            so=258;
                        resword = "c6f1668e191a139bf38a16ea3df39534";
                            goto compare;
                          case 1001:
                            so=248;
                        resword = "c6f31f44c5dff05d33715c2dded6dcba";
                            goto compare;
                          case 1005:
                            so=403;
                        resword = "9dbbb586de6c1df382ae4a80247ac5e3";
                            goto compare;
                          case 1006:
                            so=111;
                        resword = "066a86c55902a9eb1a9efeb40a4815bf";
                            goto compare;
                          case 1015:
                            so=194;
                        resword = "42578c4c97fdf42b0c1903ebb5dc58ca";
                            goto compare;
                          case 1023:
                            so=366;
                        resword = "8ef7565ec2ef5e90c8843a9630f28298";
                            goto compare;
                          case 1028:
                            so=117;
                        resword = "1f104ac710fef665870bb9dac94bfb01";
                            goto compare;
                          case 1029:
                            so=64;
                        resword = "94f6cae8dca0b595cf5bafa68ffe0074";
                            goto compare;
                          case 1035:
                            so=7;
                        resword = "055203896c7655fa15cd6c886d76ae2e";
                            goto compare;
                          case 1050:
                            so=373;
                        resword = "a141f83afbc5b9984b3b57dafae28829";
                            goto compare;
                          case 1056:
                            so=75;
                        resword = "da89285b3c167401c60978f5d22cf943";
                            goto compare;
                          case 1058:
                            so=199;
                        resword = "864ca923630fbbafa23ed67b82583bcb";
                            goto compare;
                          case 1061:
                            so=206;
                        resword = "6840123482f07a0e020b34bea75aa185";
                            goto compare;
                          case 1084:
                            so=228;
                        resword = "715d60a27ccdfe2215d5f666e250fcf9";
                            goto compare;
                          case 1086:
                            so=254;
                        resword = "8a94c3eb6905d5eb163adce065943204";
                            goto compare;
                          case 1093:
                            so=375;
                        resword = "f9bcdb9bcab131423d579a1786840554";
                            goto compare;
                          case 1097:
                            so=127;
                        resword = "aeffd35690ce2674dee58655fd174050";
                            goto compare;
                          case 1116:
                            so=68;
                        resword = "9678c01451ac9d36980b08f8b2de323b";
                            goto compare;
                          case 1121:
                            so=306;
                        resword = "6137925010439094e8dc64b737dc17e5";
                            goto compare;
                          case 1141:
                            so=1;
                        resword = "c4f41853d99a2137c8e1ecd575ba0b2a";
                            goto compare;
                          case 1147:
                            so=319;
                        resword = "395128434dca2a407a3e2da6599a148e";
                            goto compare;
                          case 1154:
                            so=241;
                        resword = "2b326182c08ccb44a3cac050d3c1a26e";
                            goto compare;
                          case 1176:
                            so=98;
                        resword = "1b9805d5ec9e74b2b7cc36869f46b2c5";
                            goto compare;
                          case 1181:
                            so=16;
                        resword = "5207155b32ba9eba99013dca7c1bfe80";
                            goto compare;
                          case 1184:
                            so=334;
                        resword = "da24b88671187ac466c9ad18255f1e93";
                            goto compare;
                          case 1185:
                            so=128;
                        resword = "2fc1bde7119bb7024a022645fdec16d2";
                            goto compare;
                          case 1188:
                            so=13;
                        resword = "1f2d0131595254a5f8d70eab3f70d332";
                            goto compare;
                          case 1196:
                            so=202;
                        resword = "caf007f3343d646c1468ca473911cb55";
                            goto compare;
                          case 1209:
                            so=262;
                        resword = "8112fa2a267340ded4c3ca87bdd11037";
                            goto compare;
                          case 1210:
                            so=367;
                        resword = "f1c509719abf0127eb99d0ce1c4d2b1c";
                            goto compare;
                          case 1221:
                            so=148;
                        resword = "d0c45377bdfc39c086cd0ddcce0c5e41";
                            goto compare;
                          case 1222:
                            so=232;
                        resword = "ac3cb05bc684158bee09c508e674cc7e";
                            goto compare;
                          case 1228:
                            so=386;
                        resword = "3e4abb8e44629ded5393650107666148";
                            goto compare;
                          case 1232:
                            so=77;
                        resword = "ae7a77a7ab48639fa843df467c5cba16";
                            goto compare;
                          case 1236:
                            so=134;
                        resword = "567a1901cb0c3c8bec4e9fd781a14257";
                            goto compare;
                          case 1246:
                            so=144;
                        resword = "6a14e50c439c0358b205a0f53d8e664b";
                            goto compare;
                          case 1248:
                            so=46;
                        resword = "724ecac8b9beac0b29325a42496a5eb5";
                            goto compare;
                          case 1252:
                            so=406;
                        resword = "573397466fabd24e813571e2733f3955";
                            goto compare;
                          case 1253:
                            so=26;
                        resword = "15ac96fd22f0e6abd304e920f32d34c0";
                            goto compare;
                          case 1255:
                            so=309;
                        resword = "23abacdb295c5016120d65ca54906e7a";
                            goto compare;
                          case 1260:
                            so=369;
                        resword = "e00be05ff0d9cd17c90d6f4b07db999a";
                            goto compare;
                          case 1266:
                            so=222;
                        resword = "f793f54c15983bcfe6bc2419a7766d11";
                            goto compare;
                          case 1268:
                            so=416;
                        resword = "bb31ffa351909a1cb3384f6879e11377";
                            goto compare;
                          case 1273:
                            so=114;
                        resword = "74b7b2ebbd40281796dd72bcdd7fb2de";
                            goto compare;
                          case 1276:
                            so=381;
                        resword = "e62204de052a2a3b300254374ada45ce";
                            goto compare;
                          case 1291:
                            so=15;
                        resword = "556a4361d5426ef059e66dd6585b18f5";
                            goto compare;
                          case 1306:
                            so=18;
                        resword = "a7ff48be040ab8d050760cbc10d0a227";
                            goto compare;
                          case 1310:
                            so=323;
                        resword = "e6df5edf2bd892c7602bb7442962cb10";
                            goto compare;
                          case 1311:
                            so=129;
                        resword = "05e0b5aabc9b9516b1968296bab84022";
                            goto compare;
                          case 1313:
                            so=39;
                        resword = "7b141a365ea7490223317774ce050503";
                            goto compare;
                          case 1331:
                            so=115;
                        resword = "286a0366220d018d0359904ea4fce4d3";
                            goto compare;
                          case 1339:
                            so=190;
                        resword = "880e65aa0d8336992dc2d332033a86af";
                            goto compare;
                          case 1343:
                            so=351;
                        resword = "71f7d942718c8f91c15166e28b128e1e";
                            goto compare;
                          case 1347:
                            so=328;
                        resword = "cfd15f5345df2baebb2980058c67458f";
                            goto compare;
                          case 1376:
                            so=162;
                        resword = "8b89c20f789568909c08a8dba5c71207";
                            goto compare;
                          case 1393:
                            so=262;
                        resword = "c46c2093ad9b8353cc03053b0e89fc34";
                            goto compare;
                          case 1396:
                            so=167;
                        resword = "20e0104bfd81828ba08af73c44e102d1";
                            goto compare;
                          case 1400:
                            so=210;
                        resword = "9f15671cb035eec55229c948a913fd86";
                            goto compare;
                          case 1404:
                            so=380;
                        resword = "011e40bd6c55fde9f5cea4eb268e8c18";
                            goto compare;
                          case 1405:
                            so=226;
                        resword = "b3e8b30c56fa7bdbff626303c7cf9a98";
                            goto compare;
                          case 1406:
                            so=276;
                        resword = "806a4087df5dd0849169e8775707a04b";
                            goto compare;
                          case 1415:
                            so=151;
                        resword = "b4e86b3445c870909f4145aae6d9b039";
                            goto compare;
                          case 1418:
                            so=283;
                        resword = "7d553ac9dd195c67142235554710b032";
                            goto compare;
                          case 1423:
                            so=288;
                        resword = "61a8a2ada435774e90d1613c962c5b74";
                            goto compare;
                          case 1431:
                            so=129;
                        resword = "dac19a8bf925ec4c61c9e77fbd2f0300";
                            goto compare;
                          case 1433:
                            so=253;
                        resword = "04254cc45ef388ab670d1ebfde610c61";
                            goto compare;
                          case 1438:
                            so=392;
                        resword = "b6fde518e61659c16856b97993a7f2a4";
                            goto compare;
                          case 1450:
                            so=112;
                        resword = "efa771432266db8094a3f165f81e1803";
                            goto compare;
                          case 1461:
                            so=179;
                        resword = "f66d337908e9424bd6faec20a08eb007";
                            goto compare;
                          case 1483:
                            so=91;
                        resword = "c6c7c76d4c9e8ca8b1d10b0090a94a4a";
                            goto compare;
                          case 1503:
                            so=205;
                        resword = "4091b1629c89d878fc017fd0a1c7ad2b";
                            goto compare;
                          case 1505:
                            so=382;
                        resword = "5edd93fa5d43cafe07dd81736dfa6581";
                            goto compare;
                          case 1511:
                            so=61;
                        resword = "d3fdd67d68d8db136b82087692367175";
                            goto compare;
                          case 1531:
                            so=189;
                        resword = "3ab76727866b6a1534df7341f9db6d7c";
                            goto compare;
                          case 1532:
                            so=275;
                        resword = "e77738263901c3bfbfdb09903040fa31";
                            goto compare;
                          case 1540:
                            so=251;
                        resword = "a14a25ba693c737c75660c64531c8b13";
                            goto compare;
                          case 1555:
                            so=3;
                        resword = "58eb876011c79b498346a684c5cb7ab3";
                            goto compare;
                          case 1558:
                            so=225;
                        resword = "f6dfd1a411014e4fa4825345f7179058";
                            goto compare;
                          case 1564:
                            so=20;
                        resword = "47f42a94763f9ebbc09eec0158e237ef";
                            goto compare;
                          case 1567:
                            so=194;
                        resword = "ad2890d6179569e9230529aa77d53207";
                            goto compare;
                          case 1571:
                            so=45;
                        resword = "e6f270e317fd75ee51fe155ba96c69d3";
                            goto compare;
                          case 1586:
                            so=381;
                        resword = "3ae30ec08b9acfef368e4db0a1befda4";
                            goto compare;
                          case 1625:
                            so=385;
                        resword = "94b7ab0f7f8c4e08b919a60062977a65";
                            goto compare;
                          case 1640:
                            so=165;
                        resword = "43a71847b0c50d223e2a029986599d06";
                            goto compare;
                          case 1645:
                            so=265;
                        resword = "97933c94ed6c45dcb50eda29871f64fe";
                            goto compare;
                          case 1656:
                            so=157;
                        resword = "0d44eb854199ccdb3f051c5f24482c4b";
                            goto compare;
                          case 1659:
                            so=208;
                        resword = "7c57fb275285075af3d9b55086f0053b";
                            goto compare;
                          case 1672:
                            so=45;
                        resword = "1cd51e06805650862520e0cad0ec36f1";
                            goto compare;
                          case 1674:
                            so=282;
                        resword = "f7354c95ac686cec435f0393d5550b61";
                            goto compare;
                          case 1685:
                            so=131;
                        resword = "7f31ce5bffdab0ee353785bdb5a31d1c";
                            goto compare;
                          case 1693:
                            so=308;
                        resword = "5005dda2741e47b9aa0655f52a998d1b";
                            goto compare;
                          case 1698:
                            so=346;
                        resword = "0ee61d389f22136c3e852b7c3483445f";
                            goto compare;
                          case 1701:
                            so=231;
                        resword = "0917c8398ab198ed923b3642e0f077a1";
                            goto compare;
                          case 1713:
                            so=97;
                        resword = "658877a96917ecbb473f7be4065f27cb";
                            goto compare;
                          case 1720:
                            so=95;
                        resword = "61fb8572336e7b8e71fb1443c3a7263b";
                            goto compare;
                          case 1731:
                            so=81;
                        resword = "6304211303c702cfb03256102e78a180";
                            goto compare;
                          case 1732:
                            so=380;
                        resword = "005a7c86aba82ad8f76ebddf073c243e";
                            goto compare;
                          case 1753:
                            so=201;
                        resword = "73076b3c1e5fc0c46d315d127e1fc887";
                            goto compare;
                          case 1766:
                            so=38;
                        resword = "16e482e09b82196448e4728781664d9d";
                            goto compare;
                          case 1771:
                            so=128;
                        resword = "6844af54e496bddc823aa6cafbe26e56";
                            goto compare;
                          case 1774:
                            so=407;
                        resword = "0ddfb3fa4d066cd37e1ed7778525c305";
                            goto compare;
                          case 1778:
                            so=14;
                        resword = "5aecd48636a4b80e476b7ac558e3ed35";
                            goto compare;
                          case 1779:
                            so=243;
                        resword = "7657581a0aca9b09bd087ca834975101";
                            goto compare;
                          case 1786:
                            so=384;
                        resword = "5ae0865b150b4e719c6f46ec10af3b4e";
                            goto compare;
                          case 1790:
                            so=137;
                        resword = "4cc6f11a87e7ba0822daeb1e693ec016";
                            goto compare;
                          case 1794:
                            so=156;
                        resword = "04a01098033560e811ce4e10630f2a21";
                            goto compare;
                          case 1801:
                            so=415;
                        resword = "9cb2e5410fdd364140203a45f1d29d67";
                            goto compare;
                          case 1806:
                            so=124;
                        resword = "89bf235ac6d849d391df34ebe1efcbe5";
                            goto compare;
                          case 1811:
                            so=339;
                        resword = "287fba9bdfdf4b6ed73e2ce6721095fc";
                            goto compare;
                          case 1828:
                            so=402;
                        resword = "9b2ba258b675873bd108c6ba3c10630d";
                            goto compare;
                          case 1829:
                            so=229;
                        resword = "9b14eb7e6bab060e9b0ad6f0115f7043";
                            goto compare;
                          case 1833:
                            so=338;
                        resword = "4d02c5f6f911ef7c73dba5abdd5c654e";
                            goto compare;
                          case 1834:
                            so=293;
                        resword = "e244a00d2c0ca45874cdd3fc504accda";
                            goto compare;
                          case 1859:
                            so=121;
                        resword = "fa994a4a9222161a00a429f9ef64fe61";
                            goto compare;
                          case 1863:
                            so=182;
                        resword = "8275af5350b163194608d838d31f711b";
                            goto compare;
                          case 1872:
                            so=411;
                        resword = "ffbb682b8329b3a25b97f2d986a2764e";
                            goto compare;
                          case 1877:
                            so=151;
                        resword = "9a01d5f6cdb05ae26ecfd35c9eb3f419";
                            goto compare;
                          case 1885:
                            so=225;
                        resword = "a48fa387cf214fb9f833e984fb90f7be";
                            goto compare;
                          case 1898:
                            so=72;
                        resword = "ac82fd34552c64fd8fc29837c1d1fb9e";
                            goto compare;
                          case 1899:
                            so=14;
                        resword = "6479631c670622317cc2005ed5127aa6";
                            goto compare;
                          case 1911:
                            so=352;
                        resword = "064747cc64de7231c13e184178c7382f";
                            goto compare;
                          case 1914:
                            so=274;
                        resword = "59a38108bb50d4cc97c5eea8e60fd970";
                            goto compare;
                          case 1921:
                            so=307;
                        resword = "62ff42650c00b4186c496da70fe642ee";
                            goto compare;
                          case 1932:
                            so=376;
                        resword = "585fcecf889f3cf7c0050f4c6ac1b328";
                            goto compare;
                          case 1939:
                            so=276;
                        resword = "c1d776a17b26106b2a1f5a2e7309fcff";
                            goto compare;
                          case 1951:
                            so=63;
                        resword = "1b477722d9b20aab55069a0d87ee59d6";
                            goto compare;
                          case 1959:
                            so=61;
                        resword = "c99065e9a6204ad3bbc755a5ade2807c";
                            goto compare;
                          case 1970:
                            so=385;
                        resword = "af0900b34f8e04714bcc1c4afbadff98";
                            goto compare;
                          case 1971:
                            so=130;
                        resword = "8d816faf610faeed380a8ef25e7fd8f1";
                            goto compare;
                          case 1983:
                            so=358;
                        resword = "b2eefa108a6c3fc58084beea18c9a76c";
                            goto compare;
                          case 1995:
                            so=152;
                        resword = "73a803adba931589bc36265452ae1f29";
                            goto compare;
                          case 2021:
                            so=270;
                        resword = "42343197d9d5ae9ef1c0d65d3c638515";
                            goto compare;
                          case 2022:
                            so=314;
                        resword = "e0569fc05836efaa3b07447d660b0c5b";
                            goto compare;
                          case 2033:
                            so=164;
                        resword = "b1b2d2cdf7d4bacf510ed2ad44327838";
                            goto compare;
                          case 2041:
                            so=187;
                        resword = "026548c0b7dbd911e3c9c8468bf08bac";
                            goto compare;
                          case 2051:
                            so=115;
                        resword = "01f89a610ee186b3f0aab56a10695f88";
                            goto compare;
                          case 2057:
                            so=146;
                        resword = "17e0e5109d4e3e1d989bae351b0545dd";
                            goto compare;
                          case 2073:
                            so=405;
                        resword = "438848c116808d1b42c2b778a16e4a31";
                            goto compare;
                          case 2101:
                            so=188;
                        resword = "e34612fa05530af84c3dcd27ff1def3f";
                            goto compare;
                          case 2103:
                            so=103;
                        resword = "d6e80c0d97dd3be2047e01c57b21d038";
                            goto compare;
                          case 2113:
                            so=0;
                        resword = "08da44085b48adc6b59b58829b0de255";
                            goto compare;
                          case 2119:
                            so=340;
                        resword = "952a4be9269432a10e94ef48c81b0d01";
                            goto compare;
                          case 2121:
                            so=163;
                        resword = "10a24ceae0b48f2f5330212e5b2ac174";
                            goto compare;
                          case 2127:
                            so=159;
                        resword = "fb5de5619b52bcdae147d1e939c81dbb";
                            goto compare;
                          case 2131:
                            so=364;
                        resword = "637ad0d177f8c7faa09b771b02f2df9a";
                            goto compare;
                          case 2142:
                            so=340;
                        resword = "c253321a7fa2454b6f062c89c923dc16";
                            goto compare;
                          case 2145:
                            so=360;
                        resword = "cbb5e96322b5835b24a4b9db68ebe2c0";
                            goto compare;
                          case 2162:
                            so=391;
                        resword = "f74d3e1837ec04dc91fb3b709f53beda";
                            goto compare;
                          case 2168:
                            so=385;
                        resword = "4361b1e517c2be15a833092d29edf376";
                            goto compare;
                          case 2170:
                            so=186;
                        resword = "40bfebba528b02d0752cc73bcb1d439a";
                            goto compare;
                          case 2173:
                            so=268;
                        resword = "1835337881f08ac32332507c5193249d";
                            goto compare;
                          case 2176:
                            so=244;
                        resword = "d2d3882b02a076d9cfc6bd6df6be4838";
                            goto compare;
                          case 2181:
                            so=268;
                        resword = "f6ceffff50ebc0e3e4a28ba00d3269f9";
                            goto compare;
                          case 2184:
                            so=330;
                        resword = "a8f7e30dc25969888cbfd37fb9eeb770";
                            goto compare;
                          case 2185:
                            so=79;
                        resword = "bdbf011127edca385121f569e9e31930";
                            goto compare;
                          case 2188:
                            so=400;
                        resword = "e4c65c2c66cfcdad0533017d4038b52f";
                            goto compare;
                          case 2195:
                            so=15;
                        resword = "41f8fe076f8fbec614fca8fea964163f";
                            goto compare;
                          case 2197:
                            so=405;
                        resword = "2f54bdf6866c6433b4c27e98241d3e46";
                            goto compare;
                          case 2204:
                            so=131;
                        resword = "aea8d563379fbeb49c3e01bef12e4633";
                            goto compare;
                          case 2205:
                            so=350;
                        resword = "b215485cb69c4a29f936df1a0f001aee";
                            goto compare;
                          case 2214:
                            so=374;
                        resword = "26b191a2a162853fd3c06abe6b8a863e";
                            goto compare;
                          case 2228:
                            so=378;
                        resword = "6f8133c1de592383bc036c2ca75029ac";
                            goto compare;
                          case 2236:
                            so=215;
                        resword = "0aa118f9310cf8ee953fb70d53102d19";
                            goto compare;
                          case 2246:
                            so=13;
                        resword = "dd8278586f3e11a6910989ee0a1b59d3";
                            goto compare;
                          case 2248:
                            so=84;
                        resword = "ad26eb0c5592dc798ecf34715c324c2e";
                            goto compare;
                          case 2259:
                            so=325;
                        resword = "e0490fb4262a858bdccb216f2fee7402";
                            goto compare;
                          case 2266:
                            so=205;
                        resword = "4346a7f9168c97288cc3540722803c9c";
                            goto compare;
                          case 2270:
                            so=96;
                        resword = "466814139ff702c7aa3a76f6a433ac42";
                            goto compare;
                          case 2273:
                            so=303;
                        resword = "12d755cb09112496310b44d14037f76a";
                            goto compare;
                          case 2274:
                            so=153;
                        resword = "f9905df61c8e96f9d62c48e91d6d7bd2";
                            goto compare;
                          case 2275:
                            so=308;
                        resword = "4e2e5bb42165dfae3f004dc548b73e98";
                            goto compare;
                          case 2278:
                            so=357;
                        resword = "86ec7f22c5c04a47555f2e87a008da16";
                            goto compare;
                          case 2311:
                            so=289;
                        resword = "e0ff57783056d57a70e9fd9bedd2c8ab";
                            goto compare;
                          case 2345:
                            so=86;
                        resword = "61cc5c08f7b1594a0f38a7a6e71d8a45";
                            goto compare;
                          case 2364:
                            so=400;
                        resword = "8af68ac31f2e96c440a39f64b971b82b";
                            goto compare;
                          case 2368:
                            so=316;
                        resword = "9052e3794b3679b325c9dec6271512d1";
                            goto compare;
                          case 2371:
                            so=109;
                        resword = "ec870b0fc088b29350d4ba86454164c5";
                            goto compare;
                          case 2376:
                            so=282;
                        resword = "ccf3392abc8e1c21e073d2725ad914df";
                            goto compare;
                          case 2377:
                            so=277;
                        resword = "1a5a7e3927a9d3265558c88cac51f234";
                            goto compare;
                          case 2380:
                            so=80;
                        resword = "98509c9597b4ca705c383879c3c61040";
                            goto compare;
                          case 2385:
                            so=342;
                        resword = "b8da8f0050fcfe8726edd5ee5e922a66";
                            goto compare;
                        }
                    }
                  else
                    {
                      switch (key - 8734)
                        {
                          case 0:
                            so=47;
                        resword = "9798f796a269cf12e3389b30f8dd794a";
                            goto compare;
                          case 10:
                            so=74;
                        resword = "aee329ef737ac00314f16bf76e1f8560";
                            goto compare;
                          case 14:
                            so=10;
                        resword = "db278ef7346776da1c0d53c46bea6755";
                            goto compare;
                          case 16:
                            so=45;
                        resword = "79b660600832afd214305f6ef6ef92fb";
                            goto compare;
                          case 27:
                            so=262;
                        resword = "f080544a9fabd92e8d2f8e6af0789502";
                            goto compare;
                          case 32:
                            so=141;
                        resword = "212d3cd33f40fe2a61cc0fba76fbd707";
                            goto compare;
                          case 44:
                            so=332;
                        resword = "e00a65dce23e795af578f1e65f2c7ec0";
                            goto compare;
                          case 62:
                            so=189;
                        resword = "dc04fdaaf9a39a56bec92673a63373b4";
                            goto compare;
                          case 69:
                            so=154;
                        resword = "9e2a1fe5d2e6a3e86f4d6e5463cb8c75";
                            goto compare;
                          case 79:
                            so=283;
                        resword = "29aaa75b8745a8b74a48856ad94850bb";
                            goto compare;
                          case 84:
                            so=17;
                        resword = "df554d04b2c42d7508dd09de0fc8999c";
                            goto compare;
                          case 92:
                            so=350;
                        resword = "7cf8e7cb479891ed17b928b86e601fa3";
                            goto compare;
                          case 103:
                            so=256;
                        resword = "7dc47a97be891556903993789455b89d";
                            goto compare;
                          case 104:
                            so=123;
                        resword = "2aeecb0f19e238e63febc3bf635ff9b6";
                            goto compare;
                          case 112:
                            so=176;
                        resword = "1bf22fdbea8aa03b16a54aad01cc64b8";
                            goto compare;
                          case 116:
                            so=314;
                        resword = "f6b55bf07fa660d4a66959d172dda46d";
                            goto compare;
                          case 123:
                            so=131;
                        resword = "62ab1178456f55b3f307a49f428864f6";
                            goto compare;
                          case 136:
                            so=180;
                        resword = "c9df4c7cb7f75f5a4edd09cf85addb4b";
                            goto compare;
                          case 139:
                            so=335;
                        resword = "c5fd902d8c4f9adc6c9bff83744af5e8";
                            goto compare;
                          case 154:
                            so=304;
                        resword = "cbb3bbd154edfa008fdcf422416cbc51";
                            goto compare;
                          case 160:
                            so=269;
                        resword = "c7b6404280a5dbb941d49b4fbdbeeee0";
                            goto compare;
                          case 174:
                            so=251;
                        resword = "e03ff12178baddf3dd0953eb719fa359";
                            goto compare;
                          case 219:
                            so=274;
                        resword = "ea27f66eb03e38044d01a86e66b8a7aa";
                            goto compare;
                          case 241:
                            so=177;
                        resword = "f6ccc067e003ed98b22a662dea948c69";
                            goto compare;
                          case 252:
                            so=389;
                        resword = "80a9d036ad3ada5cf7c943f39cc2fbb4";
                            goto compare;
                          case 272:
                            so=184;
                        resword = "04f139bb9013668fce2b43955e63ba0a";
                            goto compare;
                          case 277:
                            so=197;
                        resword = "8e5af24472f4cd1bd85468b5d010b31a";
                            goto compare;
                          case 284:
                            so=149;
                        resword = "82b3349668bf88d24e3ea49d8d8f9e27";
                            goto compare;
                          case 286:
                            so=160;
                        resword = "11154247583b93044e32398f51ba2dfa";
                            goto compare;
                          case 289:
                            so=288;
                        resword = "e0a34ad7aea3950ead0a5687b2a0447e";
                            goto compare;
                          case 294:
                            so=20;
                        resword = "38efd701c3c0e744af98269e9b828cff";
                            goto compare;
                          case 302:
                            so=296;
                        resword = "f9cbc6e7a50bcd505615ebebeaca955d";
                            goto compare;
                          case 303:
                            so=88;
                        resword = "40f54082681794f8777291b35cf0d5d9";
                            goto compare;
                          case 304:
                            so=325;
                        resword = "56aa9f6bc6ec5811e467ef01fc9343d9";
                            goto compare;
                          case 305:
                            so=23;
                        resword = "7f15a7f36b355f9bd30c9adfec12726e";
                            goto compare;
                          case 315:
                            so=2;
                        resword = "570f437f471caac94433d8f45557a140";
                            goto compare;
                          case 319:
                            so=146;
                        resword = "a77587c0814e56127ac872a4d56f031a";
                            goto compare;
                          case 324:
                            so=43;
                        resword = "c027ce8af5b62bd9af06eb1c3a8bbc72";
                            goto compare;
                          case 329:
                            so=236;
                        resword = "f8a802a23347d4962aaadf6a672ff49f";
                            goto compare;
                          case 330:
                            so=301;
                        resword = "d76df250c5c58fb73300cf959aa456e0";
                            goto compare;
                          case 351:
                            so=107;
                        resword = "21de34d8f91fabc69531ea3e1b4df480";
                            goto compare;
                          case 359:
                            so=136;
                        resword = "3aaaadf831a2905ecf4217f0aa69d550";
                            goto compare;
                          case 365:
                            so=278;
                        resword = "b69aec66d259f54affba18b1084b5286";
                            goto compare;
                          case 404:
                            so=298;
                        resword = "53fc6129b54d606f782cf8e6aaa51211";
                            goto compare;
                          case 411:
                            so=217;
                        resword = "e8e873f760203318c043fa8f97787f36";
                            goto compare;
                          case 414:
                            so=135;
                        resword = "e19aa899b9dcc5e31342aa5b29730c29";
                            goto compare;
                          case 417:
                            so=194;
                        resword = "b9fb7aa3a42be0eb0d1234697d8210ef";
                            goto compare;
                          case 436:
                            so=401;
                        resword = "481f604e3e391bca58029c104f612666";
                            goto compare;
                          case 451:
                            so=27;
                        resword = "458f78af6c78dece82008e881612d43f";
                            goto compare;
                          case 454:
                            so=137;
                        resword = "dd9356fed7c231dde232aa91fc9f0553";
                            goto compare;
                          case 460:
                            so=119;
                        resword = "655ad537a0bff63b856e2fd62ccf1ee8";
                            goto compare;
                          case 494:
                            so=79;
                        resword = "23be2451e94ddbc9cb3fe6ba5efade62";
                            goto compare;
                          case 498:
                            so=383;
                        resword = "5df478dfb497f2c55bbdd2352fbf6024";
                            goto compare;
                          case 504:
                            so=134;
                        resword = "6397a25b39e0bd22dc3181b9eed64623";
                            goto compare;
                          case 516:
                            so=178;
                        resword = "4a8a055204ce04dacc97685bc6f53e03";
                            goto compare;
                          case 519:
                            so=87;
                        resword = "34bf3a3fc3c5e7b3ea0fb60d259cd234";
                            goto compare;
                          case 528:
                            so=65;
                        resword = "beef11de1d5f5bb1e09b0390efdff5a0";
                            goto compare;
                          case 529:
                            so=364;
                        resword = "a7cd8b6338cd209830c5d4315842273a";
                            goto compare;
                          case 530:
                            so=164;
                        resword = "4af3d836cb9de09ef1b5b37dc1739703";
                            goto compare;
                          case 533:
                            so=119;
                        resword = "cc55dab4a57bfe7d5b1061b248a76379";
                            goto compare;
                          case 555:
                            so=316;
                        resword = "5d5859bab410457a1ace60ab6070f28f";
                            goto compare;
                          case 561:
                            so=366;
                        resword = "ef6e819d61657a0bac023425ee3efb0c";
                            goto compare;
                          case 579:
                            so=196;
                        resword = "fcb00575c4c558504ffcfc2b06c5f122";
                            goto compare;
                          case 606:
                            so=406;
                        resword = "1fbdcad3226c4dbd7ddda182deb2035a";
                            goto compare;
                          case 611:
                            so=364;
                        resword = "50f3565b4e6349802510c536e356fd8a";
                            goto compare;
                          case 616:
                            so=115;
                        resword = "df9aea4781e92aec03ef1596d4e4a251";
                            goto compare;
                          case 635:
                            so=96;
                        resword = "6c5f3396ae9d86a4aad7e9271a48c06b";
                            goto compare;
                          case 659:
                            so=124;
                        resword = "86e71ced5ae05c06b18e00870a119664";
                            goto compare;
                          case 667:
                            so=342;
                        resword = "9b6a03076f2d237f074d56f4be0a28db";
                            goto compare;
                          case 682:
                            so=70;
                        resword = "95e2409b855453da0a547c32d3ac5e44";
                            goto compare;
                          case 689:
                            so=258;
                        resword = "20ed54d287bf9bfde883cdabaecf1635";
                            goto compare;
                          case 718:
                            so=320;
                        resword = "a1e7185b4503f506c3481524be509488";
                            goto compare;
                          case 746:
                            so=291;
                        resword = "e0d086d2d8c9e4d6e5348f3972a6bda0";
                            goto compare;
                          case 749:
                            so=161;
                        resword = "b6f909411c5d146a972dc2e0b34a0e7c";
                            goto compare;
                          case 751:
                            so=209;
                        resword = "c5852206f1baa80d3100bf89f268fb06";
                            goto compare;
                          case 770:
                            so=55;
                        resword = "2c5ab8feb5d511709948a793a3eb87d9";
                            goto compare;
                          case 772:
                            so=290;
                        resword = "84f644c4bf8b1e264823af89d0d3628e";
                            goto compare;
                          case 784:
                            so=203;
                        resword = "608f47725daa3190d13703f8b0126432";
                            goto compare;
                          case 793:
                            so=178;
                        resword = "00e0331515c3b2178cbc6b57e82a6cb6";
                            goto compare;
                          case 796:
                            so=223;
                        resword = "406d38b4e298cd7200098353825f6216";
                            goto compare;
                          case 798:
                            so=179;
                        resword = "eede8c04bc8dbd7dba0443faddf2d040";
                            goto compare;
                          case 799:
                            so=142;
                        resword = "d19d287ad408a4e4d638ae4a00676686";
                            goto compare;
                          case 826:
                            so=168;
                        resword = "b3dd3110b2980e8f10ca8d64cc3b4508";
                            goto compare;
                          case 841:
                            so=125;
                        resword = "62ca8306ce462a532df60f8edca207a4";
                            goto compare;
                          case 859:
                            so=390;
                        resword = "9bf526fe26bb940afbee3e617d0af180";
                            goto compare;
                          case 899:
                            so=210;
                        resword = "89df0b110dee7a9157c2b699c447ed0e";
                            goto compare;
                          case 903:
                            so=338;
                        resword = "40dcd7ae346609a50ccf303ea66d592f";
                            goto compare;
                          case 904:
                            so=80;
                        resword = "60e90c65dc87bb54cbe6d362884c5f53";
                            goto compare;
                          case 921:
                            so=79;
                        resword = "84f63edd44e6c7bc461e95c5a31dc3a5";
                            goto compare;
                          case 923:
                            so=379;
                        resword = "f4a78919e5b79a76e7b55ea9dc689159";
                            goto compare;
                          case 927:
                            so=201;
                        resword = "9c66684a903ffe83af3790771dd70fe3";
                            goto compare;
                          case 929:
                            so=10;
                        resword = "659d3d29a6f2763a663cbbaaea128e65";
                            goto compare;
                          case 941:
                            so=13;
                        resword = "e8a87cbc341d01708330fb091e383941";
                            goto compare;
                          case 950:
                            so=297;
                        resword = "f914987bd74e3c3355dd15ccd031eb34";
                            goto compare;
                          case 951:
                            so=130;
                        resword = "cf30ce681b9046acf33fc823f1831807";
                            goto compare;
                          case 990:
                            so=20;
                        resword = "e7e3dbc504de5ad7f497d8483e880f61";
                            goto compare;
                          case 997:
                            so=322;
                        resword = "6c69dfa62fe6282e05c2661454c3138c";
                            goto compare;
                          case 1020:
                            so=234;
                        resword = "95a9d8881a72be5deac0079486b8dffd";
                            goto compare;
                          case 1024:
                            so=402;
                        resword = "11adf28da758a71ff6046affe744ef1b";
                            goto compare;
                          case 1039:
                            so=331;
                        resword = "dd4ac0747a0e6f3c149b73658857f022";
                            goto compare;
                          case 1047:
                            so=194;
                        resword = "912a73a3722022daa9f829b6388bedf8";
                            goto compare;
                          case 1061:
                            so=379;
                        resword = "3af9f0dee49049f44c1c8feaa41de0d5";
                            goto compare;
                          case 1069:
                            so=31;
                        resword = "6d64ed8a27d00c334e307d141f0e7f51";
                            goto compare;
                          case 1071:
                            so=102;
                        resword = "8bbcf6778312d9980b3bea1d7ece485c";
                            goto compare;
                          case 1081:
                            so=295;
                        resword = "6b3524faac60fda8830ac443864099c7";
                            goto compare;
                          case 1084:
                            so=167;
                        resword = "80ed3423f9b9c56cde88abe70491721e";
                            goto compare;
                          case 1085:
                            so=335;
                        resword = "e55d8721e2edb2468c00388224d55ec2";
                            goto compare;
                          case 1088:
                            so=41;
                        resword = "3b3a238c71455cf163b54174c9f2f067";
                            goto compare;
                          case 1093:
                            so=141;
                        resword = "ad67123b0b35b9903631f091d8ff04c9";
                            goto compare;
                          case 1094:
                            so=108;
                        resword = "8d4a2a1544631cdd4def3c2b3222c104";
                            goto compare;
                          case 1096:
                            so=261;
                        resword = "b5ca3ca56fb34b09eeaa20184a1d2653";
                            goto compare;
                          case 1103:
                            so=110;
                        resword = "a65aca793d02c721f3b4f90c2efacc66";
                            goto compare;
                          case 1144:
                            so=312;
                        resword = "5fa9f168889cf6b1d6cd78af4be7c92b";
                            goto compare;
                          case 1189:
                            so=126;
                        resword = "e1e6200fe588893944e1cd0df14e0f66";
                            goto compare;
                          case 1199:
                            so=64;
                        resword = "fdae2d290c0aae87eefb6f17d331811d";
                            goto compare;
                          case 1200:
                            so=108;
                        resword = "3f5f4d24af72be49c6c3e23d5fceb728";
                            goto compare;
                          case 1204:
                            so=208;
                        resword = "06ed8ee30a1fb103a7579d0f948e9479";
                            goto compare;
                          case 1211:
                            so=117;
                        resword = "63cdca79340c45dfeb324292365c9359";
                            goto compare;
                          case 1244:
                            so=35;
                        resword = "c6e243d516c18c18a151e6eaf55c0b90";
                            goto compare;
                          case 1257:
                            so=271;
                        resword = "afda45e3d1986e1065e916b1a2b496d1";
                            goto compare;
                          case 1262:
                            so=9;
                        resword = "1cb1303e2322676d36c18e43fb4a76fa";
                            goto compare;
                          case 1316:
                            so=379;
                        resword = "f2276d4430bc07bfc0134ac7b7086a36";
                            goto compare;
                          case 1336:
                            so=123;
                        resword = "4235dbc256ded9b32ecf47d40b9fb695";
                            goto compare;
                          case 1341:
                            so=358;
                        resword = "e0b833ce092cf5590a3879ff4a0d9227";
                            goto compare;
                          case 1372:
                            so=234;
                        resword = "35bd61570524861a06cc0d647de1510c";
                            goto compare;
                          case 1382:
                            so=301;
                        resword = "9a4d3ed0b8cdee060636bec422433a62";
                            goto compare;
                          case 1391:
                            so=110;
                        resword = "3cdef84a00fd85043934965236397749";
                            goto compare;
                          case 1397:
                            so=177;
                        resword = "c4b1fa4cc607ec7964c1a20ab92cc201";
                            goto compare;
                          case 1414:
                            so=275;
                        resword = "4795f8e6d73047edcc0fb8e6c3bcd1bb";
                            goto compare;
                          case 1427:
                            so=245;
                        resword = "cd03a00d4f817ba8cfcb2417be06f949";
                            goto compare;
                          case 1444:
                            so=294;
                        resword = "9f7a1654ca288ffaae52b8522b7fb13b";
                            goto compare;
                          case 1466:
                            so=105;
                        resword = "cac714f2ae5053f36a38d70cac6120b8";
                            goto compare;
                          case 1484:
                            so=174;
                        resword = "9fe2b872ac552043fa77877930183690";
                            goto compare;
                          case 1511:
                            so=11;
                        resword = "eabcc811024da1e44b327aa6bf22e32e";
                            goto compare;
                          case 1531:
                            so=241;
                        resword = "933a6b5ee5d50d0409b9850e61ce68d0";
                            goto compare;
                          case 1540:
                            so=85;
                        resword = "92f365fcf00a1a29702e6b59d0b566b3";
                            goto compare;
                          case 1554:
                            so=349;
                        resword = "c9b18b9264386c7a463e348bb407b7c7";
                            goto compare;
                          case 1556:
                            so=64;
                        resword = "ce85b8bb17a879417dc8766c48618035";
                            goto compare;
                          case 1557:
                            so=205;
                        resword = "1ef429997ed02f97e1d68e989d688ceb";
                            goto compare;
                          case 1572:
                            so=383;
                        resword = "fadbb4fe0e1d46815e1126d907754c4b";
                            goto compare;
                          case 1574:
                            so=54;
                        resword = "68ba0bbcdcf2fecba467bdf490e00c80";
                            goto compare;
                          case 1581:
                            so=413;
                        resword = "fec79081ff29fc0d6e254127826ffc56";
                            goto compare;
                          case 1592:
                            so=248;
                        resword = "ca0d62562b2bfa2772caa5549cefaef5";
                            goto compare;
                          case 1594:
                            so=329;
                        resword = "fcd2d22479434f6422adb3002345fa96";
                            goto compare;
                          case 1613:
                            so=58;
                        resword = "2ff4d5089fcda441e512537196c22a4c";
                            goto compare;
                          case 1657:
                            so=196;
                        resword = "5ef1800b286728e55edd9a77cc3db996";
                            goto compare;
                          case 1662:
                            so=397;
                        resword = "4857114973b6fa834732e7342b6256c9";
                            goto compare;
                          case 1679:
                            so=29;
                        resword = "8baa422431d338148652f5e0da3e7c53";
                            goto compare;
                          case 1704:
                            so=50;
                        resword = "6b05872acb95858b3bc47a64cebc4653";
                            goto compare;
                          case 1719:
                            so=5;
                        resword = "0bf509e12e3b4b0fbeae1e92cb0336f4";
                            goto compare;
                          case 1736:
                            so=380;
                        resword = "2ae587b095b578b508fba2f173ff5a41";
                            goto compare;
                          case 1756:
                            so=322;
                        resword = "49a70856075d253b7600abfd3624e664";
                            goto compare;
                          case 1760:
                            so=213;
                        resword = "ccdbd8a4bec3633e8a06990712cdf048";
                            goto compare;
                          case 1768:
                            so=413;
                        resword = "08aa28075b67f8e855b38c1450c143ea";
                            goto compare;
                          case 1773:
                            so=290;
                        resword = "4cf5b88eda6255ea7049ec391ce287dd";
                            goto compare;
                          case 1782:
                            so=200;
                        resword = "01e0067febf0e5315faae8e829c4bb61";
                            goto compare;
                          case 1795:
                            so=273;
                        resword = "fb929e1d1b77837984d11239e99073bc";
                            goto compare;
                          case 1869:
                            so=232;
                        resword = "1abd4ff32b463639753c5955a9e77d90";
                            goto compare;
                          case 1870:
                            so=285;
                        resword = "fd2b6b4720e10772a21ecfd9faad26a4";
                            goto compare;
                          case 1873:
                            so=374;
                        resword = "4f9a4010845fba299952e586fed561d1";
                            goto compare;
                          case 1880:
                            so=372;
                        resword = "8f2aa124fba0d118dcb94a5916aa5f6b";
                            goto compare;
                          case 1904:
                            so=62;
                        resword = "ed8e4e6358650e7be93827aed2f2be23";
                            goto compare;
                          case 1914:
                            so=137;
                        resword = "1ff9b5f22616273d5d2ce82e099e0f87";
                            goto compare;
                          case 1919:
                            so=230;
                        resword = "eff647eab716570153ad4064fe682def";
                            goto compare;
                          case 1932:
                            so=270;
                        resword = "2c55da58a64a0b641239b6068b20ef78";
                            goto compare;
                          case 1938:
                            so=258;
                        resword = "4fe401beb7bd49de534c896990f11005";
                            goto compare;
                          case 1940:
                            so=23;
                        resword = "c4f53fe793889086d5be54c1a80b4fe2";
                            goto compare;
                          case 1954:
                            so=218;
                        resword = "5abd897f6dae27976336e4c307f2c765";
                            goto compare;
                          case 1976:
                            so=13;
                        resword = "ebecb6ef985268e89af944f374896013";
                            goto compare;
                          case 1987:
                            so=69;
                        resword = "9de0422bf03aca981f84750683e43b16";
                            goto compare;
                          case 1997:
                            so=223;
                        resword = "fb87e7fd4c48153dbb253b85094459a6";
                            goto compare;
                          case 2007:
                            so=100;
                        resword = "9c37a78510da6ab674386e0ef6ef7722";
                            goto compare;
                          case 2039:
                            so=34;
                        resword = "c8b7a5179393b2c5e808beecf7c14f79";
                            goto compare;
                          case 2049:
                            so=203;
                        resword = "6d7d26c6179b15624f0e1b3b187b84ab";
                            goto compare;
                          case 2080:
                            so=121;
                        resword = "afaadf66059f5d3c09f2bf33b54bbad8";
                            goto compare;
                          case 2081:
                            so=49;
                        resword = "45ba454cbe248b47934f70a7c28425ed";
                            goto compare;
                          case 2110:
                            so=297;
                        resword = "48f8682c1522aeda2f13f1c99b2cb76a";
                            goto compare;
                          case 2113:
                            so=409;
                        resword = "1d3ac5da3b910f3b19b3e367ac942803";
                            goto compare;
                          case 2131:
                            so=244;
                        resword = "44e77f3faf9fbf6741ed8863bb86984c";
                            goto compare;
                          case 2176:
                            so=387;
                        resword = "f9db4765d9a19df304d184e18e1d9f41";
                            goto compare;
                          case 2294:
                            so=199;
                        resword = "c3ba34353be630b5f3eb1b30c57bfdc2";
                            goto compare;
                          case 2337:
                            so=87;
                        resword = "882ad6abebf3b4b8ee2800697c962bb9";
                            goto compare;
                          case 2338:
                            so=240;
                        resword = "adadb2a5ae1ed2e8b305f019b79aeeca";
                            goto compare;
                          case 2349:
                            so=301;
                        resword = "daedd27e5b467141a3f07ed8a3506974";
                            goto compare;
                          case 2386:
                            so=166;
                        resword = "4da23950a6ef9eb22c065f23de524fc2";
                            goto compare;
                          case 2420:
                            so=136;
                        resword = "416afd4cc2108f20efbd583491eb2824";
                            goto compare;
                          case 2424:
                            so=254;
                        resword = "cdfdd333ec3ae3d8dc58c1c267c15cd3";
                            goto compare;
                          case 2457:
                            so=190;
                        resword = "30e38dbcf33da401562600e166e7acb6";
                            goto compare;
                          case 2464:
                            so=18;
                        resword = "3ded41c2654223022d6dd7df19ad8ba1";
                            goto compare;
                          case 2516:
                            so=98;
                        resword = "fd8e1d2201298d552f16631ff58889ea";
                            goto compare;
                          case 2551:
                            so=111;
                        resword = "ceedcd8b06c2a45f797d772ffc8d98db";
                            goto compare;
                          case 2563:
                            so=192;
                        resword = "b17a13f3cf5d41b62f1d2d690a355a40";
                            goto compare;
                          case 2619:
                            so=197;
                        resword = "6ce629706830a4a040fe942d614cf8c2";
                            goto compare;
                          case 2656:
                            so=214;
                        resword = "06e36a3c62a55feba9185dc470efdaf6";
                            goto compare;
                          case 2664:
                            so=90;
                        resword = "90ebb969727b7b02e1a7adc2bcd3f006";
                            goto compare;
                          case 2672:
                            so=239;
                        resword = "d6ee2022251d16973ead5b9ea17e5583";
                            goto compare;
                          case 2709:
                            so=228;
                        resword = "0ded49cd03c69c2b1be22f52061347c8";
                            goto compare;
                          case 2749:
                            so=292;
                        resword = "424a3656decc7197bca64b34b5c44a19";
                            goto compare;
                          case 2762:
                            so=12;
                        resword = "cd6f32b0148af0f300ca511d1a92aa7e";
                            goto compare;
                          case 2840:
                            so=71;
                        resword = "96f70082a3274644b62f73ffd861c55f";
                            goto compare;
                          case 2845:
                            so=374;
                        resword = "f2390e80e133d638a2009b4af5f8382a";
                            goto compare;
                          case 2882:
                            so=86;
                        resword = "2effe6731c41d0f47bd7f4a50477010d";
                            goto compare;
                          case 2887:
                            so=249;
                        resword = "f2cd87e7e6911b9422def06279cb7d49";
                            goto compare;
                          case 2975:
                            so=368;
                        resword = "c3f39ce05e792e21cbddc32fca895021";
                            goto compare;
                          case 2997:
                            so=165;
                        resword = "f1cfe889d0b7d7bf48dbacc44a7f049c";
                            goto compare;
                          case 3009:
                            so=180;
                        resword = "c3ec5f52019d6dd349a1d733a46e513f";
                            goto compare;
                          case 3050:
                            so=93;
                        resword = "027abf9d6a321d5079d4cb4c69346f75";
                            goto compare;
                          case 3075:
                            so=308;
                        resword = "328a36e8f97a3d988dd21e39fe7cfaf1";
                            goto compare;
                          case 3078:
                            so=183;
                        resword = "fdd07ed1334a0d02291d769b6533beee";
                            goto compare;
                          case 3088:
                            so=116;
                        resword = "f281531a60fb3c814fc537204123721d";
                            goto compare;
                          case 3089:
                            so=368;
                        resword = "4bff19a7061e90454dad07c86a8b22b3";
                            goto compare;
                          case 3091:
                            so=90;
                        resword = "45b5f309b58fb7f155c90338710ee354";
                            goto compare;
                          case 3097:
                            so=345;
                        resword = "2de356c36067690343a0f481bcb3bcb2";
                            goto compare;
                          case 3098:
                            so=200;
                        resword = "f8407d7c3081a032b4c0382fd996bd6c";
                            goto compare;
                          case 3112:
                            so=139;
                        resword = "3de025e26727f55861a638c8ee197689";
                            goto compare;
                          case 3164:
                            so=354;
                        resword = "71ba28e89df243d304a63905e1c0ae3f";
                            goto compare;
                          case 3201:
                            so=247;
                        resword = "bef593276fb44f0b68d632eeb22f209e";
                            goto compare;
                          case 3250:
                            so=122;
                        resword = "fba4c8af74b24d072ed9162542cba298";
                            goto compare;
                          case 3251:
                            so=348;
                        resword = "f7a6c0206f6f5c480fda205617809b76";
                            goto compare;
                          case 3285:
                            so=294;
                        resword = "f516633ed16df7800136f78107945316";
                            goto compare;
                          case 3286:
                            so=156;
                        resword = "ae0a608ec9a5cc57e2d002818a04100f";
                            goto compare;
                          case 3340:
                            so=251;
                        resword = "f5be585c594760b05cd65a4b566a6458";
                            goto compare;
                          case 3350:
                            so=305;
                        resword = "7f2a3784de8cda24d412044ee1284a3f";
                            goto compare;
                          case 3353:
                            so=61;
                        resword = "33daea65572c5caec6111071c8df0465";
                            goto compare;
                          case 3405:
                            so=241;
                        resword = "e7e80860540b25a5e6a15f5a9c8e42a5";
                            goto compare;
                          case 3410:
                            so=179;
                        resword = "fcf19ea6780bfda1237375ce9c8c7f21";
                            goto compare;
                          case 3435:
                            so=171;
                        resword = "15fe5c574c272aceba0414cadc7bf99e";
                            goto compare;
                          case 3461:
                            so=22;
                        resword = "27f0277ac8cd24d79806356d7f3f73b0";
                            goto compare;
                          case 3472:
                            so=417;
                        resword = "af4a8e6b034ea081d61c86ea0ccfa3f3";
                            goto compare;
                          case 3477:
                            so=49;
                        resword = "32e8495129a95c50d5d9af0e3aa17b28";
                            goto compare;
                          case 3488:
                            so=395;
                        resword = "53f3efdc31682f6904c9cf8856001bea";
                            goto compare;
                          case 3490:
                            so=308;
                        resword = "74f6c870e193cd0aebc9b7ed584300c0";
                            goto compare;
                          case 3545:
                            so=172;
                        resword = "f18e1722fa77789b0203c6447af8d2bc";
                            goto compare;
                          case 3590:
                            so=43;
                        resword = "f9fdd3815c181c50c076cfe5f865892a";
                            goto compare;
                          case 3605:
                            so=61;
                        resword = "36f050882470171868340c2cd513fef8";
                            goto compare;
                          case 3671:
                            so=123;
                        resword = "4cbe3614a238032e2e38f5492b1c8947";
                            goto compare;
                          case 3789:
                            so=94;
                        resword = "6ced76b890d6b2b8705eb2fdd7bde9ac";
                            goto compare;
                          case 3793:
                            so=278;
                        resword = "9feee1d3bc02657e82b14c58aeaed08d";
                            goto compare;
                          case 3821:
                            so=225;
                        resword = "f5504d248c2e6e63963b18f2b3004525";
                            goto compare;
                          case 3831:
                            so=16;
                        resword = "60e3eed739f9dabfd21dd8558a6b0c7e";
                            goto compare;
                          case 3845:
                            so=132;
                        resword = "f76b571a613d4a3c85321c320d48b166";
                            goto compare;
                          case 3860:
                            so=312;
                        resword = "fe1e957cfe68f8fdbac2cdfd1dc5267c";
                            goto compare;
                          case 3893:
                            so=418;
                        resword = "5fe49e257a96b0a6de17bac4b95d74dc";
                            goto compare;
                          case 3965:
                            so=389;
                        resword = "fb91cf58aaa05aa14b303e951755019c";
                            goto compare;
                          case 3968:
                            so=291;
                        resword = "5eaa0c5881be5957821d40dea3651fed";
                            goto compare;
                          case 3976:
                            so=281;
                        resword = "e7fe6960b115c30f07d13409a8b2dc61";
                            goto compare;
                          case 4008:
                            so=361;
                        resword = "7bee09a8a899e04db2199fec4e777f35";
                            goto compare;
                          case 4084:
                            so=209;
                        resword = "61e83f894249e1e784203ae3d7bd8a8f";
                            goto compare;
                          case 4103:
                            so=344;
                        resword = "b7e0adb1dc35c0e645d3fcd577497521";
                            goto compare;
                          case 4145:
                            so=22;
                        resword = "e4f3c7f0f77baddb740de70abd8e2763";
                            goto compare;
                          case 4169:
                            so=270;
                        resword = "94e9b5b4aa3e54c7c1128c2d480170e9";
                            goto compare;
                          case 4185:
                            so=311;
                        resword = "7bf4bf882f1dd45164cc59d7d99159b7";
                            goto compare;
                          case 4249:
                            so=240;
                        resword = "befaea8731f72074fc49d0dfaa6a5463";
                            goto compare;
                          case 4260:
                            so=11;
                        resword = "84f94ce22eaba81ada3c14920249b400";
                            goto compare;
                          case 4275:
                            so=347;
                        resword = "4ce986f1d1eaa6e561bf880362f9dba0";
                            goto compare;
                          case 4293:
                            so=170;
                        resword = "67aa969a29259a8158adedc9d5b2901b";
                            goto compare;
                          case 4305:
                            so=211;
                        resword = "f04dbe155898d4dfb9073ad3989591ff";
                            goto compare;
                          case 4306:
                            so=28;
                        resword = "e9e9b66e6040350a55181f731325b7e5";
                            goto compare;
                          case 4401:
                            so=155;
                        resword = "f65a60fa25be61cb69804d6d0b2e19aa";
                            goto compare;
                          case 4450:
                            so=41;
                        resword = "e02ac9bec12543c6b0dbe41269183081";
                            goto compare;
                          case 4455:
                            so=272;
                        resword = "ccf093a40321aabfb0d7cde740a974d0";
                            goto compare;
                          case 4488:
                            so=261;
                        resword = "baed9113a5c30ff9721f766902d7943f";
                            goto compare;
                          case 4517:
                            so=296;
                        resword = "7afaf3745ae94aa122e955f4aa71e2e1";
                            goto compare;
                          case 4567:
                            so=393;
                        resword = "b28afa7f280b1e7c4007e6613bd96e58";
                            goto compare;
                          case 4605:
                            so=387;
                        resword = "55aaab55c887f67d03d33512d93e8e43";
                            goto compare;
                          case 4610:
                            so=126;
                        resword = "fda95b4b8a3b9bd5b9de3544e94d76e4";
                            goto compare;
                          case 4628:
                            so=39;
                        resword = "93f8ae100993a4d45ac0c31f76c47739";
                            goto compare;
                          case 4632:
                            so=24;
                        resword = "2fe004d9dcb07e455ed52fc413068b85";
                            goto compare;
                          case 4707:
                            so=217;
                        resword = "93eb3b79ac281b93bdd8a9eefc352636";
                            goto compare;
                          case 4762:
                            so=362;
                        resword = "14ca7303cb9c280e9f01ad6d3aaa463c";
                            goto compare;
                          case 4832:
                            so=284;
                        resword = "1df5bf5a361feb854fd82d9424a8c29c";
                            goto compare;
                          case 4871:
                            so=349;
                        resword = "fff09dd6252885fdd6b328e5c055effb";
                            goto compare;
                          case 4901:
                            so=10;
                        resword = "8b5a82703739049cdbd7a8d2ddade2bd";
                            goto compare;
                          case 4914:
                            so=49;
                        resword = "4e2a745815fe1b6dcbdbc780d0b2fb1e";
                            goto compare;
                          case 4977:
                            so=189;
                        resword = "f8de056d63ece09b753cf0dbc3270202";
                            goto compare;
                          case 5010:
                            so=74;
                        resword = "9d2aa9f742f5793fab261eac6d4de62a";
                            goto compare;
                          case 5060:
                            so=191;
                        resword = "fbb081dc1f1f32b5550ed0fb0ec85162";
                            goto compare;
                          case 5088:
                            so=128;
                        resword = "322ae64c0cf4f1830cc6eb0bb23f7ca1";
                            goto compare;
                          case 5097:
                            so=249;
                        resword = "ff7a1fa3741b5e2af7ed18b43508db8e";
                            goto compare;
                          case 5146:
                            so=256;
                        resword = "c7f415f5fcef6789ab04e6341bff1a0c";
                            goto compare;
                          case 5170:
                            so=314;
                        resword = "61f0ff11e2d0797f0a397fba4ca07ad4";
                            goto compare;
                          case 5185:
                            so=203;
                        resword = "c9f1022d6dde467f7538654ef991d480";
                            goto compare;
                          case 5190:
                            so=96;
                        resword = "5afa8965a908532beff5a591faf837d4";
                            goto compare;
                          case 5252:
                            so=149;
                        resword = "ffe1a72d62748eb6cf80e965fd218130";
                            goto compare;
                          case 5255:
                            so=221;
                        resword = "209a8cb0d13f8ea0863fe9063f506c50";
                            goto compare;
                          case 5263:
                            so=27;
                        resword = "90fab97e882973b65a95650fe1b937f5";
                            goto compare;
                          case 5317:
                            so=164;
                        resword = "cafb030da7726f8f95c80dae19d75941";
                            goto compare;
                          case 5424:
                            so=127;
                        resword = "f21ab42bd29cbe78d7b43e5970f98b90";
                            goto compare;
                          case 5475:
                            so=169;
                        resword = "88ed1ac9a3dc3096cad19d0333e1659e";
                            goto compare;
                          case 5528:
                            so=341;
                        resword = "f4555af057db8730ce3c919fbeee661c";
                            goto compare;
                          case 5540:
                            so=54;
                        resword = "1cf7447718e773e3920aa95167885b75";
                            goto compare;
                          case 5598:
                            so=271;
                        resword = "4d3a09ea99f78ef17b19fd1aee054f1f";
                            goto compare;
                          case 5615:
                            so=283;
                        resword = "75e65f16a0051c5823c710a53cabfab1";
                            goto compare;
                          case 5720:
                            so=193;
                        resword = "f2ba2c9a9a729a0d42e03ac49969dca0";
                            goto compare;
                          case 5772:
                            so=243;
                        resword = "42fa36e2ad8de0caf94965897a19a843";
                            goto compare;
                          case 5810:
                            so=411;
                        resword = "6df1503acec6f110a9030209daec870f";
                            goto compare;
                          case 5823:
                            so=245;
                        resword = "cebaf7c1aba28f4c981e519e07d7213c";
                            goto compare;
                          case 5849:
                            so=138;
                        resword = "fcdcca1541c591661e3283b0b48d0d8f";
                            goto compare;
                          case 5890:
                            so=341;
                        resword = "51e911fe7699f790500bb04f29e6c3f4";
                            goto compare;
                          case 5910:
                            so=25;
                        resword = "c6fec12326d626067c3b98faad12c95f";
                            goto compare;
                          case 6028:
                            so=355;
                        resword = "86e2a365b7738bb413c625fcb59c9076";
                            goto compare;
                          case 6160:
                            so=392;
                        resword = "72ee28b061fff6eb3dc058ef07085b6f";
                            goto compare;
                          case 6301:
                            so=343;
                        resword = "939ae4852200088720c394555920fe95";
                            goto compare;
                          case 6339:
                            so=363;
                        resword = "fad5b5788df545d4063448129163f0f8";
                            goto compare;
                          case 6401:
                            so=204;
                        resword = "954ac19c76454e07bccb15b1eba25f4d";
                            goto compare;
                          case 6474:
                            so=281;
                        resword = "3bebbe618f0ee765d2369e24658dbd3e";
                            goto compare;
                          case 6520:
                            so=22;
                        resword = "fbed34ea396b5956269456e7e6ddc318";
                            goto compare;
                          case 6615:
                            so=348;
                        resword = "30ea3c59af9d65ce4b577964bb4a14c2";
                            goto compare;
                          case 6713:
                            so=325;
                        resword = "c52af352cdd02f53f5c10eb16d401db6";
                            goto compare;
                          case 6750:
                            so=220;
                        resword = "53ed41d0703fc684d002871a45c43662";
                            goto compare;
                          case 6848:
                            so=220;
                        resword = "0d3a89adb49e2125cfc709fc15bef694";
                            goto compare;
                          case 6920:
                            so=31;
                        resword = "e2e84313489b7bf908c3889a87e01edb";
                            goto compare;
                          case 6980:
                            so=86;
                        resword = "d9eaff81e320dc38ece784f11d3e9bb7";
                            goto compare;
                          case 7072:
                            so=311;
                        resword = "bbeeac38c7ed0d9b893d8bcda3bcb074";
                            goto compare;
                          case 7101:
                            so=299;
                        resword = "98e9116dc3d27f4b61c9666bfd559d36";
                            goto compare;
                          case 7185:
                            so=317;
                        resword = "52baffc7b0e68ed5223c1743cb35ab63";
                            goto compare;
                          case 7288:
                            so=252;
                        resword = "c0e2c7213978f3e87ec4584c88fb1058";
                            goto compare;
                          case 7608:
                            so=27;
                        resword = "f8e72432e1be05e4d3adf9d8c8956634";
                            goto compare;
                          case 7640:
                            so=273;
                        resword = "01e5ca3e00c566edf5cb8a3d1ac4d672";
                            goto compare;
                          case 7700:
                            so=317;
                        resword = "deba14c92ff98a00f8c59c990b03e7be";
                            goto compare;
                          case 7755:
                            so=36;
                        resword = "81ea60c3a5dd2c35d8f44dead3ebe692";
                            goto compare;
                          case 7975:
                            so=178;
                        resword = "c9efc933af660db4c80eccb48672b5fb";
                            goto compare;
                          case 8118:
                            so=329;
                        resword = "62ba2fa00bc160ce92c1c06e77badad7";
                            goto compare;
                          case 8507:
                            so=236;
                        resword = "46aa8e8738371ad5733a1654306b1aa5";
                            goto compare;
                          case 8678:
                            so=188;
                        resword = "c1aa14b43775db3b94ccd856a32428ac";
                            goto compare;
                          case 9065:
                            so=144;
                        resword = "ceedf8171d57a96964ca85892be0a7e0";
                            goto compare;
                          case 10294:
                            so=244;
                        resword = "f24a1ddb62505c0001ccbea43ddc4c2f";
                            goto compare;
                          case 10464:
                            so=220;
                        resword = "28faebc87641cfd9f0caac3081de55f1";
                            goto compare;
                          case 10721:
                            so=286;
                        resword = "f19aecfc5b6d7ba2063ae701fbd89422";
                            goto compare;
                          case 11826:
                            so=238;
                        resword = "f1ba3b8081269eac3109ccf26796bd04";
                            goto compare;
                          case 12380:
                            so=291;
                        resword = "adea6fb16b6cf71fceddf350855da47c";
                            goto compare;
                          case 12661:
                            so=113;
                        resword = "d5ea004463dc4edfc90fa4cd3e98918d";
                            goto compare;
                          case 13478:
                            so=97;
                        resword = "ffe5efc328c78c0298ccf131e439a273";
                            goto compare;
                          case 15243:
                            so=190;
                        resword = "4ceaf07ef10163a7420b3adabb65f546";
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
