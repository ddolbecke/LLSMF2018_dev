/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#if !defined(MIC3_H)
#define MIC3_H

/* ------------------------------------------------------------ */
/*					Definitions									*/
/* ------------------------------------------------------------ */
#define MIC3_NO_BITS		12

#define MIC3_SPI_FREQ	1000000 // 1 MHz - default spi freq
#define	PAR_ACCESS_SPI0			0
#define	PAR_ACCESS_SPI1			1
#define	PAR_ACCESS_I2C			2	
/* ------------------------------------------------------------ */
/*					Procedure Declarations						*/
/* ------------------------------------------------------------ */

void initMIC3(void);
int readMIC3(void);
void closeMIC3(void);
unsigned int readVolume(void);

unsigned int abs_int(int val);

#endif
