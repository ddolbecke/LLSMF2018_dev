

/* 
 * File:   scope.h
 * Author: Dimitri
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SCOPE_H
#define	SCOPE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1

#include "plib.h"


void initScope(void);
void scopeRoutine();
void sendVariables(long* data);

long scopeVariables[6];

#endif	/* SCOPE_H */

