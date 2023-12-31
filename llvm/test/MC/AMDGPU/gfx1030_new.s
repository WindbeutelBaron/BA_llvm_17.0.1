// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1030 -show-encoding %s | FileCheck --check-prefix=GFX10 %s
// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1031 -show-encoding %s | FileCheck --check-prefix=GFX10 %s
// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1032 -show-encoding %s | FileCheck --check-prefix=GFX10 %s
// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1033 -show-encoding %s | FileCheck --check-prefix=GFX10 %s
// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1034 -show-encoding %s | FileCheck --check-prefix=GFX10 %s
// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1035 -show-encoding %s | FileCheck --check-prefix=GFX10 %s
// RUN: llvm-mc -arch=amdgcn -mcpu=gfx1036 -show-encoding %s | FileCheck --check-prefix=GFX10 %s

global_load_dword_addtid v1, s[2:3] offset:16
// GFX10: encoding: [0x10,0x80,0x58,0xdc,0x00,0x00,0x02,0x01]

global_load_dword_addtid v1, s[2:3] offset:16 glc slc dlc
// GFX10: encoding: [0x10,0x90,0x5b,0xdc,0x00,0x00,0x02,0x01]

global_store_dword_addtid v1, s[2:3] offset:16 glc slc dlc
// GFX10: encoding: [0x10,0x90,0x5f,0xdc,0x00,0x01,0x02,0x00]

global_load_dword_addtid v1, off offset:16
// GFX10: encoding: [0x10,0x80,0x58,0xdc,0x00,0x00,0x7d,0x01]

global_load_dword_addtid v1, off offset:16 glc slc dlc
// GFX10: encoding: [0x10,0x90,0x5b,0xdc,0x00,0x00,0x7d,0x01]

global_store_dword_addtid v1, off offset:16 glc slc dlc
// GFX10: encoding: [0x10,0x90,0x5f,0xdc,0x00,0x01,0x7d,0x00]

global_store_dword v254, v1, s[2:3] offset:16
// GFX10: encoding: [0x10,0x80,0x70,0xdc,0xfe,0x01,0x02,0x00]

global_atomic_csub v2, v[0:1], v2, off offset:100 glc slc
// GFX10: encoding: [0x64,0x80,0xd3,0xdc,0x00,0x02,0x7d,0x02]

global_atomic_csub v2, v[0:1], v2, off glc
// GFX10: encoding: [0x00,0x80,0xd1,0xdc,0x00,0x02,0x7d,0x02]

global_atomic_csub v2, v0, v2, s[2:3] glc
// GFX10: encoding: [0x00,0x80,0xd1,0xdc,0x00,0x02,0x02,0x02]

global_atomic_csub v2, v0, v2, s[2:3] offset:100 glc slc
// GFX10: encoding: [0x64,0x80,0xd3,0xdc,0x00,0x02,0x02,0x02]

buffer_atomic_csub v5, off, s[8:11], s3 glc
// GFX10: encoding: [0x00,0x40,0xd0,0xe0,0x00,0x05,0x02,0x03]

buffer_atomic_csub v5, off, s[8:11], s3 offset:4095 glc
// GFX10: encoding: [0xff,0x4f,0xd0,0xe0,0x00,0x05,0x02,0x03]

buffer_atomic_csub v5, off, s[8:11], -1 offset:4095 glc
// GFX10: encoding: [0xff,0x4f,0xd0,0xe0,0x00,0x05,0x02,0xc1]

buffer_atomic_csub v5, v0, s[8:11], s3 offen offset:4095 glc
// GFX10: encoding: [0xff,0x5f,0xd0,0xe0,0x00,0x05,0x02,0x03]

buffer_atomic_csub v5, v0, s[8:11], s3 idxen offset:4095 glc
// GFX10: encoding: [0xff,0x6f,0xd0,0xe0,0x00,0x05,0x02,0x03]

buffer_atomic_csub v5, off, s[8:11], s3 glc slc
// GFX10: encoding: [0x00,0x40,0xd0,0xe0,0x00,0x05,0x42,0x03]

s_getreg_b32 s2, hwreg(HW_REG_SHADER_CYCLES)
// GFX10: encoding: [0x1d,0xf8,0x02,0xb9]

s_getreg_b32 s2, 29
// GFX10: s_getreg_b32 s2, hwreg(HW_REG_SHADER_CYCLES, 0, 1) ; encoding: [0x1d,0x00,0x02,0xb9]

s_getreg_b32 s2, hwreg(22)
// GFX10: s_getreg_b32 s2, hwreg(22) ; encoding: [0x16,0xf8,0x02,0xb9]

