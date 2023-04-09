/*******************************************
 * How to use "witsanu.h"                  *
 * *****************************************
 * Blend285(<Time>);
 * ฟังชั่น แสดงรูป3เหลี่ยม
 * <Time> เวลาที่อยากให้รูปแสดงมีหน่วยเป็นมิลลิวินาที
 * Ex. Blend285(1000);
 * 
 * 
 * CaptainMorgan(<NAME>,<TIME>);
 * ฟังชั่นสำหรับเขียนชื่อ
 * <NAME> ใส่ชื่อหรือข้อความที่ต้องการ
 * <TIME> เวลาที่แต่ละตัวอักษรแสดง มีหน่วยเป็นมิลลิวินาที
 * Ex. CaptainMorgan("NAME",1000);
 * 
 * JohnnyWalker(<รหัสนศ4ตัวท้าย>,<TIME>);
 * <รหัสนศ4ตัวท้าย> รหัสนศ 4 ตัวท้าย อย่าใส่เกินนะไอหนุ่ม
 * <TIME> เวลาที่แต่ละตัวเลขแสดง มีหน่วยเป็นมิลลิวินาที
 * Ex. JohnnyWalker(1005,1000);
 * 
 * 
 * แต่ถ้าคุณขี้เกลียจผมขอเสนอfunctionนี้เลย
 * SoSad(<Name>,<รหัสนศ4ตัวท้าย>);
 * <Name> ใส่เพียงชื่อของคุณ
 * <รหัสนศ4ตัวท้าย> ใส่รหัสนศของคุณ4ตัวท้ายเท่านั้น
 * Ex. SoSad("Tommy",1005);
 * 
 * **หมายเหตุ
 * ในvoid setup คุณต้องใช้ function 
 * gost();
 * ด้วยนะจ๊ะ
 * 
 * ในกรณีที่รหัสนศของคุณเป็น 0135 คุณไม่สามารถใส่ 0135 ได้
 * เนื่องจากโปรแกรมจะมองว่าการที่คุณใส่ 0 นำหน้าจะเป็นเลขฐาน 8
 * แต่คุณไม่ต้องห่วงคุณสามารถแก้ปัญหานี้ได้โดย
 * ใส่เลขโดยไม่มี 0 นำหน้า เช่น 0135 -> 135
 * 
 */

#include "witsanu.h"

void setup(){
  gost();
}

void loop() {
  SoSad("Tommy",1357);
  
  /*
  Blend285(1000);
  CaptainMorgan("Tommy",1000);
  JohnnyWalker(1357,1000);*/
}