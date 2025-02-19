#if defined(_WIN32) || defined(_WIN64)

// COFF Header Section
#include <Windows.h>

// COFF magic numbers for different architectures
#define COFF_MAGIC_NUMBER_I386  0x14c  // Magic number for x86 architecture
#define COFF_MAGIC_NUMBER_AMD64 0x8664 // Magic number for x64 architecture

#define IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#define IMAGE_SUBSYSTEM_WINDOWS_CUI 3

// Structure for the COFF Header
typedef struct
{
    UINT16 Machine;              // Target machine identifier
    UINT16 NumberOfSections;     // Number of sections in the file
    UINT32 TimeDateStamp;        // Timestamp of the file creation
    UINT32 PointerToSymbolTable; // Pointer to the symbol table (if present)
    UINT32 NumberOfSymbols;      // Number of symbols in the symbol table
    UINT16 SizeOfOptionalHeader; // Size of the optional header
    UINT16 Characteristics;      // Characteristics of the file (e.g., executable, DLL)
} COFF_HEADER;

// Structure for Section Header
typedef struct 
{
    UINT32 Name;                 // Name of the section
    UINT32 PhysicalAddress;      // Address of the section
    UINT32 VirtualSize;          // Size of the section
    UINT32 RawDataSize;          // Size of the raw data
    UINT32 PointerToRawData;     // Pointer to the raw data
    UINT32 PointerToRelocations; // Pointer to the relocations
    UINT32 PointerToLinenumbers; // Pointer to the line numbers
    UINT16 NumberOfRelocations;  // Number of relocations
    UINT16 NumberOfLinenumbers;  // Number of line numbers
    UINT32 Characteristics;       // Characteristics
} SECTION_HEADER;

// Structure for Section Optional
typedef struct {
    WORD    Magic;                   // Magic number
    BYTE    MajorLinkerVersion;      // Major version of the linker
    BYTE    MinorLinkerVersion;      // Minor version of the linker
    DWORD   SizeOfCode;              // Size of the code section
    DWORD   SizeOfInitializedData;   // Size of initialized data
    DWORD   SizeOfUninitializedData; // Size of uninitialized data
    DWORD   AddressOfEntryPoint;     // Address of entry point
    DWORD   BaseOfCode;              // Base address of the code section
    DWORD   BaseOfData;              // Base address of the data section (for PE32 only)
    DWORD   ImageBase;               // Preferred load address
    DWORD   SectionAlignment;         // Section alignment (bytes)
    DWORD   FileAlignment;            // File alignment (bytes)
    WORD    MajorOperatingSystemVersion; // OS version
    WORD    MinorOperatingSystemVersion; // OS version
    WORD    MajorImageVersion;       // Image version
    WORD    MinorImageVersion;       // Image version
    WORD    MajorSubsystemVersion;   // Subsystem version
    WORD    MinorSubsystemVersion;   // Subsystem version
    DWORD   Win32VersionValue;       // Reserved, must be zero
    DWORD   SizeOfImage;             // Size of the image (in bytes)
    DWORD   SizeOfHeaders;           // Size of headers (in bytes)
    DWORD   CheckSum;                // Checksum
    WORD    Subsystem;               // Subsystem type
    WORD    DLLCharacteristics;      // DLL characteristics
    DWORD   SizeOfStackReserve;      // Size of stack reserve
    DWORD   SizeOfStackCommit;       // Size of stack commit
    DWORD   SizeOfHeapReserve;       // Size of heap reserve
    DWORD   SizeOfHeapCommit;        // Size of heap commit
    DWORD   LoaderFlags;             // Loader flags
    DWORD   NumberOfRvaAndSizes;     // Number of data directories
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES]; // Data directories
} SECTION_OPTIONAL;

#endif /* defined(_WIN32) || defined(_WIN64) */