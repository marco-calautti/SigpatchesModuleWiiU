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

#define VALUE_A 0xe3a00000 // mov r0, #0
#define VALUE_B 0xe12fff1e // bx lr
#define VALUE_C 0x20004770 // mov r0, #0; bx lr

int main(int argc, char **argv)
{
    int res = IOSUHAX_Open(nullptr);
    if (res >= 0) {
        IOSUHAX_kern_write32(0x5014cac,VALUE_C); // patch_MCP_authentication_check
        IOSUHAX_kern_write32(0x5052c44,VALUE_A); // patch_IOSC_VerifyPubkeySign - first u32
        IOSUHAX_kern_write32(0x5052c48,VALUE_B); // patch_IOSC_VerifyPubkeySign - second u32
        IOSUHAX_kern_write32(0x5052a90,VALUE_A); // patch_cert_verification - first u32
        IOSUHAX_kern_write32(0x5052a94,VALUE_B); // patch_cert_verification - second u32
        IOSUHAX_kern_write32(0x5054d6c,VALUE_A); // patch_cached_cert_check - first u32
        IOSUHAX_kern_write32(0x5054d70,VALUE_B); // patch_cached_cert_check - second u32
        IOSUHAX_Close();
    }
    
    return 0;
}