v_fma_legacy_f32 v0, v1, v2, v3
// GFX10: encoding: [0x00,0x00,0x40,0xd5,0x01,0x05,0x0e,0x04]

v_fma_legacy_f32 v0, v1, |v2|, -v3
// GFX10: encoding: [0x00,0x02,0x40,0xd5,0x01,0x05,0x0e,0x84]

v_fma_legacy_f32 v0, s1, 2.0, -v3
// GFX10: encoding: [0x00,0x00,0x40,0xd5,0x01,0xe8,0x0d,0x84]

v_fmac_legacy_f32 v0, v1, v2
// GFX10: encoding: [0x01,0x05,0x00,0x0c]

v_fmac_legacy_f32 v0, |v1|, -v2
// GFX10: encoding: [0x00,0x01,0x06,0xd5,0x01,0x05,0x02,0x40]

v_fmac_legacy_f32 v0, s1, 2.0
// GFX10: encoding: [0x00,0x00,0x06,0xd5,0x01,0xe8,0x01,0x00]

image_bvh_intersect_ray v[4:7], v[9:19], s[4:7]
// GFX10: encoding: [0x01,0x9f,0x98,0xf1,0x09,0x04,0x01,0x00]

image_bvh_intersect_ray v[4:7], v[9:19], s[4:7] noa16
// GFX10: encoding: [0x01,0x9f,0x98,0xf1,0x09,0x04,0x01,0x00]

image_bvh_intersect_ray v[4:7], v[9:16], s[4:7] a16
// GFX10: encoding: [0x01,0x9f,0x98,0xf1,0x09,0x04,0x01,0x40]

image_bvh64_intersect_ray v[4:7], v[9:20], s[4:7]
// GFX10: encoding: [0x01,0x9f,0x9c,0xf1,0x09,0x04,0x01,0x00]

image_bvh64_intersect_ray v[4:7], v[9:17], s[4:7] a16
// GFX10: encoding: [0x01,0x9f,0x9c,0xf1,0x09,0x04,0x01,0x40]

image_bvh_intersect_ray v[39:42], [v50, v46, v23, v17, v16, v15, v21, v20, v19, v37, v40], s[12:15]
// GFX10: encoding: [0x07,0x9f,0x98,0xf1,0x32,0x27,0x03,0x00,0x2e,0x17,0x11,0x10,0x0f,0x15,0x14,0x13,0x25,0x28,0x00,0x00]

image_bvh_intersect_ray v[39:42], [v50, v46, v23, v17, v16, v15, v21, v20, v19, v37, v40], s[12:15] noa16
// GFX10: encoding: [0x07,0x9f,0x98,0xf1,0x32,0x27,0x03,0x00,0x2e,0x17,0x11,0x10,0x0f,0x15,0x14,0x13,0x25,0x28,0x00,0x00]

image_bvh_intersect_ray v[39:42], [v50, v46, v23, v17, v16, v15, v21, v20], s[12:15] a16
// GFX10: encoding: [0x05,0x9f,0x98,0xf1,0x32,0x27,0x03,0x40,0x2e,0x17,0x11,0x10,0x0f,0x15,0x14,0x00]

image_bvh64_intersect_ray v[39:42], [v50, v46, v23, v17, v16, v15, v21, v20, v19, v37, v40, v42], s[12:15]
// GFX10: encoding: [0x07,0x9f,0x9c,0xf1,0x32,0x27,0x03,0x00,0x2e,0x17,0x11,0x10,0x0f,0x15,0x14,0x13,0x25,0x28,0x2a,0x00]

image_bvh64_intersect_ray v[39:42], [v50, v46, v23, v17, v16, v15, v21, v20, v19], s[12:15] a16
// GFX10: encoding: [0x05,0x9f,0x9c,0xf1,0x32,0x27,0x03,0x40,0x2e,0x17,0x11,0x10,0x0f,0x15,0x14,0x13]

image_msaa_load v[1:4], v[5:7], s[8:15] dmask:0xf dim:SQ_RSRC_IMG_2D_MSAA
// GFX10: encoding: [0x31,0x0f,0x00,0xf0,0x05,0x01,0x02,0x00]

image_msaa_load v[1:4], v[5:7], s[8:15] dmask:0xf dim:SQ_RSRC_IMG_2D_MSAA glc
// GFX10: encoding: [0x31,0x2f,0x00,0xf0,0x05,0x01,0x02,0x00]

image_msaa_load v5, v[1:3], s[8:15] dmask:0x1 dim:SQ_RSRC_IMG_2D_MSAA d16
// GFX10: encoding: [0x31,0x01,0x00,0xf0,0x01,0x05,0x02,0x80]

