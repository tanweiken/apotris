#include "def.h"
#include <string.h>
#include <string>
#include <tonc.h>
#include "posprintf.h"

#define bg3MapLen 1376
u16 bg3Map[688]__attribute__((aligned(4)));

void aprint(std::string str, int x, int y){
	u16 * dest = (u16 * )bg3Map;
	dest+= 32*y+x;
	for(int i = 0; i < (int) str.length(); i++){
		int c = str[i]-32;
		int letter = 0xf000;
		letter += c;
		*dest++ = letter;
	}
	memcpy16(&se_mem[29][y*32+x],&bg3Map[y*32+x],((int)str.length())*16/2);
}

void aprintf(int n, int x, int y){
	char res[30];
	// posprintf(res,"%d",n);
	aprint(res,x,y);
}

void clearText(){
	for(int i = 0; i < 688; i++){
		bg3Map[i] = 0xf000;
	}
	memcpy16(&se_mem[29],bg3Map,bg3MapLen/2);
}

const u16 fontTiles[1552] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,
	0x2000,0x0032,0x3000,0x0033,0x2000,0x0032,0x3000,0x0033,
	0x3200,0x0032,0x3200,0x0032,0x3300,0x0033,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0032,0x3200,0x0322,0x2200,0x0332,0x3220,0x0322,
	0x2230,0x0332,0x3220,0x0032,0x3230,0x0033,0x3300,0x0000,
	0x2000,0x0003,0x2200,0x0322,0x2320,0x0333,0x2230,0x0032,
	0x2300,0x0323,0x2220,0x0332,0x2330,0x0033,0x3000,0x0003,

	0x0000,0x0000,0x0000,0x3200,0x3200,0x3320,0x3300,0x0332,
	0x2000,0x0033,0x3200,0x0323,0x3320,0x0330,0x0330,0x0000,
	0x0000,0x0000,0x2200,0x0003,0x3320,0x0032,0x2230,0x0033,
	0x2320,0x0323,0x3320,0x0332,0x2230,0x3223,0x3300,0x3333,
	0x3200,0x0000,0x3200,0x0000,0x3300,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0032,0x2000,0x0003,0x3200,0x0000,0x3200,0x0000,
	0x3200,0x0000,0x2300,0x0003,0x3000,0x0032,0x0000,0x0033,

	0x2000,0x0003,0x3000,0x0032,0x0000,0x0323,0x0000,0x0320,
	0x0000,0x0320,0x0000,0x0332,0x2000,0x0033,0x3000,0x0003,
	0x2000,0x0003,0x2320,0x0323,0x3230,0x0332,0x2300,0x0033,
	0x3200,0x0032,0x2320,0x0323,0x2330,0x0333,0x3000,0x0003,
	0x0000,0x0000,0x2000,0x0003,0x2000,0x0003,0x2220,0x0322,
	0x2330,0x0333,0x2000,0x0003,0x3000,0x0003,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x2000,0x0003,0x2000,0x0003,0x3000,0x0003,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x2220,0x0322,
	0x3330,0x0333,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x3200,0x0000,0x3300,0x0000,
	0x0000,0x0000,0x0000,0x3200,0x0000,0x3320,0x0000,0x0332,
	0x2000,0x0033,0x3200,0x0003,0x3320,0x0000,0x0330,0x0000,
	0x0000,0x0000,0x2200,0x0322,0x3220,0x3223,0x3220,0x3222,
	0x2220,0x3223,0x3220,0x3223,0x2230,0x3322,0x3300,0x0333,

	0x0000,0x0000,0x2200,0x0032,0x2300,0x0032,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,0x3000,0x0033,
	0x0000,0x0000,0x2220,0x0022,0x3220,0x3223,0x0330,0x3220,
	0x2200,0x3322,0x3220,0x0333,0x2220,0x3222,0x3330,0x3333,
	0x0000,0x0000,0x2220,0x0322,0x3220,0x3223,0x2330,0x3322,
	0x3000,0x3223,0x3220,0x3220,0x2220,0x3322,0x3330,0x0333,
	0x0000,0x0000,0x0000,0x0322,0x2000,0x0322,0x2200,0x0322,
	0x3220,0x0322,0x2220,0x3222,0x3330,0x3322,0x0000,0x0333,

	0x0000,0x0000,0x2220,0x3222,0x3220,0x3333,0x2220,0x3222,
	0x3330,0x3223,0x3220,0x3220,0x2220,0x3322,0x3330,0x0333,
	0x0000,0x0000,0x2200,0x0322,0x3220,0x0333,0x2220,0x3222,
	0x3220,0x3223,0x3220,0x3220,0x2230,0x3322,0x3300,0x0333,
	0x0000,0x0000,0x2220,0x0322,0x3330,0x0322,0x2000,0x0332,
	0x2000,0x0032,0x2200,0x0033,0x2200,0x0003,0x3300,0x0003,
	0x0000,0x0000,0x2200,0x0322,0x3220,0x3223,0x2230,0x3322,
	0x3220,0x3223,0x3220,0x3220,0x2230,0x3322,0x3300,0x0333,

	0x0000,0x0000,0x2200,0x0322,0x3220,0x3223,0x3220,0x3220,
	0x2220,0x3222,0x3330,0x3223,0x2200,0x3322,0x3300,0x0333,
	0x0000,0x0000,0x3200,0x0000,0x3300,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x3200,0x0000,0x3300,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x3200,0x0000,0x3300,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x3200,0x0000,0x3200,0x0000,0x3300,0x0000,
	0x0000,0x0032,0x2000,0x0033,0x3200,0x0003,0x3320,0x0000,
	0x3230,0x0000,0x2300,0x0003,0x3000,0x0032,0x0000,0x0033,

	0x0000,0x0000,0x0000,0x0000,0x2220,0x0322,0x3330,0x0333,
	0x2220,0x0322,0x3330,0x0333,0x0000,0x0000,0x0000,0x0000,
	0x2000,0x0003,0x3000,0x0032,0x0000,0x0323,0x0000,0x3230,
	0x0000,0x3320,0x0000,0x0332,0x2000,0x0033,0x3000,0x0003,
	0x2200,0x0032,0x3220,0x0322,0x3220,0x0322,0x3330,0x0332,
	0x2000,0x0033,0x3000,0x0003,0x2000,0x0003,0x3000,0x0003,
	0x2200,0x0032,0x3320,0x0323,0x2032,0x3232,0x3232,0x3223,
	0x3232,0x3220,0x2320,0x3322,0x2200,0x0332,0x3300,0x0033,

	0x0000,0x0000,0x2000,0x3222,0x2200,0x3223,0x3220,0x3223,
	0x2220,0x3222,0x3220,0x3223,0x3220,0x3220,0x3330,0x3330,
	0x0000,0x0000,0x2200,0x3222,0x3220,0x3223,0x2220,0x3322,
	0x3220,0x3223,0x3220,0x3220,0x2220,0x3322,0x3330,0x0333,
	0x0000,0x0000,0x2200,0x3222,0x3220,0x3223,0x3220,0x3330,
	0x3220,0x3220,0x3220,0x3220,0x2230,0x3322,0x3300,0x0333,
	0x0000,0x0000,0x2200,0x0322,0x3220,0x3223,0x3220,0x3220,
	0x3220,0x3220,0x3220,0x3220,0x2220,0x3322,0x3330,0x0333,

	0x0000,0x0000,0x2200,0x0322,0x3220,0x0333,0x2220,0x0322,
	0x3220,0x0333,0x3220,0x0000,0x2220,0x0322,0x3330,0x0333,
	0x0000,0x0000,0x2200,0x0322,0x3220,0x0333,0x2220,0x0322,
	0x3220,0x0333,0x3220,0x0000,0x3220,0x0000,0x3330,0x0000,
	0x0000,0x0000,0x2200,0x3222,0x3220,0x3333,0x3220,0x3222,
	0x3220,0x3220,0x3220,0x3220,0x2230,0x3322,0x3300,0x0333,
	0x0000,0x0000,0x3200,0x3220,0x3220,0x3220,0x2220,0x3222,
	0x3220,0x3223,0x3220,0x3220,0x3220,0x3220,0x3330,0x3330,

	0x0000,0x0000,0x0000,0x0032,0x2000,0x0032,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,0x3000,0x0033,
	0x0000,0x0000,0x0000,0x0032,0x2000,0x0032,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2200,0x0033,0x3300,0x0003,
	0x0000,0x0000,0x3200,0x3220,0x3220,0x3322,0x2220,0x0332,
	0x2220,0x0032,0x3220,0x0322,0x3220,0x3223,0x3330,0x3330,
	0x0000,0x0000,0x3200,0x0000,0x3220,0x0000,0x3220,0x0000,
	0x3220,0x0000,0x3220,0x0000,0x2220,0x3222,0x3330,0x3333,

	0x0000,0x0000,0x0032,0x3200,0x0322,0x3220,0x3222,0x3222,
	0x2222,0x3222,0x2322,0x3223,0x3322,0x3223,0x0333,0x3330,
	0x0000,0x0000,0x3220,0x3220,0x2220,0x3223,0x2220,0x3222,
	0x3220,0x3222,0x3220,0x3223,0x3220,0x3230,0x3330,0x3300,
	0x0000,0x0000,0x2200,0x0322,0x3220,0x3223,0x3220,0x3220,
	0x3220,0x3220,0x3220,0x3220,0x2230,0x3322,0x3300,0x0333,
	0x0000,0x0000,0x2200,0x3222,0x3220,0x3223,0x3220,0x3220,
	0x2220,0x3322,0x3220,0x0333,0x3220,0x0000,0x3330,0x0000,

	0x0000,0x0000,0x2200,0x0322,0x3220,0x3223,0x3220,0x3220,
	0x2220,0x3222,0x3220,0x3223,0x2230,0x3222,0x3300,0x3333,
	0x0000,0x0000,0x2200,0x3222,0x3220,0x3223,0x3220,0x3220,
	0x2220,0x3322,0x3220,0x3223,0x3220,0x3220,0x3330,0x3330,
	0x0000,0x0000,0x2200,0x3222,0x3220,0x3223,0x2220,0x3332,
	0x2330,0x3222,0x3220,0x3223,0x2220,0x3322,0x3330,0x0333,
	0x0000,0x0000,0x2200,0x3222,0x2300,0x3332,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,0x3000,0x0033,

	0x0000,0x0000,0x3200,0x3220,0x3220,0x3220,0x3220,0x3220,
	0x3220,0x3220,0x3220,0x3220,0x2230,0x3322,0x3300,0x0333,
	0x0000,0x0000,0x3200,0x3220,0x3220,0x3220,0x3220,0x3220,
	0x3220,0x3220,0x2230,0x3322,0x2300,0x0332,0x3000,0x0033,
	0x0000,0x0000,0x0320,0x3220,0x0322,0x3220,0x2322,0x3223,
	0x2322,0x3223,0x2222,0x3222,0x3223,0x3322,0x3330,0x0333,
	0x0000,0x0000,0x3220,0x3220,0x2220,0x3223,0x2330,0x3332,
	0x2000,0x0032,0x3220,0x3222,0x3220,0x3223,0x3330,0x3330,

	0x0000,0x0000,0x3200,0x3220,0x3220,0x3220,0x3220,0x3220,
	0x2230,0x3322,0x2300,0x0332,0x2000,0x0032,0x3000,0x0033,
	0x0000,0x0000,0x2220,0x0322,0x3330,0x0322,0x2000,0x0332,
	0x2200,0x0033,0x3220,0x0003,0x2220,0x0322,0x3330,0x0333,
	0x2200,0x0032,0x3200,0x0033,0x3200,0x0000,0x3200,0x0000,
	0x3200,0x0000,0x3200,0x0000,0x2200,0x0032,0x3300,0x0033,
	0x0000,0x0000,0x0320,0x0000,0x3230,0x0000,0x2300,0x0003,
	0x3000,0x0032,0x0000,0x0323,0x0000,0x3230,0x0000,0x3300,

	0x2000,0x0322,0x3000,0x0323,0x0000,0x0320,0x0000,0x0320,
	0x0000,0x0320,0x0000,0x0320,0x2000,0x0322,0x3000,0x0333,
	0x0000,0x0000,0x2000,0x0003,0x3200,0x0032,0x3320,0x0323,
	0x0332,0x3230,0x0033,0x3300,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x2220,0x0322,0x3330,0x0333,
	0x0000,0x0000,0x0000,0x0032,0x0000,0x0323,0x0000,0x0330,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x2000,0x0032,0x3000,0x0322,0x2000,0x0322,
	0x3200,0x0322,0x3200,0x0322,0x2300,0x0322,0x3000,0x0333,
	0x0000,0x0000,0x2000,0x0003,0x2200,0x0003,0x2200,0x0322,
	0x2200,0x0323,0x2200,0x0323,0x2200,0x0332,0x3300,0x0033,
	0x0000,0x0000,0x0000,0x0000,0x2000,0x0322,0x2200,0x0333,
	0x2200,0x0003,0x2200,0x0003,0x2200,0x0322,0x3300,0x0333,
	0x0000,0x0000,0x0000,0x0320,0x0000,0x0322,0x2000,0x0322,
	0x3200,0x0322,0x3200,0x0322,0x2300,0x0322,0x3000,0x0333,

	0x0000,0x0000,0x0000,0x0000,0x2000,0x0032,0x2200,0x0323,
	0x2200,0x0322,0x2200,0x0333,0x2200,0x0322,0x3300,0x0333,
	0x0000,0x0000,0x0000,0x0322,0x2000,0x0332,0x2200,0x0322,
	0x2300,0x0332,0x2000,0x0032,0x2000,0x0032,0x3000,0x0033,
	0x0000,0x0000,0x2000,0x0322,0x3200,0x0322,0x3200,0x0322,
	0x2300,0x0322,0x3000,0x0322,0x2000,0x0332,0x3000,0x0033,
	0x0000,0x0000,0x2000,0x0003,0x2200,0x0003,0x2200,0x0032,
	0x2200,0x0323,0x2200,0x0323,0x2200,0x0323,0x3300,0x0333,

	0x0000,0x0000,0x2000,0x0032,0x3000,0x0033,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,0x3000,0x0033,
	0x0000,0x0000,0x0000,0x0032,0x2000,0x0032,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2200,0x0033,0x3300,0x0003,
	0x0000,0x0000,0x2000,0x0003,0x2200,0x0003,0x2200,0x0323,
	0x2200,0x0332,0x2200,0x0323,0x2200,0x0323,0x3300,0x0333,
	0x0000,0x0000,0x2200,0x0003,0x2000,0x0032,0x2000,0x0032,
	0x2000,0x0032,0x2000,0x0032,0x2000,0x0032,0x3000,0x0033,

	0x0000,0x0000,0x0000,0x0000,0x2200,0x3222,0x3220,0x3232,
	0x3220,0x3232,0x3220,0x3232,0x3220,0x3232,0x3330,0x3333,
	0x0000,0x0000,0x0000,0x0000,0x2000,0x0322,0x2200,0x0323,
	0x2200,0x0323,0x2200,0x0323,0x2200,0x0323,0x3300,0x0333,
	0x0000,0x0000,0x0000,0x0000,0x2000,0x0032,0x2200,0x0323,
	0x2200,0x0323,0x2200,0x0323,0x2300,0x0332,0x3000,0x0033,
	0x0000,0x0000,0x2000,0x0322,0x2200,0x0323,0x2200,0x0323,
	0x2200,0x0332,0x2200,0x0033,0x2200,0x0003,0x3300,0x0003,

	0x0000,0x0000,0x2000,0x0322,0x3200,0x0322,0x3200,0x0322,
	0x2200,0x0322,0x3300,0x0322,0x0000,0x0322,0x0000,0x0333,
	0x0000,0x0000,0x0000,0x0000,0x2000,0x0323,0x2200,0x0332,
	0x2200,0x0033,0x2200,0x0003,0x2200,0x0003,0x3300,0x0003,
	0x0000,0x0000,0x0000,0x0000,0x2000,0x0322,0x2200,0x0333,
	0x2200,0x0322,0x3300,0x0322,0x2200,0x0322,0x3300,0x0333,
	0x0000,0x0000,0x0000,0x0032,0x2000,0x0032,0x2200,0x0322,
	0x2300,0x0332,0x2000,0x0032,0x2000,0x0322,0x3000,0x0333,

	0x0000,0x0000,0x0000,0x0000,0x2000,0x0323,0x2200,0x0323,
	0x2200,0x0323,0x2200,0x0323,0x2300,0x0322,0x3000,0x0333,
	0x0000,0x0000,0x0000,0x0000,0x2000,0x0323,0x2200,0x0323,
	0x2200,0x0323,0x2300,0x0332,0x2000,0x0032,0x3000,0x0033,
	0x0000,0x0000,0x0000,0x0000,0x3200,0x3200,0x3220,0x3200,
	0x3220,0x3232,0x2220,0x3222,0x2230,0x3323,0x3300,0x0333,
	0x0000,0x0000,0x0000,0x0000,0x2200,0x0323,0x2200,0x0323,
	0x2300,0x0332,0x2200,0x0323,0x2200,0x0323,0x3300,0x0333,

	0x0000,0x0000,0x0000,0x0000,0x3200,0x0322,0x3200,0x0322,
	0x2200,0x0322,0x3300,0x0322,0x2200,0x0332,0x3300,0x0033,
	0x0000,0x0000,0x0000,0x0000,0x2200,0x0322,0x3300,0x0322,
	0x2000,0x0332,0x2200,0x0033,0x2200,0x0322,0x3300,0x0333,
	0x2000,0x0032,0x2200,0x0033,0x2300,0x0003,0x3200,0x0003,
	0x2300,0x0003,0x2200,0x0003,0x2300,0x0032,0x3000,0x0033,
	0x2000,0x0003,0x2000,0x0003,0x2000,0x0003,0x2000,0x0003,
	0x2000,0x0003,0x2000,0x0003,0x2000,0x0003,0x3000,0x0003,

	0x2000,0x0032,0x3000,0x0322,0x0000,0x0332,0x0000,0x0323,
	0x0000,0x0332,0x0000,0x0322,0x2000,0x0332,0x3000,0x0033,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3220,0x0000,
	0x2332,0x3203,0x3033,0x3322,0x0000,0x0333,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x3220,0x0322,0x3320,0x3232,
	0x3220,0x3232,0x3320,0x3232,0x3220,0x3322,0x3330,0x0333,
	0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,
	0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,
};