#include "usbuser.h"

/// Definice. Global USB classes.
  UsbDevice usb;
  //CdClass   vcom;
  //CdClass   test;
  MsClass   disc;
  
/// Následně použito v aplikaci
void BuildDevice (void) {
  usb.addClass (&disc);		/// Přidáme všechny potřebné třídy.
  //usb.addClass (&vcom);
  //usb.addClass (&test);
  usb.buildDev ();		/// A nakonec postavíme strom zařízení.
}
/** ************************************/
#ifdef DSCBLD
#include <stdio.h>
/// main pro vytvoření deskriptorů
int main (void) {
  BuildDevice ();	/// Stejně jako v aplikaci.
  /// Zde se definují ASCII řetězce pro String Descriptory (musí být správné pořadí)
  usb.setStrings ("Mrazik labs.","Test C++ Class","00ABCD");
  //vcom.setString ("USB <=> Serial");
  //test.setString ("Server");
  disc.setString ("USB Mass Storage");	/// I každá třída má popis
  usb.blddsc  ();	/// Vytvoří soubor dscbld.c obsahující všechny konstantní Descriptory
  printf ("GCC %d.%d\n", __GNUC__, __GNUC_MINOR__);
  return 0;
}

#endif // DSCBLD