image_msaa_load v[1:4], v[5:8], s[8:15] dmask:0xf dim:SQ_RSRC_IMG_2D_MSAA_ARRAY
// GFX10: encoding: [0x39,0x0f,0x00,0xf0,0x05,0x01,0x02,0x00]

image_msaa_load v14, [v204,v11,v14,v19], s[40:47] dmask:0x1 dim:SQ_RSRC_IMG_2D_MSAA_ARRAY
// GFX10: encoding: [0x3b,0x01,0x00,0xf0,0xcc,0x0e,0x0a,0x00,0x0b,0x0e,0x13,0x00]

//===----------------------------------------------------------------------===//
// s_waitcnt_depctr.
//===----------------------------------------------------------------------===//

s_waitcnt_depctr -32768
// GFX10: encoding: [0x00,0x80,0xa3,0xbf]

s_waitcnt_depctr 65535
// GFX10: encoding: [0xff,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_hold_cnt(0)
// GFX10: encoding: [0x1f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_hold_cnt(1)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_sa_sdst(0)
// GFX10: encoding: [0x9e,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_sa_sdst(1)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_va_vdst(0)
// GFX10: encoding: [0x9f,0x0f,0xa3,0xbf]

s_waitcnt_depctr depctr_va_vdst(1)
// GFX10: encoding: [0x9f,0x1f,0xa3,0xbf]

s_waitcnt_depctr depctr_va_vdst(14)
// GFX10: encoding: [0x9f,0xef,0xa3,0xbf]

s_waitcnt_depctr depctr_va_vdst(15)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_va_sdst(0)
// GFX10: encoding: [0x9f,0xf1,0xa3,0xbf]

s_waitcnt_depctr depctr_va_sdst(1)
// GFX10: encoding: [0x9f,0xf3,0xa3,0xbf]

s_waitcnt_depctr depctr_va_sdst(6)
// GFX10: encoding: [0x9f,0xfd,0xa3,0xbf]

s_waitcnt_depctr depctr_va_sdst(7)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_va_ssrc(0)
// GFX10: encoding: [0x9f,0xfe,0xa3,0xbf]

s_waitcnt_depctr depctr_va_ssrc(1)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_va_vcc(0)
// GFX10: encoding: [0x9d,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_va_vcc(1)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_vm_vsrc(0)
// GFX10: encoding: [0x83,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_vm_vsrc(1)
// GFX10: encoding: [0x87,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_vm_vsrc(6)
// GFX10: encoding: [0x9b,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_vm_vsrc(7)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_hold_cnt(0) depctr_sa_sdst(0) depctr_va_vdst(0) depctr_va_sdst(0) depctr_va_ssrc(0) depctr_va_vcc(0) depctr_vm_vsrc(0)
// GFX10: encoding: [0x00,0x00,0xa3,0xbf]

s_waitcnt_depctr depctr_hold_cnt(1) depctr_sa_sdst(1) depctr_va_vdst(15) depctr_va_sdst(7) depctr_va_ssrc(1) depctr_va_vcc(1) depctr_vm_vsrc(7)
// GFX10: encoding: [0x9f,0xff,0xa3,0xbf]

s_waitcnt_depctr depctr_hold_cnt(1) & depctr_sa_sdst(1) & depctr_va_vdst(1) & depctr_va_sdst(1) & depctr_va_ssrc(1) & depctr_va_vcc(1) & depctr_vm_vsrc(1)
// GFX10: encoding: [0x87,0x13,0xa3,0xbf]

s_waitcnt_depctr depctr_hold_cnt(1), depctr_sa_sdst(1), depctr_va_vdst(14), depctr_va_sdst(6), depctr_va_ssrc(1), depctr_va_vcc(1), depctr_vm_vsrc(6)
// GFX10: encoding: [0x9b,0xed,0xa3,0xbf]

scratch_load_dword off, off offset:1024 lds
// GFX10: [0x00,0x64,0x30,0xdc,0x00,0x00,0x7f,0x00]

scratch_load_ubyte off, off offset:1024 lds
// GFX10: [0x00,0x64,0x20,0xdc,0x00,0x00,0x7f,0x00]

scratch_load_sbyte off, off offset:1024 lds
// GFX10: [0x00,0x64,0x24,0xdc,0x00,0x00,0x7f,0x00]

scratch_load_ushort off, off offset:1024 lds
// GFX10: [0x00,0x64,0x28,0xdc,0x00,0x00,0x7f,0x00]

scratch_load_sshort off, off offset:1024 lds
// GFX10: [0x00,0x64,0x2c,0xdc,0x00,0x00,0x7f,0x00]
