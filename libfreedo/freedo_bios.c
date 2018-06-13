#include "freedo_bios.h"

static const freedo_bios_t BIOSES[] =
  {
    {
      "panafz1.bin",
      "Panasonic FZ-1",
      (1024 * 1024),
      'U',
      "?",
      "1993-08-03",
      {0xc8,0xc8,0xff,0x89},
      {0xf4,0x72,0x64,0xdd,0x47,0xfe,0x30,0xf7,
       0x3a,0xb3,0xc0,0x10,0x01,0x5c,0x15,0x5b},
      {0x34,0xbf,0x18,0x91,0x11,0x29,0x5f,0x74,0xd7,0xb7,
       0xdf,0xc1,0xf3,0x04,0xd9,0x8b,0x8d,0x36,0x32,0x5a}
    },
    {
      "panafz10.bin",
      "Panasonic FZ-10",
      (1024 * 1024),
      'U',
      "1.59.1.1",
      "1994-08-25",
      {0x58,0x24,0x2c,0xee},
      {0x51,0xf2,0xf4,0x3a,0xe2,0xf3,0x50,0x8a,
       0x14,0xd9,0xf5,0x65,0x97,0xe2,0xd3,0xce},
      {0x3c,0x91,0x23,0x00,0x77,0x5d,0x1a,0xd7,0x30,0xdc,
       0x35,0x75,0x7e,0x27,0x9c,0x27,0x4c,0x0a,0xca,0xad}
    },
    {
      "panafz10-patched.bin",
      "Panasonic FZ-10 [RSA Patch]",
      (1024 * 1024),
      'U',
      "1.59.1.1 [patched]",
      "1994-08-25",
      {0x23,0x0e,0x6f,0xeb},
      {0x14,0x77,0xbd,0xa8,0x0d,0xc3,0x37,0x31,
       0xa6,0x54,0x68,0xc1,0xf5,0xbc,0xbe,0xe9},
      {0xf0,0x5e,0x64,0x23,0x22,0xc0,0x36,0x94,0xf0,0x6a,
       0x80,0x9c,0x0b,0x90,0xfc,0x27,0xac,0x73,0xc0,0x02}
    },
    {
      "panafz10-anvil.bin",
      "Panasonic FZ-10 [Anvil]",
      (1024 * 1024),
      'E',
      "?",
      "????-??-??",
      {0x24,0x95,0xc5,0x00},
      {0xa4,0x8e,0x67,0x46,0xbd,0x7e,0xde,0xc0,
       0xf4,0x0c,0xff,0x07,0x8f,0x0b,0xb1,0x9f},
      {0xa9,0x00,0x37,0x1f,0x0c,0xdc,0xdc,0x03,0xf7,0x95,
       0x57,0xf1,0x1d,0x40,0x6f,0xd7,0x12,0x51,0xa5,0xfd}
    },
    {
      "goldstar.bin",
      "Goldstar GDO-101M",
      (1024 * 1024),
      'U',
      "1.59",
      "1994-05-10",
      {0xb6,0xf5,0x02,0x8b},
      {0x86,0x39,0xfd,0x5e,0x54,0x9b,0xd6,0x23,
       0x8c,0xfe,0xe7,0x9e,0x3e,0x74,0x91,0x14},
      {0xc4,0xa2,0xe5,0x33,0x6f,0x77,0xfb,0x5f,0x74,0x3d,
       0xe1,0xee,0xa2,0xcd,0xa4,0x36,0x75,0xee,0x2d,0xe7}
    },
    {
      "sanyotry.bin",
      "Sanyo Try IMP-21J",
      (1024 * 1024),
      'J',
      "1.59",
      "1994-05-10",
      {0xd5,0xcb,0xc5,0x09},
      {0x35,0xfa,0x1a,0x1e,0xba,0xae,0xea,0x28,
       0x6d,0xc5,0xcd,0x15,0x48,0x7c,0x13,0xea},
      {0xb0,0x1c,0x53,0xda,0x25,0x6d,0xde,0x43,0xff,0xec,
       0x4a,0xd3,0xfc,0x3a,0xdf,0xa8,0xd6,0x35,0xe9,0x43}
    },
    {
      "3do_arcade_saot.bin",
      "3DO Arcade - SAOT",
      (512 * 1024),
      'U',
      "?",
      "????-??-??",
      {0xb8,0x32,0xda,0x9a},
      {0x89,0x70,0xfc,0x98,0x7a,0xb8,0x9a,0x7f,
       0x64,0xda,0x9f,0x8a,0x8c,0x43,0x33,0xff},
      {0x52,0x0d,0x3d,0x1b,0x58,0x97,0x80,0x0a,0xf4,0x7f,
       0x92,0xef,0xd2,0x44,0x4a,0x26,0xb7,0xa7,0xde,0xad}
    },
    {0,0,0,'X',0,0,{0},{0},{0}}
  };

static const freedo_bios_t ROM2 =
  {
    "rom2.bin",
    "Kanji ROM",
    933636,
    'J',
    "16.4",
    "????-??-??",
    {0xa8,0xe9,0x44,0x7c},
    {0xb8,0xdc,0x97,0xf7,0x78,0xa6,0x24,0x5c,
     0x58,0xe0,0x64,0xb0,0x31,0x2e,0x82,0x81},
    {0xac,0xd3,0x9a,0x8f,0xee,0x1b,0x9d,0x29,0x50,0xd5,
     0xab,0x44,0x78,0x46,0xc1,0x1f,0xb3,0x1a,0xf6,0x3e}
  };


const
freedo_bios_t*
freedo_bios_rom2(void)
{
  return &ROM2;
}

const
freedo_bios_t*
freedo_bios_begin(void)
{
  return &BIOSES[0];
}

const
freedo_bios_t*
freedo_bios_end(void)
{
  return &BIOSES[sizeof(BIOSES) / sizeof(BIOSES[0]) - 1];
}
