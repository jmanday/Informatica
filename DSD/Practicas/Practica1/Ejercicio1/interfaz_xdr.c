/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "interfaz.h"

bool_t
xdr_param (XDR *xdrs, param *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->primero))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->segundo))
		 return FALSE;
	return TRUE;
}
