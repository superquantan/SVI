#include "efi.h"
EFI_STATUS Print(EFI_SYSTEM_TABLE *Table, CHAR16 *String)
{
	return Table->ConOut->OutputString(Table->ConOut, String);
}
