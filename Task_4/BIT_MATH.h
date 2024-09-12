#ifndef DAY_12_BIT_MASS_H
#define DAY_12_BIT_MASS_H
#define SET_BIT(REG,BIT_NUM)  (REG|=(1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)  (REG&=~(1<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)  (REG^=(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM)  ((REG>>BIT_NUM)&1)

#endif
