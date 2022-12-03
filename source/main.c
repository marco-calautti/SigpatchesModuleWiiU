/*  This module assumes the IOSUHAX exploit to have been performed (e.g., 00_mocha.rpx has been executed before this module).
    
    This module implements the following patches from the original Mocha CFW:

    .arm

    patch_MCP_authentication_check:
        .thumb
        mov r0, #0
        bx lr

    patch_IOSC_VerifyPubkeySign:
    patch_cert_verification:
    patch_cached_cert_check:
        .arm
        mov r0, #0
        bx lr


    .globl mcp_patches_table, mcp_patches_table_end
    mcp_patches_table:
    #          origin           data                                    size
        .word 0x05014CAC,      patch_MCP_authentication_check,         4
        .word 0x05052C44,      patch_IOSC_VerifyPubkeySign,            8
        .word 0x05052A90,      patch_cert_verification,                8
        .word 0x05054D6C,      patch_cached_cert_check,                8
    mcp_patches_table_end:
*/


#include <iosuhax.h>
#include <stddef.h>

int main()
{
    int res = IOSUHAX_Open(NULL);
    if (res >= 0) {
        IOSUHAX_kern_write32(0x5014cac,0x20004770); // patch_MCP_authentication_check
        IOSUHAX_kern_write32(0x5052c44,0xe3a00000); // patch_IOSC_VerifyPubkeySign - first u32
        IOSUHAX_kern_write32(0x5052c48,0xe12fff1e); // patch_IOSC_VerifyPubkeySign - second u32
        IOSUHAX_kern_write32(0x5052a90,0xe3a00000); // patch_cert_verification - first u32
        IOSUHAX_kern_write32(0x5052a94,0xe12fff1e); // patch_cert_verification - second u32
        IOSUHAX_kern_write32(0x5054d6c,0xe3a00000); // patch_cached_cert_check - first u32
        IOSUHAX_kern_write32(0x5054d70,0xe12fff1e); // patch_cached_cert_check - second u32
        IOSUHAX_Close();
    }

    return 0;
}

