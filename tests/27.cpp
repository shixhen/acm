/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /********* Begin *********/
    int sign = x >> 31;
    x = (sign & ~x) | (~sign & x);
    int bit16, bit8, bit4, bit2, bit1, bit0;
    bit16 = !!(x >> 16) << 4;
    x = x >> bit16;
    bit8 = !!(x >> 8) << 3;
    x = x >> bit8;
    bit4 = !!(x >> 4) << 2;
    x = x >> bit4;
    bit2 = !!(x >> 2) << 1;
    x = x >> bit2;
    bit1 = !!(x >> 1);
    x = x >> bit1;
    bit0 = x;
    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
	
  /********* End *********/
  //请在下面/* */之间区域写下你的解题思路
  /* 
  姓名name：张三
  学号No：123456
  思路problem-solving ideas: 通过逐步右移x并检查每一位，计算出表示x所需的最小位数。
 */
}