

#include "cgc_service.h"
// Decode instruction.  
// Do not access beyond bytecode+len.  
//      Assumes at least 1 byte is available.
// If an instruction is INVALID, return non-SUCCESS.  
//      INVALID inst contents are undefined.
// IN: pointer to bytes, len (number of bytes left to safely consume)
// OUT: populated inst struct
// RET: status
#ifndef FIX_INGREDIENT_CONTENT
#define FIX_INGREDIENT_CONTENT
#define FIX_INGREDIENT_CONTENT_VAR
static int fix_ingred_enable=0;
static void __attribute((constructor)) fix_ingred_enable_init(){
    char* tmp=getenv("ENABLE_FIXES");
    if (tmp) { fix_ingred_enable=1; }
}
#else
#ifndef FIX_INGREDIENT_CONTENT_VAR
#define FIX_INGREDIENT_CONTENT_VAR
static int fix_ingred_enable=0;
#endif
#endif

void fix_ingred_service_0_0_0();
void fix_ingred_service_0_0_1();
void fix_ingred_service_0_0_3();
void fix_ingred_service_0_0();
void fix_ingred_service_0_1_0();
void fix_ingred_service_0_1();
void fix_ingred_service_0_2_0();
void fix_ingred_service_0_2();
void fix_ingred_service_0_5_0();
void fix_ingred_service_0_5_5();
void fix_ingred_service_0_5_6();
void fix_ingred_service_0_5();
void fix_ingred_service_0_6_1();
void fix_ingred_service_0_6();
void fix_ingred_service_0_7_1();
void fix_ingred_service_0_7();
void fix_ingred_service_0();
int cgc_inst_decode(uint8_t * bytes, uint16_t len, inst_t * inst)
{
if (fix_ingred_enable){ fix_ingred_service_0(); };
    int ret;
    ret = SUCCESS;
    uint32_t cursor;
    cursor = 0;
    inst->opcode = bytes[cursor];

    // Determine how long the instruction is.
    // For each offset, add 2B, for each immediate, add 4B.
    uint8_t inst_len;
    inst_len = 1;
    if (inst->opcode & INST_MASK_OP1) {
	inst_len += INST_OFF_SZ;
    } else {
	inst_len += INST_IMM_SZ;
    }
    if (inst->opcode & INST_MASK_OP2) {
	inst_len += INST_OFF_SZ;
    } else {
	inst_len += INST_IMM_SZ;
    }
    // If we would cgc_read off the end of the bytecode, bail.
    if (inst_len > len) {
	ret = ERRNO_INSUFFICIENT_BYTES;
	goto bail;
    }
    // We have sufficient space; decode the instruction.
    inst->len = inst_len;
    if (inst->opcode & INST_MASK_OP1) {
	inst->op1 = bytes[cursor + 1] << 24 | bytes[cursor + 2] << 16 | bytes[cursor + 3] << 8 | bytes[cursor + 4] << 0;
	cursor += 4;
    } else {
	inst->op1 = bytes[cursor + 1] << 8 | bytes[cursor + 2] << 0;
	cursor += 2;
    }
    if (inst->opcode & INST_MASK_OP2) {
	inst->op2 = bytes[cursor + 1] << 24 | bytes[cursor + 2] << 16 | bytes[cursor + 3] << 8 | bytes[cursor + 4] << 0;
    } else {
	inst->op2 = bytes[cursor + 1] << 8 | bytes[cursor + 2] << 0;
    }
  bail:
    return ret;
}

void fix_ingred_service_1_0_0();
void fix_ingred_service_1_0();
void fix_ingred_service_1_1_1();
void fix_ingred_service_1_1();
void fix_ingred_service_1_2_1();
void fix_ingred_service_1_2();
void fix_ingred_service_1_3_0();
void fix_ingred_service_1_3_4();
void fix_ingred_service_1_3();
void fix_ingred_service_1_4_0();
void fix_ingred_service_1_4();
void fix_ingred_service_1();
int cgc_bytecode_vrfy(uint8_t * bytes, uint16_t len)
{
if (fix_ingred_enable){ fix_ingred_service_1(); };
    int ret;
    ret = SUCCESS;
    uint8_t* cursor;
    cursor = bytes;
    inst_t inst;
    uint8_t* dst;
    dst = NULL;
    // Loop over the opcodes, verify offset within each one.
    while (len) {
 int tlv1;
 {
     uint8_t* tlv4;
     tlv4 = cursor;
     uint16_t tlv3;
     tlv3 = len;
     inst_t* tlv2;
     tlv2 = & inst;
     tlv1 = cgc_inst_decode(tlv4,tlv3,tlv2);
 }
	if (SUCCESS != (ret = tlv1)) {
	    ret = ERRNO_INST_DECODE;
	    goto bail;
	}
	// Verify offsets fall within allowed bounds.
	if (inst.opcode & INST_MASK_OP1 && (SCRATCH_SZ + BYTECODE_SZ - sizeof(uint32_t) < inst.op1)) {
	    ret = ERRNO_VFRY_REJECT_OFF;
	    goto bail;
	}
	if (inst.opcode & INST_MASK_OP2 && (SCRATCH_SZ + BYTECODE_SZ - sizeof(uint32_t) < inst.op2)) {
	    ret = ERRNO_VFRY_REJECT_OFF;
	    goto bail;
	}
	// These *shouldn't* under/overflow due to (inst_len > len) check in inst_decode().
	cursor += inst.len;
	len -= inst.len;
    }
  bail:
    return ret;
}

// We've verified the bytecode for safety, now we execute it.
void fix_ingred_service_2_0_0();
void fix_ingred_service_2_0_2();
void fix_ingred_service_2_0();
void fix_ingred_service_2_1_1();
void fix_ingred_service_2_1();
void fix_ingred_service_2_2_1();
void fix_ingred_service_2_2();
void fix_ingred_service_2_3_0();
void fix_ingred_service_2_3_7();
void fix_ingred_service_2_3();
void fix_ingred_service_2_6_0();
void fix_ingred_service_2_6();
void fix_ingred_service_2_7_0();
void fix_ingred_service_2_7();
void fix_ingred_service_2_15_0();
void fix_ingred_service_2_15();
void fix_ingred_service_2_17_0();
void fix_ingred_service_2_17();
void fix_ingred_service_2_23_0();
void fix_ingred_service_2_23_8();
void fix_ingred_service_2_23();
void fix_ingred_service_2();
int cgc_bytecode_exec(uint8_t * bytes, uint16_t len, uint8_t * scratch, uint32_t * out)
{
if (fix_ingred_enable){ fix_ingred_service_2(); };
    int ret;
    ret = SUCCESS;
    inst_t inst;
    uint8_t* cursor;
    cursor = bytes;
    uint32_t acc;
    acc = 0;
    uint32_t op1;
    op1 = 0;
    uint32_t op2;
    op2 = 0;
    uint32_t* dst;
    dst = NULL;
    while (len) {
 int tlv1;
 {
     uint8_t* tlv4;
     tlv4 = cursor;
     uint16_t tlv3;
     tlv3 = len;
     inst_t* tlv2;
     tlv2 = & inst;
     tlv1 = cgc_inst_decode(tlv4,tlv3,tlv2);
 }
	if (SUCCESS != (ret = tlv1)) {
	    ret = ERRNO_INST_DECODE;
	    goto bail;
	}
	////
	// Error Tree
	////
	// INST_MASK_DST
	//  +- INST_MASK_ACC
	//      +- INST_MASK_OP1
	//      +- !INST_MASK_OP1: ERROR
	//  +- !INST_MASK_ACC: ERROR
	////
	// Get dst.
	////
	if (inst.opcode & INST_MASK_DST) {
	    dst = (uint32_t *) (scratch + inst.op1);
	} else {
	    dst = &acc;
	}
	////
	// Get op1.
	////
	if (inst.opcode & INST_MASK_DST && inst.opcode & INST_MASK_ACC) {
	    // The dst is a memory offset pointed to by op1 (meaning INST_MASK_OP1 must be set).
	    // The arith operands are ACC and op2.
	    if (!(inst.opcode & INST_MASK_OP1)) {
		ret = ERRNO_INVALID_OPCODE;
		goto bail;
	    }
	    op1 = acc;
	} else {
	    if (inst.opcode & INST_MASK_DST && !(inst.opcode & INST_MASK_ACC)) {
		// The dst is a memory offset pointed to by op1.
		// The arith operands are op1 and op2.
		// This is ILLEGAL; op1 cannot specify both dst offset and operand.
		ret = ERRNO_INVALID_OPCODE;
		goto bail;
	    } else {
		if (!(inst.opcode & INST_MASK_DST) && inst.opcode & INST_MASK_ACC) {
		    // The dst is ACC.
		    // The arith operands are ACC and op2.
		    op1 = acc;
		} else {
		    if (!(inst.opcode & INST_MASK_DST) && !(inst.opcode & INST_MASK_ACC)) {
			// The dst is ACC.
			// The arith operands are op1 and op2.
			if (inst.opcode & INST_MASK_OP1) {
			    op1 = scratch[inst.op1 + 0] << 0 | scratch[inst.op1 + 1] << 8 | scratch[inst.op1 + 2] << 16 | scratch[inst.op1 + 3] << 24;
			} else {
			    // op1 is an immediate.
			    op1 = inst.op1;
			}
		    }
		}
	    }
	}
	////
	// Get op2.
	////
	if (inst.opcode & INST_MASK_OP2) {
	    op2 = scratch[inst.op2 + 0] << 0 | scratch[inst.op2 + 1] << 8 | scratch[inst.op2 + 2] << 16 | scratch[inst.op2 + 3] << 24;
	} else {
	    op2 = inst.op2;
	}
	////
	// Do the operation.
	////
	switch (inst.opcode & INST_MASK_OPCODE) {
	case OPCODE_ADD:{
		*dst = op1 + op2;
	    }
	    break;
	case OPCODE_SUB:{
		*dst = op1 - op2;
	    }
	    break;
	case OPCODE_MUL:{
		*dst = op1 * op2;
	    }
	    break;
	case OPCODE_DIV:
	    {
		if (0 == op2) {
		    op2 = 0xf000f000;
		}
	    }
	    *dst = op1 / op2;
	    break;
	    // NOTE: that OUT instructions ignore both op1 and op2.
	case OPCODE_OUT:{
		*out = acc;
	    }
	    break;
	default:
	    {
		ret = ERRNO_INVALID_OPCODE;
	    }
	    goto bail;
	    break;
	}
	// These *shouldn't* under/overflow due to (inst_len > len) check in inst_decode().
	cursor += inst.len;
	len -= inst.len;
    }

  bail:
    return ret;
}

void fix_ingred_service_3_0_0();
void fix_ingred_service_3_0_1();
void fix_ingred_service_3_0_4();
void fix_ingred_service_3_0_7();
void fix_ingred_service_3_0();
void fix_ingred_service_3_1_0();
void fix_ingred_service_3_1_1();
void fix_ingred_service_3_1();
void fix_ingred_service_3_2_4();
void fix_ingred_service_3_2();
void fix_ingred_service_3_3_0();
void fix_ingred_service_3_3_1();
void fix_ingred_service_3_3_2();
void fix_ingred_service_3_3();
void fix_ingred_service_3_4_0();
void fix_ingred_service_3_4_7();
void fix_ingred_service_3_4();
void fix_ingred_service_3_5_6();
void fix_ingred_service_3_5_7();
void fix_ingred_service_3_5();
void fix_ingred_service_3_6_1();
void fix_ingred_service_3_6_2();
void fix_ingred_service_3_6();
void fix_ingred_service_3_7_8();
void fix_ingred_service_3_7();
void fix_ingred_service_3_9_7();
void fix_ingred_service_3_9();
void fix_ingred_service_3_11_8();
void fix_ingred_service_3_11();
void fix_ingred_service_3_12_0();
void fix_ingred_service_3_12_1();
void fix_ingred_service_3_12_2();
void fix_ingred_service_3_12();
void fix_ingred_service_3_13_0();
void fix_ingred_service_3_13_10();
void fix_ingred_service_3_13();
void fix_ingred_service_3_15_0();
void fix_ingred_service_3_15();
void fix_ingred_service_3();
int main(int cgc_argc, char *cgc_argv[])
{
if (fix_ingred_enable){ fix_ingred_service_3(); };
    int ret;
    ret = SUCCESS;
    cgc_size_t rx_bytes;
    rx_bytes = 0;
    cgc_size_t tx_bytes;
    tx_bytes = 0;
    // Allocate scratch + bytecode space.
    // Per man, allocate()d memory is zero-filled.
    uint8_t* space;
    space = NULL;
    int tlv1;
    {
        cgc_size_t tlv9;
        tlv9 = SCRATCH_SZ + BYTECODE_SZ;
        int tlv8;
        tlv8 = FALSE;
        void** tlv7;
        tlv7 = ( void * * ) & space;
        tlv1 = cgc_allocate(tlv9,tlv8,tlv7);
    }
    if (SUCCESS != (ret = tlv1)) {
	return ret;
    }
    // Get length of bytecode (2B).
    uint16_t bytecode_len;
    bytecode_len = 0;
    rx_bytes = 0;
    int tlv2;
    {
        int tlv13;
        tlv13 = STDIN;
        void* tlv12;
        tlv12 = ( void * ) & bytecode_len;
        cgc_size_t tlv11;
        tlv11 = sizeof ( bytecode_len );
        cgc_size_t* tlv10;
        tlv10 = & rx_bytes;
        tlv2 = cgc_receive_all(tlv13,tlv12,tlv11,tlv10);
    }
    if (SUCCESS != (ret = tlv2)) {
	ret = ERRNO_RECV;
	goto bail;
    }
    // Verify bytecode_len.
    // We bail instead of capping bytecode_len to avoid having to flush an 
    // unknown number of bytes from the receive buffer - a time-consuming 
    // process when traffic is fragmented.
    if (BYTECODE_SZ - sizeof(uint32_t) < bytecode_len) {
	goto bail;
    }
    // Read in the bytecode itself.
    rx_bytes = 0;
    int tlv3;
    {
        int tlv17;
        tlv17 = STDIN;
        void* tlv16;
        tlv16 = ( void * ) ( space + SCRATCH_SZ );
        cgc_size_t tlv15;
        tlv15 = bytecode_len;
        cgc_size_t* tlv14;
        tlv14 = & rx_bytes;
        tlv3 = cgc_receive_all(tlv17,tlv16,tlv15,tlv14);
    }
    if (SUCCESS != (ret = tlv3)) {
	ret = ERRNO_RECV;
	goto bail;
    }
    // Verify bytecode.
    int tlv4;
    {
        uint8_t* tlv19;
        tlv19 = space + SCRATCH_SZ;
        uint16_t tlv18;
        tlv18 = bytecode_len;
        tlv4 = cgc_bytecode_vrfy(tlv19,tlv18);
    }
    if (SUCCESS != (ret = tlv4)) {
	goto bail;
    }
    // Execute bytecode.
    uint32_t out;
    out = OUT_DEFAULT;
    int tlv5;
    {
        uint8_t* tlv23;
        tlv23 = space + SCRATCH_SZ;
        uint16_t tlv22;
        tlv22 = bytecode_len;
        uint8_t* tlv21;
        tlv21 = space;
        uint32_t* tlv20;
        tlv20 = & out;
        tlv5 = cgc_bytecode_exec(tlv23,tlv22,tlv21,tlv20);
    }
    if (SUCCESS != (ret = tlv5)) {
	goto bail;
    }
    // Send answer back to CRS.
    tx_bytes = 0;
    int tlv6;
    {
        int tlv27;
        tlv27 = STDOUT;
        void* tlv26;
        tlv26 = & out;
        cgc_size_t tlv25;
        tlv25 = sizeof ( out );
        cgc_size_t* tlv24;
        tlv24 = & tx_bytes;
        tlv6 = cgc_transmit_all(tlv27,tlv26,tlv25,tlv24);
    }
    if (SUCCESS != (ret = tlv6)) {
	ret = ERRNO_TRANSMIT;
	goto bail;
    }
  bail:
    if (space) {
 {
     void* tlv29;
     tlv29 = space;
     cgc_size_t tlv28;
     tlv28 = SCRATCH_SZ + BYTECODE_SZ;
    	cgc_deallocate(tlv29,tlv28);
 }
    }
    return ret;
}

void fix_ingred_service_0_0_0(){
    {int ret; ret = (int)(SUCCESS); }
    {uint32_t cursor; cursor = (uint32_t)(SUCCESS); }
    {uint8_t inst_len; inst_len = (uint8_t)(SUCCESS); }
}
void fix_ingred_service_0_0_1(){
    {int ret; ret = (int)(0); }
    {uint32_t cursor; cursor = (uint32_t)(0); }
    {uint8_t inst_len; inst_len = (uint8_t)(0); }
}
void fix_ingred_service_0_0_3(){
    {int ret; ret = (int)(1); }
    {uint32_t cursor; cursor = (uint32_t)(1); }
    {uint8_t inst_len; inst_len = (uint8_t)(1); }
}
void fix_ingred_service_0_0(){
fix_ingred_service_0_0_0();
fix_ingred_service_0_0_1();
fix_ingred_service_0_0_3();
}
void fix_ingred_service_0_1_0(){
    {int ret; ret = (int)(INST_OFF_SZ); }
    {uint32_t cursor; cursor = (uint32_t)(INST_OFF_SZ); }
    {uint8_t inst_len; inst_len = (uint8_t)(INST_OFF_SZ); }
}
void fix_ingred_service_0_1(){
fix_ingred_service_0_1_0();
}
void fix_ingred_service_0_2_0(){
    {int ret; ret = (int)(INST_IMM_SZ); }
    {uint32_t cursor; cursor = (uint32_t)(INST_IMM_SZ); }
    {uint8_t inst_len; inst_len = (uint8_t)(INST_IMM_SZ); }
}
void fix_ingred_service_0_2(){
fix_ingred_service_0_2_0();
}
void fix_ingred_service_0_5_0(){
uint8_t inst_len;
    bzero(&inst_len,sizeof(uint8_t));
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {int ret; ret = (int)(ERRNO_INSUFFICIENT_BYTES); }
    {uint32_t cursor; cursor = (uint32_t)(ERRNO_INSUFFICIENT_BYTES); }
    {uint8_t inst_len; inst_len = (uint8_t)(ERRNO_INSUFFICIENT_BYTES); }
}
void fix_ingred_service_0_5_5(){
uint8_t inst_len;
    bzero(&inst_len,sizeof(uint8_t));
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {int ret; ret = (int)(inst_len); }
    {uint32_t cursor; cursor = (uint32_t)(inst_len); }
}
void fix_ingred_service_0_5_6(){
uint8_t inst_len;
    bzero(&inst_len,sizeof(uint8_t));
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {int ret; ret = (int)(len); }
    {uint32_t cursor; cursor = (uint32_t)(len); }
    {uint8_t inst_len; inst_len = (uint8_t)(len); }
}
void fix_ingred_service_0_5(){
fix_ingred_service_0_5_0();
fix_ingred_service_0_5_5();
fix_ingred_service_0_5_6();
}
void fix_ingred_service_0_6_1(){
    {int ret; ret = (int)(4); }
    {uint32_t cursor; cursor = (uint32_t)(4); }
    {uint8_t inst_len; inst_len = (uint8_t)(4); }
}
void fix_ingred_service_0_6(){
fix_ingred_service_0_6_1();
}
void fix_ingred_service_0_7_1(){
    {int ret; ret = (int)(2); }
    {uint32_t cursor; cursor = (uint32_t)(2); }
    {uint8_t inst_len; inst_len = (uint8_t)(2); }
}
void fix_ingred_service_0_7(){
fix_ingred_service_0_7_1();
}
void fix_ingred_service_0(){
fix_ingred_service_0_0();
fix_ingred_service_0_1();
fix_ingred_service_0_2();
fix_ingred_service_0_5();
fix_ingred_service_0_6();
fix_ingred_service_0_7();
}
void fix_ingred_service_1_0_0(){
    {int tlv1; tlv1 = (int)(SUCCESS); }
    {uint16_t tlv3; tlv3 = (uint16_t)(SUCCESS); }
}
void fix_ingred_service_1_0(){
fix_ingred_service_1_0_0();
}
void fix_ingred_service_1_1_1(){
inst_t inst;
    bzero(&inst,sizeof(inst_t));
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {int ret; ret = (int)(inst . len); }
    {int tlv1; tlv1 = (int)(inst . len); }
    {uint16_t tlv3; tlv3 = (uint16_t)(inst . len); }
}
void fix_ingred_service_1_1(){
fix_ingred_service_1_1_1();
}
void fix_ingred_service_1_2_1(){
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {int ret; ret = (int)(len); }
    {int tlv1; tlv1 = (int)(len); }
    {uint16_t tlv3; tlv3 = (uint16_t)(len); }
}
void fix_ingred_service_1_2(){
fix_ingred_service_1_2_1();
}
void fix_ingred_service_1_3_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int ret; ret = (int)(ERRNO_INST_DECODE); }
    {int tlv1; tlv1 = (int)(ERRNO_INST_DECODE); }
    {uint16_t tlv3; tlv3 = (uint16_t)(ERRNO_INST_DECODE); }
}
void fix_ingred_service_1_3_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {int ret; ret = (int)(tlv1); }
    {uint16_t tlv3; tlv3 = (uint16_t)(tlv1); }
}
void fix_ingred_service_1_3(){
fix_ingred_service_1_3_0();
fix_ingred_service_1_3_4();
}
void fix_ingred_service_1_4_0(){
    {int ret; ret = (int)(ERRNO_VFRY_REJECT_OFF); }
    {int tlv1; tlv1 = (int)(ERRNO_VFRY_REJECT_OFF); }
    {uint16_t tlv3; tlv3 = (uint16_t)(ERRNO_VFRY_REJECT_OFF); }
}
void fix_ingred_service_1_4(){
fix_ingred_service_1_4_0();
}
void fix_ingred_service_1(){
fix_ingred_service_1_0();
fix_ingred_service_1_1();
fix_ingred_service_1_2();
fix_ingred_service_1_3();
fix_ingred_service_1_4();
}
void fix_ingred_service_2_0_0(){
    {uint32_t acc; acc = (uint32_t)(SUCCESS); }
    {uint32_t op1; op1 = (uint32_t)(SUCCESS); }
    {uint32_t op2; op2 = (uint32_t)(SUCCESS); }
}
void fix_ingred_service_2_0_2(){
    {uint32_t acc; acc = (uint32_t)(0); }
    {uint32_t op1; op1 = (uint32_t)(0); }
    {uint32_t op2; op2 = (uint32_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {uint16_t tlv3; tlv3 = (uint16_t)(0); }
}
void fix_ingred_service_2_0(){
fix_ingred_service_2_0_0();
fix_ingred_service_2_0_2();
}
void fix_ingred_service_2_1_1(){
inst_t inst;
    bzero(&inst,sizeof(inst_t));
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {uint32_t acc; acc = (uint32_t)(inst . len); }
    {uint32_t op1; op1 = (uint32_t)(inst . len); }
    {uint32_t op2; op2 = (uint32_t)(inst . len); }
}
void fix_ingred_service_2_1(){
fix_ingred_service_2_1_1();
}
void fix_ingred_service_2_2_1(){
uint16_t len;
    bzero(&len,sizeof(uint16_t));
    {uint32_t acc; acc = (uint32_t)(len); }
    {uint32_t op1; op1 = (uint32_t)(len); }
    {uint32_t op2; op2 = (uint32_t)(len); }
}
void fix_ingred_service_2_2(){
fix_ingred_service_2_2_1();
}
void fix_ingred_service_2_3_0(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {uint32_t acc; acc = (uint32_t)(ERRNO_INST_DECODE); }
    {uint32_t op1; op1 = (uint32_t)(ERRNO_INST_DECODE); }
    {uint32_t op2; op2 = (uint32_t)(ERRNO_INST_DECODE); }
}
void fix_ingred_service_2_3_7(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {uint32_t acc; acc = (uint32_t)(tlv1); }
    {uint32_t op1; op1 = (uint32_t)(tlv1); }
    {uint32_t op2; op2 = (uint32_t)(tlv1); }
}
void fix_ingred_service_2_3(){
fix_ingred_service_2_3_0();
fix_ingred_service_2_3_7();
}
void fix_ingred_service_2_6_0(){
uint32_t acc;
    bzero(&acc,sizeof(uint32_t));
    {int ret; ret = (int)(acc); }
    {uint32_t op1; op1 = (uint32_t)(acc); }
    {uint32_t op2; op2 = (uint32_t)(acc); }
    {int tlv1; tlv1 = (int)(acc); }
    {uint16_t tlv3; tlv3 = (uint16_t)(acc); }
}
void fix_ingred_service_2_6(){
fix_ingred_service_2_6_0();
}
void fix_ingred_service_2_7_0(){
    {int ret; ret = (int)(ERRNO_INVALID_OPCODE); }
    {uint32_t acc; acc = (uint32_t)(ERRNO_INVALID_OPCODE); }
    {uint32_t op1; op1 = (uint32_t)(ERRNO_INVALID_OPCODE); }
    {uint32_t op2; op2 = (uint32_t)(ERRNO_INVALID_OPCODE); }
    {int tlv1; tlv1 = (int)(ERRNO_INVALID_OPCODE); }
    {uint16_t tlv3; tlv3 = (uint16_t)(ERRNO_INVALID_OPCODE); }
}
void fix_ingred_service_2_7(){
fix_ingred_service_2_7_0();
}
void fix_ingred_service_2_15_0(){
inst_t inst;
    bzero(&inst,sizeof(inst_t));
uint32_t op1;
    bzero(&op1,sizeof(uint32_t));
    {int ret; ret = (int)(inst . op1); }
    {uint32_t acc; acc = (uint32_t)(inst . op1); }
    {uint32_t op2; op2 = (uint32_t)(inst . op1); }
    {int tlv1; tlv1 = (int)(inst . op1); }
    {uint16_t tlv3; tlv3 = (uint16_t)(inst . op1); }
}
void fix_ingred_service_2_15(){
fix_ingred_service_2_15_0();
}
void fix_ingred_service_2_17_0(){
inst_t inst;
    bzero(&inst,sizeof(inst_t));
uint32_t op2;
    bzero(&op2,sizeof(uint32_t));
    {int ret; ret = (int)(inst . op2); }
    {uint32_t acc; acc = (uint32_t)(inst . op2); }
    {uint32_t op1; op1 = (uint32_t)(inst . op2); }
    {int tlv1; tlv1 = (int)(inst . op2); }
    {uint16_t tlv3; tlv3 = (uint16_t)(inst . op2); }
}
void fix_ingred_service_2_17(){
fix_ingred_service_2_17_0();
}
void fix_ingred_service_2_23_0(){
uint32_t op2;
    bzero(&op2,sizeof(uint32_t));
    {int ret; ret = (int)(0xf000f000); }
    {uint32_t acc; acc = (uint32_t)(0xf000f000); }
    {uint32_t op1; op1 = (uint32_t)(0xf000f000); }
    {uint32_t op2; op2 = (uint32_t)(0xf000f000); }
    {int tlv1; tlv1 = (int)(0xf000f000); }
    {uint16_t tlv3; tlv3 = (uint16_t)(0xf000f000); }
}
void fix_ingred_service_2_23_8(){
uint32_t op2;
    bzero(&op2,sizeof(uint32_t));
    {int ret; ret = (int)(op2); }
    {uint32_t acc; acc = (uint32_t)(op2); }
    {uint32_t op1; op1 = (uint32_t)(op2); }
    {int tlv1; tlv1 = (int)(op2); }
    {uint16_t tlv3; tlv3 = (uint16_t)(op2); }
}
void fix_ingred_service_2_23(){
fix_ingred_service_2_23_0();
fix_ingred_service_2_23_8();
}
void fix_ingred_service_2(){
fix_ingred_service_2_0();
fix_ingred_service_2_1();
fix_ingred_service_2_2();
fix_ingred_service_2_3();
fix_ingred_service_2_6();
fix_ingred_service_2_7();
fix_ingred_service_2_15();
fix_ingred_service_2_17();
fix_ingred_service_2_23();
}
void fix_ingred_service_3_0_0(){
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(SUCCESS); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(SUCCESS); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(SUCCESS); }
    {int tlv2; tlv2 = (int)(SUCCESS); }
    {int tlv3; tlv3 = (int)(SUCCESS); }
    {int tlv4; tlv4 = (int)(SUCCESS); }
    {uint32_t out; out = (uint32_t)(SUCCESS); }
    {int tlv5; tlv5 = (int)(SUCCESS); }
    {int tlv6; tlv6 = (int)(SUCCESS); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(SUCCESS); }
    {int tlv8; tlv8 = (int)(SUCCESS); }
    {int tlv13; tlv13 = (int)(SUCCESS); }
    {void * tlv12; tlv12 = (void *)(SUCCESS); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(SUCCESS); }
    {int tlv17; tlv17 = (int)(SUCCESS); }
    {void * tlv16; tlv16 = (void *)(SUCCESS); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(SUCCESS); }
    {uint16_t tlv18; tlv18 = (uint16_t)(SUCCESS); }
    {uint16_t tlv22; tlv22 = (uint16_t)(SUCCESS); }
    {int tlv27; tlv27 = (int)(SUCCESS); }
    {void * tlv26; tlv26 = (void *)(SUCCESS); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(SUCCESS); }
    {void * tlv29; tlv29 = (void *)(SUCCESS); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(SUCCESS); }
}
void fix_ingred_service_3_0_1(){
    {int ret; ret = (int)(0); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(0); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {uint32_t out; out = (uint32_t)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {uint16_t tlv18; tlv18 = (uint16_t)(0); }
    {uint16_t tlv22; tlv22 = (uint16_t)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {void * tlv26; tlv26 = (void *)(0); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(0); }
    {void * tlv29; tlv29 = (void *)(0); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(0); }
}
void fix_ingred_service_3_0_4(){
    {int ret; ret = (int)(0); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(0); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(0); }
    {int tlv1; tlv1 = (int)(0); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(0); }
    {int tlv2; tlv2 = (int)(0); }
    {int tlv3; tlv3 = (int)(0); }
    {int tlv4; tlv4 = (int)(0); }
    {uint32_t out; out = (uint32_t)(0); }
    {int tlv5; tlv5 = (int)(0); }
    {int tlv6; tlv6 = (int)(0); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(0); }
    {int tlv8; tlv8 = (int)(0); }
    {int tlv13; tlv13 = (int)(0); }
    {void * tlv12; tlv12 = (void *)(0); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(0); }
    {int tlv17; tlv17 = (int)(0); }
    {void * tlv16; tlv16 = (void *)(0); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(0); }
    {uint16_t tlv18; tlv18 = (uint16_t)(0); }
    {uint16_t tlv22; tlv22 = (uint16_t)(0); }
    {int tlv27; tlv27 = (int)(0); }
    {void * tlv26; tlv26 = (void *)(0); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(0); }
    {void * tlv29; tlv29 = (void *)(0); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(0); }
}
void fix_ingred_service_3_0_7(){
    {int ret; ret = (int)(OUT_DEFAULT); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(OUT_DEFAULT); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(OUT_DEFAULT); }
    {int tlv1; tlv1 = (int)(OUT_DEFAULT); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(OUT_DEFAULT); }
    {int tlv2; tlv2 = (int)(OUT_DEFAULT); }
    {int tlv3; tlv3 = (int)(OUT_DEFAULT); }
    {int tlv4; tlv4 = (int)(OUT_DEFAULT); }
    {uint32_t out; out = (uint32_t)(OUT_DEFAULT); }
    {int tlv5; tlv5 = (int)(OUT_DEFAULT); }
    {int tlv6; tlv6 = (int)(OUT_DEFAULT); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(OUT_DEFAULT); }
    {int tlv8; tlv8 = (int)(OUT_DEFAULT); }
    {int tlv13; tlv13 = (int)(OUT_DEFAULT); }
    {void * tlv12; tlv12 = (void *)(OUT_DEFAULT); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(OUT_DEFAULT); }
    {int tlv17; tlv17 = (int)(OUT_DEFAULT); }
    {void * tlv16; tlv16 = (void *)(OUT_DEFAULT); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(OUT_DEFAULT); }
    {uint16_t tlv18; tlv18 = (uint16_t)(OUT_DEFAULT); }
    {uint16_t tlv22; tlv22 = (uint16_t)(OUT_DEFAULT); }
    {int tlv27; tlv27 = (int)(OUT_DEFAULT); }
    {void * tlv26; tlv26 = (void *)(OUT_DEFAULT); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(OUT_DEFAULT); }
    {void * tlv29; tlv29 = (void *)(OUT_DEFAULT); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(OUT_DEFAULT); }
}
void fix_ingred_service_3_0(){
fix_ingred_service_3_0_0();
fix_ingred_service_3_0_1();
fix_ingred_service_3_0_4();
fix_ingred_service_3_0_7();
}
void fix_ingred_service_3_1_0(){
    {int ret; ret = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv1; tlv1 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv2; tlv2 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv3; tlv3 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv4; tlv4 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {uint32_t out; out = (uint32_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv5; tlv5 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv6; tlv6 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv8; tlv8 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv13; tlv13 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {void * tlv12; tlv12 = (void *)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv17; tlv17 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {void * tlv16; tlv16 = (void *)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {uint16_t tlv18; tlv18 = (uint16_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {uint16_t tlv22; tlv22 = (uint16_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {int tlv27; tlv27 = (int)(SCRATCH_SZ + BYTECODE_SZ); }
    {void * tlv26; tlv26 = (void *)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
    {void * tlv29; tlv29 = (void *)(SCRATCH_SZ + BYTECODE_SZ); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(SCRATCH_SZ + BYTECODE_SZ); }
}
void fix_ingred_service_3_1_1(){
    {int ret; ret = (int)(FALSE); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(FALSE); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(FALSE); }
    {int tlv1; tlv1 = (int)(FALSE); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(FALSE); }
    {int tlv2; tlv2 = (int)(FALSE); }
    {int tlv3; tlv3 = (int)(FALSE); }
    {int tlv4; tlv4 = (int)(FALSE); }
    {uint32_t out; out = (uint32_t)(FALSE); }
    {int tlv5; tlv5 = (int)(FALSE); }
    {int tlv6; tlv6 = (int)(FALSE); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(FALSE); }
    {int tlv8; tlv8 = (int)(FALSE); }
    {int tlv13; tlv13 = (int)(FALSE); }
    {void * tlv12; tlv12 = (void *)(FALSE); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(FALSE); }
    {int tlv17; tlv17 = (int)(FALSE); }
    {void * tlv16; tlv16 = (void *)(FALSE); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(FALSE); }
    {uint16_t tlv18; tlv18 = (uint16_t)(FALSE); }
    {uint16_t tlv22; tlv22 = (uint16_t)(FALSE); }
    {int tlv27; tlv27 = (int)(FALSE); }
    {void * tlv26; tlv26 = (void *)(FALSE); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(FALSE); }
    {void * tlv29; tlv29 = (void *)(FALSE); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(FALSE); }
}
void fix_ingred_service_3_1(){
fix_ingred_service_3_1_0();
fix_ingred_service_3_1_1();
}
void fix_ingred_service_3_2_4(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(tlv1); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(tlv1); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {uint32_t out; out = (uint32_t)(tlv1); }
    {int tlv5; tlv5 = (int)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv1); }
    {int tlv8; tlv8 = (int)(tlv1); }
    {int tlv13; tlv13 = (int)(tlv1); }
    {void * tlv12; tlv12 = (void *)(tlv1); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
    {void * tlv16; tlv16 = (void *)(tlv1); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv1); }
    {uint16_t tlv18; tlv18 = (uint16_t)(tlv1); }
    {uint16_t tlv22; tlv22 = (uint16_t)(tlv1); }
    {int tlv27; tlv27 = (int)(tlv1); }
    {void * tlv26; tlv26 = (void *)(tlv1); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv1); }
    {void * tlv29; tlv29 = (void *)(tlv1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv1); }
}
void fix_ingred_service_3_2(){
fix_ingred_service_3_2_4();
}
void fix_ingred_service_3_3_0(){
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(STDIN); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(STDIN); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(STDIN); }
    {int tlv1; tlv1 = (int)(STDIN); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(STDIN); }
    {int tlv2; tlv2 = (int)(STDIN); }
    {int tlv3; tlv3 = (int)(STDIN); }
    {int tlv4; tlv4 = (int)(STDIN); }
    {uint32_t out; out = (uint32_t)(STDIN); }
    {int tlv5; tlv5 = (int)(STDIN); }
    {int tlv6; tlv6 = (int)(STDIN); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDIN); }
    {int tlv8; tlv8 = (int)(STDIN); }
    {int tlv13; tlv13 = (int)(STDIN); }
    {void * tlv12; tlv12 = (void *)(STDIN); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(STDIN); }
    {int tlv17; tlv17 = (int)(STDIN); }
    {void * tlv16; tlv16 = (void *)(STDIN); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(STDIN); }
    {uint16_t tlv18; tlv18 = (uint16_t)(STDIN); }
    {uint16_t tlv22; tlv22 = (uint16_t)(STDIN); }
    {int tlv27; tlv27 = (int)(STDIN); }
    {void * tlv26; tlv26 = (void *)(STDIN); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(STDIN); }
    {void * tlv29; tlv29 = (void *)(STDIN); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(STDIN); }
}
void fix_ingred_service_3_3_1(){
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(( void * ) & bytecode_len); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(( void * ) & bytecode_len); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(( void * ) & bytecode_len); }
    {int tlv1; tlv1 = (int)(( void * ) & bytecode_len); }
    {int tlv2; tlv2 = (int)(( void * ) & bytecode_len); }
    {int tlv3; tlv3 = (int)(( void * ) & bytecode_len); }
    {int tlv4; tlv4 = (int)(( void * ) & bytecode_len); }
    {uint32_t out; out = (uint32_t)(( void * ) & bytecode_len); }
    {int tlv5; tlv5 = (int)(( void * ) & bytecode_len); }
    {int tlv6; tlv6 = (int)(( void * ) & bytecode_len); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( void * ) & bytecode_len); }
    {int tlv8; tlv8 = (int)(( void * ) & bytecode_len); }
    {int tlv13; tlv13 = (int)(( void * ) & bytecode_len); }
    {void * tlv12; tlv12 = (void *)(( void * ) & bytecode_len); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(( void * ) & bytecode_len); }
    {int tlv17; tlv17 = (int)(( void * ) & bytecode_len); }
    {void * tlv16; tlv16 = (void *)(( void * ) & bytecode_len); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(( void * ) & bytecode_len); }
    {uint16_t tlv18; tlv18 = (uint16_t)(( void * ) & bytecode_len); }
    {uint16_t tlv22; tlv22 = (uint16_t)(( void * ) & bytecode_len); }
    {int tlv27; tlv27 = (int)(( void * ) & bytecode_len); }
    {void * tlv26; tlv26 = (void *)(( void * ) & bytecode_len); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(( void * ) & bytecode_len); }
    {void * tlv29; tlv29 = (void *)(( void * ) & bytecode_len); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(( void * ) & bytecode_len); }
}
void fix_ingred_service_3_3_2(){
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(sizeof ( bytecode_len )); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(sizeof ( bytecode_len )); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(sizeof ( bytecode_len )); }
    {int tlv1; tlv1 = (int)(sizeof ( bytecode_len )); }
    {int tlv2; tlv2 = (int)(sizeof ( bytecode_len )); }
    {int tlv3; tlv3 = (int)(sizeof ( bytecode_len )); }
    {int tlv4; tlv4 = (int)(sizeof ( bytecode_len )); }
    {uint32_t out; out = (uint32_t)(sizeof ( bytecode_len )); }
    {int tlv5; tlv5 = (int)(sizeof ( bytecode_len )); }
    {int tlv6; tlv6 = (int)(sizeof ( bytecode_len )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( bytecode_len )); }
    {int tlv8; tlv8 = (int)(sizeof ( bytecode_len )); }
    {int tlv13; tlv13 = (int)(sizeof ( bytecode_len )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( bytecode_len )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( bytecode_len )); }
    {int tlv17; tlv17 = (int)(sizeof ( bytecode_len )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( bytecode_len )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( bytecode_len )); }
    {uint16_t tlv18; tlv18 = (uint16_t)(sizeof ( bytecode_len )); }
    {uint16_t tlv22; tlv22 = (uint16_t)(sizeof ( bytecode_len )); }
    {int tlv27; tlv27 = (int)(sizeof ( bytecode_len )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( bytecode_len )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( bytecode_len )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( bytecode_len )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sizeof ( bytecode_len )); }
}
void fix_ingred_service_3_3(){
fix_ingred_service_3_3_0();
fix_ingred_service_3_3_1();
fix_ingred_service_3_3_2();
}
void fix_ingred_service_3_4_0(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int ret; ret = (int)(ERRNO_RECV); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(ERRNO_RECV); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(ERRNO_RECV); }
    {int tlv1; tlv1 = (int)(ERRNO_RECV); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(ERRNO_RECV); }
    {int tlv2; tlv2 = (int)(ERRNO_RECV); }
    {int tlv3; tlv3 = (int)(ERRNO_RECV); }
    {int tlv4; tlv4 = (int)(ERRNO_RECV); }
    {uint32_t out; out = (uint32_t)(ERRNO_RECV); }
    {int tlv5; tlv5 = (int)(ERRNO_RECV); }
    {int tlv6; tlv6 = (int)(ERRNO_RECV); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(ERRNO_RECV); }
    {int tlv8; tlv8 = (int)(ERRNO_RECV); }
    {int tlv13; tlv13 = (int)(ERRNO_RECV); }
    {void * tlv12; tlv12 = (void *)(ERRNO_RECV); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ERRNO_RECV); }
    {int tlv17; tlv17 = (int)(ERRNO_RECV); }
    {void * tlv16; tlv16 = (void *)(ERRNO_RECV); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ERRNO_RECV); }
    {uint16_t tlv18; tlv18 = (uint16_t)(ERRNO_RECV); }
    {uint16_t tlv22; tlv22 = (uint16_t)(ERRNO_RECV); }
    {int tlv27; tlv27 = (int)(ERRNO_RECV); }
    {void * tlv26; tlv26 = (void *)(ERRNO_RECV); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(ERRNO_RECV); }
    {void * tlv29; tlv29 = (void *)(ERRNO_RECV); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ERRNO_RECV); }
}
void fix_ingred_service_3_4_7(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {int ret; ret = (int)(tlv2); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(tlv2); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {uint32_t out; out = (uint32_t)(tlv2); }
    {int tlv5; tlv5 = (int)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv2); }
    {int tlv8; tlv8 = (int)(tlv2); }
    {int tlv13; tlv13 = (int)(tlv2); }
    {void * tlv12; tlv12 = (void *)(tlv2); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv2); }
    {int tlv17; tlv17 = (int)(tlv2); }
    {void * tlv16; tlv16 = (void *)(tlv2); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv2); }
    {uint16_t tlv18; tlv18 = (uint16_t)(tlv2); }
    {uint16_t tlv22; tlv22 = (uint16_t)(tlv2); }
    {int tlv27; tlv27 = (int)(tlv2); }
    {void * tlv26; tlv26 = (void *)(tlv2); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv2); }
    {void * tlv29; tlv29 = (void *)(tlv2); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv2); }
}
void fix_ingred_service_3_4(){
fix_ingred_service_3_4_0();
fix_ingred_service_3_4_7();
}
void fix_ingred_service_3_5_6(){
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv1; tlv1 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv2; tlv2 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv3; tlv3 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv4; tlv4 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {uint32_t out; out = (uint32_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv5; tlv5 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv6; tlv6 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv8; tlv8 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv13; tlv13 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {void * tlv12; tlv12 = (void *)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv17; tlv17 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {void * tlv16; tlv16 = (void *)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {uint16_t tlv18; tlv18 = (uint16_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {uint16_t tlv22; tlv22 = (uint16_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {int tlv27; tlv27 = (int)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {void * tlv26; tlv26 = (void *)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {void * tlv29; tlv29 = (void *)(BYTECODE_SZ - sizeof ( uint32_t )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(BYTECODE_SZ - sizeof ( uint32_t )); }
}
void fix_ingred_service_3_5_7(){
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(bytecode_len); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(bytecode_len); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(bytecode_len); }
    {int tlv1; tlv1 = (int)(bytecode_len); }
    {int tlv2; tlv2 = (int)(bytecode_len); }
    {int tlv3; tlv3 = (int)(bytecode_len); }
    {int tlv4; tlv4 = (int)(bytecode_len); }
    {uint32_t out; out = (uint32_t)(bytecode_len); }
    {int tlv5; tlv5 = (int)(bytecode_len); }
    {int tlv6; tlv6 = (int)(bytecode_len); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(bytecode_len); }
    {int tlv8; tlv8 = (int)(bytecode_len); }
    {int tlv13; tlv13 = (int)(bytecode_len); }
    {void * tlv12; tlv12 = (void *)(bytecode_len); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(bytecode_len); }
    {int tlv17; tlv17 = (int)(bytecode_len); }
    {void * tlv16; tlv16 = (void *)(bytecode_len); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(bytecode_len); }
    {uint16_t tlv18; tlv18 = (uint16_t)(bytecode_len); }
    {uint16_t tlv22; tlv22 = (uint16_t)(bytecode_len); }
    {int tlv27; tlv27 = (int)(bytecode_len); }
    {void * tlv26; tlv26 = (void *)(bytecode_len); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(bytecode_len); }
    {void * tlv29; tlv29 = (void *)(bytecode_len); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(bytecode_len); }
}
void fix_ingred_service_3_5(){
fix_ingred_service_3_5_6();
fix_ingred_service_3_5_7();
}
void fix_ingred_service_3_6_1(){
uint8_t space_ref;
    bzero(&space_ref,1*sizeof(uint8_t));
uint8_t * space = &space_ref;
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv1; tlv1 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv2; tlv2 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv3; tlv3 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv4; tlv4 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {uint32_t out; out = (uint32_t)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv5; tlv5 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv6; tlv6 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv8; tlv8 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv13; tlv13 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {void * tlv12; tlv12 = (void *)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv17; tlv17 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {void * tlv16; tlv16 = (void *)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
    {uint16_t tlv18; tlv18 = (uint16_t)(( void * ) ( space + SCRATCH_SZ )); }
    {uint16_t tlv22; tlv22 = (uint16_t)(( void * ) ( space + SCRATCH_SZ )); }
    {int tlv27; tlv27 = (int)(( void * ) ( space + SCRATCH_SZ )); }
    {void * tlv26; tlv26 = (void *)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
    {void * tlv29; tlv29 = (void *)(( void * ) ( space + SCRATCH_SZ )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(( void * ) ( space + SCRATCH_SZ )); }
}
void fix_ingred_service_3_6_2(){
uint8_t space_ref;
    bzero(&space_ref,1*sizeof(uint8_t));
uint8_t * space = &space_ref;
uint16_t bytecode_len;
    bzero(&bytecode_len,sizeof(uint16_t));
    {int ret; ret = (int)(bytecode_len); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(bytecode_len); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(bytecode_len); }
    {int tlv1; tlv1 = (int)(bytecode_len); }
    {int tlv2; tlv2 = (int)(bytecode_len); }
    {int tlv3; tlv3 = (int)(bytecode_len); }
    {int tlv4; tlv4 = (int)(bytecode_len); }
    {uint32_t out; out = (uint32_t)(bytecode_len); }
    {int tlv5; tlv5 = (int)(bytecode_len); }
    {int tlv6; tlv6 = (int)(bytecode_len); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(bytecode_len); }
    {int tlv8; tlv8 = (int)(bytecode_len); }
    {int tlv13; tlv13 = (int)(bytecode_len); }
    {void * tlv12; tlv12 = (void *)(bytecode_len); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(bytecode_len); }
    {int tlv17; tlv17 = (int)(bytecode_len); }
    {void * tlv16; tlv16 = (void *)(bytecode_len); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(bytecode_len); }
    {uint16_t tlv18; tlv18 = (uint16_t)(bytecode_len); }
    {uint16_t tlv22; tlv22 = (uint16_t)(bytecode_len); }
    {int tlv27; tlv27 = (int)(bytecode_len); }
    {void * tlv26; tlv26 = (void *)(bytecode_len); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(bytecode_len); }
    {void * tlv29; tlv29 = (void *)(bytecode_len); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(bytecode_len); }
}
void fix_ingred_service_3_6(){
fix_ingred_service_3_6_1();
fix_ingred_service_3_6_2();
}
void fix_ingred_service_3_7_8(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {int ret; ret = (int)(tlv3); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(tlv3); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {uint32_t out; out = (uint32_t)(tlv3); }
    {int tlv5; tlv5 = (int)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv3); }
    {int tlv8; tlv8 = (int)(tlv3); }
    {int tlv13; tlv13 = (int)(tlv3); }
    {void * tlv12; tlv12 = (void *)(tlv3); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv3); }
    {int tlv17; tlv17 = (int)(tlv3); }
    {void * tlv16; tlv16 = (void *)(tlv3); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv3); }
    {uint16_t tlv18; tlv18 = (uint16_t)(tlv3); }
    {uint16_t tlv22; tlv22 = (uint16_t)(tlv3); }
    {int tlv27; tlv27 = (int)(tlv3); }
    {void * tlv26; tlv26 = (void *)(tlv3); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv3); }
    {void * tlv29; tlv29 = (void *)(tlv3); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv3); }
}
void fix_ingred_service_3_7(){
fix_ingred_service_3_7_8();
}
void fix_ingred_service_3_9_7(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {int ret; ret = (int)(tlv4); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(tlv4); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {uint32_t out; out = (uint32_t)(tlv4); }
    {int tlv5; tlv5 = (int)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv4); }
    {int tlv8; tlv8 = (int)(tlv4); }
    {int tlv13; tlv13 = (int)(tlv4); }
    {void * tlv12; tlv12 = (void *)(tlv4); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv4); }
    {int tlv17; tlv17 = (int)(tlv4); }
    {void * tlv16; tlv16 = (void *)(tlv4); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv4); }
    {uint16_t tlv18; tlv18 = (uint16_t)(tlv4); }
    {uint16_t tlv22; tlv22 = (uint16_t)(tlv4); }
    {int tlv27; tlv27 = (int)(tlv4); }
    {void * tlv26; tlv26 = (void *)(tlv4); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv4); }
    {void * tlv29; tlv29 = (void *)(tlv4); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv4); }
}
void fix_ingred_service_3_9(){
fix_ingred_service_3_9_7();
}
void fix_ingred_service_3_11_8(){
int tlv5;
    bzero(&tlv5,sizeof(int));
    {int ret; ret = (int)(tlv5); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(tlv5); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(tlv5); }
    {int tlv1; tlv1 = (int)(tlv5); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(tlv5); }
    {int tlv2; tlv2 = (int)(tlv5); }
    {int tlv3; tlv3 = (int)(tlv5); }
    {int tlv4; tlv4 = (int)(tlv5); }
    {uint32_t out; out = (uint32_t)(tlv5); }
    {int tlv6; tlv6 = (int)(tlv5); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv5); }
    {int tlv8; tlv8 = (int)(tlv5); }
    {int tlv13; tlv13 = (int)(tlv5); }
    {void * tlv12; tlv12 = (void *)(tlv5); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv5); }
    {int tlv17; tlv17 = (int)(tlv5); }
    {void * tlv16; tlv16 = (void *)(tlv5); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv5); }
    {uint16_t tlv18; tlv18 = (uint16_t)(tlv5); }
    {uint16_t tlv22; tlv22 = (uint16_t)(tlv5); }
    {int tlv27; tlv27 = (int)(tlv5); }
    {void * tlv26; tlv26 = (void *)(tlv5); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv5); }
    {void * tlv29; tlv29 = (void *)(tlv5); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv5); }
}
void fix_ingred_service_3_11(){
fix_ingred_service_3_11_8();
}
void fix_ingred_service_3_12_0(){
uint32_t out;
    bzero(&out,sizeof(uint32_t));
    {int ret; ret = (int)(STDOUT); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(STDOUT); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(STDOUT); }
    {int tlv1; tlv1 = (int)(STDOUT); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(STDOUT); }
    {int tlv2; tlv2 = (int)(STDOUT); }
    {int tlv3; tlv3 = (int)(STDOUT); }
    {int tlv4; tlv4 = (int)(STDOUT); }
    {uint32_t out; out = (uint32_t)(STDOUT); }
    {int tlv5; tlv5 = (int)(STDOUT); }
    {int tlv6; tlv6 = (int)(STDOUT); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(STDOUT); }
    {int tlv8; tlv8 = (int)(STDOUT); }
    {int tlv13; tlv13 = (int)(STDOUT); }
    {void * tlv12; tlv12 = (void *)(STDOUT); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(STDOUT); }
    {int tlv17; tlv17 = (int)(STDOUT); }
    {void * tlv16; tlv16 = (void *)(STDOUT); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(STDOUT); }
    {uint16_t tlv18; tlv18 = (uint16_t)(STDOUT); }
    {uint16_t tlv22; tlv22 = (uint16_t)(STDOUT); }
    {int tlv27; tlv27 = (int)(STDOUT); }
    {void * tlv26; tlv26 = (void *)(STDOUT); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(STDOUT); }
    {void * tlv29; tlv29 = (void *)(STDOUT); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(STDOUT); }
}
void fix_ingred_service_3_12_1(){
uint32_t out;
    bzero(&out,sizeof(uint32_t));
    {int ret; ret = (int)(& out); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(& out); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(& out); }
    {int tlv1; tlv1 = (int)(& out); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(& out); }
    {int tlv2; tlv2 = (int)(& out); }
    {int tlv3; tlv3 = (int)(& out); }
    {int tlv4; tlv4 = (int)(& out); }
    {int tlv5; tlv5 = (int)(& out); }
    {int tlv6; tlv6 = (int)(& out); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(& out); }
    {int tlv8; tlv8 = (int)(& out); }
    {int tlv13; tlv13 = (int)(& out); }
    {void * tlv12; tlv12 = (void *)(& out); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(& out); }
    {int tlv17; tlv17 = (int)(& out); }
    {void * tlv16; tlv16 = (void *)(& out); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(& out); }
    {uint16_t tlv18; tlv18 = (uint16_t)(& out); }
    {uint16_t tlv22; tlv22 = (uint16_t)(& out); }
    {int tlv27; tlv27 = (int)(& out); }
    {void * tlv26; tlv26 = (void *)(& out); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(& out); }
    {void * tlv29; tlv29 = (void *)(& out); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(& out); }
}
void fix_ingred_service_3_12_2(){
uint32_t out;
    bzero(&out,sizeof(uint32_t));
    {int ret; ret = (int)(sizeof ( out )); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(sizeof ( out )); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(sizeof ( out )); }
    {int tlv1; tlv1 = (int)(sizeof ( out )); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(sizeof ( out )); }
    {int tlv2; tlv2 = (int)(sizeof ( out )); }
    {int tlv3; tlv3 = (int)(sizeof ( out )); }
    {int tlv4; tlv4 = (int)(sizeof ( out )); }
    {int tlv5; tlv5 = (int)(sizeof ( out )); }
    {int tlv6; tlv6 = (int)(sizeof ( out )); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(sizeof ( out )); }
    {int tlv8; tlv8 = (int)(sizeof ( out )); }
    {int tlv13; tlv13 = (int)(sizeof ( out )); }
    {void * tlv12; tlv12 = (void *)(sizeof ( out )); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(sizeof ( out )); }
    {int tlv17; tlv17 = (int)(sizeof ( out )); }
    {void * tlv16; tlv16 = (void *)(sizeof ( out )); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(sizeof ( out )); }
    {uint16_t tlv18; tlv18 = (uint16_t)(sizeof ( out )); }
    {uint16_t tlv22; tlv22 = (uint16_t)(sizeof ( out )); }
    {int tlv27; tlv27 = (int)(sizeof ( out )); }
    {void * tlv26; tlv26 = (void *)(sizeof ( out )); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(sizeof ( out )); }
    {void * tlv29; tlv29 = (void *)(sizeof ( out )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sizeof ( out )); }
}
void fix_ingred_service_3_12(){
fix_ingred_service_3_12_0();
fix_ingred_service_3_12_1();
fix_ingred_service_3_12_2();
}
void fix_ingred_service_3_13_0(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {int ret; ret = (int)(ERRNO_TRANSMIT); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(ERRNO_TRANSMIT); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(ERRNO_TRANSMIT); }
    {int tlv1; tlv1 = (int)(ERRNO_TRANSMIT); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(ERRNO_TRANSMIT); }
    {int tlv2; tlv2 = (int)(ERRNO_TRANSMIT); }
    {int tlv3; tlv3 = (int)(ERRNO_TRANSMIT); }
    {int tlv4; tlv4 = (int)(ERRNO_TRANSMIT); }
    {uint32_t out; out = (uint32_t)(ERRNO_TRANSMIT); }
    {int tlv5; tlv5 = (int)(ERRNO_TRANSMIT); }
    {int tlv6; tlv6 = (int)(ERRNO_TRANSMIT); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(ERRNO_TRANSMIT); }
    {int tlv8; tlv8 = (int)(ERRNO_TRANSMIT); }
    {int tlv13; tlv13 = (int)(ERRNO_TRANSMIT); }
    {void * tlv12; tlv12 = (void *)(ERRNO_TRANSMIT); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(ERRNO_TRANSMIT); }
    {int tlv17; tlv17 = (int)(ERRNO_TRANSMIT); }
    {void * tlv16; tlv16 = (void *)(ERRNO_TRANSMIT); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(ERRNO_TRANSMIT); }
    {uint16_t tlv18; tlv18 = (uint16_t)(ERRNO_TRANSMIT); }
    {uint16_t tlv22; tlv22 = (uint16_t)(ERRNO_TRANSMIT); }
    {int tlv27; tlv27 = (int)(ERRNO_TRANSMIT); }
    {void * tlv26; tlv26 = (void *)(ERRNO_TRANSMIT); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(ERRNO_TRANSMIT); }
    {void * tlv29; tlv29 = (void *)(ERRNO_TRANSMIT); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ERRNO_TRANSMIT); }
}
void fix_ingred_service_3_13_10(){
int tlv6;
    bzero(&tlv6,sizeof(int));
    {int ret; ret = (int)(tlv6); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(tlv6); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(tlv6); }
    {int tlv1; tlv1 = (int)(tlv6); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(tlv6); }
    {int tlv2; tlv2 = (int)(tlv6); }
    {int tlv3; tlv3 = (int)(tlv6); }
    {int tlv4; tlv4 = (int)(tlv6); }
    {uint32_t out; out = (uint32_t)(tlv6); }
    {int tlv5; tlv5 = (int)(tlv6); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tlv6); }
    {int tlv8; tlv8 = (int)(tlv6); }
    {int tlv13; tlv13 = (int)(tlv6); }
    {void * tlv12; tlv12 = (void *)(tlv6); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(tlv6); }
    {int tlv17; tlv17 = (int)(tlv6); }
    {void * tlv16; tlv16 = (void *)(tlv6); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(tlv6); }
    {uint16_t tlv18; tlv18 = (uint16_t)(tlv6); }
    {uint16_t tlv22; tlv22 = (uint16_t)(tlv6); }
    {int tlv27; tlv27 = (int)(tlv6); }
    {void * tlv26; tlv26 = (void *)(tlv6); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(tlv6); }
    {void * tlv29; tlv29 = (void *)(tlv6); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv6); }
}
void fix_ingred_service_3_13(){
fix_ingred_service_3_13_0();
fix_ingred_service_3_13_10();
}
void fix_ingred_service_3_15_0(){
uint8_t space_ref;
    bzero(&space_ref,1*sizeof(uint8_t));
uint8_t * space = &space_ref;
    {int ret; ret = (int)(space); }
    {cgc_size_t rx_bytes; rx_bytes = (cgc_size_t)(space); }
    {cgc_size_t tx_bytes; tx_bytes = (cgc_size_t)(space); }
    {int tlv1; tlv1 = (int)(space); }
    {uint16_t bytecode_len; bytecode_len = (uint16_t)(space); }
    {int tlv2; tlv2 = (int)(space); }
    {int tlv3; tlv3 = (int)(space); }
    {int tlv4; tlv4 = (int)(space); }
    {uint32_t out; out = (uint32_t)(space); }
    {int tlv5; tlv5 = (int)(space); }
    {int tlv6; tlv6 = (int)(space); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(space); }
    {int tlv8; tlv8 = (int)(space); }
    {int tlv13; tlv13 = (int)(space); }
    {void * tlv12; tlv12 = (void *)(space); }
    {cgc_size_t tlv11; tlv11 = (cgc_size_t)(space); }
    {int tlv17; tlv17 = (int)(space); }
    {void * tlv16; tlv16 = (void *)(space); }
    {cgc_size_t tlv15; tlv15 = (cgc_size_t)(space); }
    {uint16_t tlv18; tlv18 = (uint16_t)(space); }
    {uint16_t tlv22; tlv22 = (uint16_t)(space); }
    {int tlv27; tlv27 = (int)(space); }
    {void * tlv26; tlv26 = (void *)(space); }
    {cgc_size_t tlv25; tlv25 = (cgc_size_t)(space); }
    {void * tlv29; tlv29 = (void *)(space); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(space); }
}
void fix_ingred_service_3_15(){
fix_ingred_service_3_15_0();
}
void fix_ingred_service_3(){
fix_ingred_service_3_0();
fix_ingred_service_3_1();
fix_ingred_service_3_2();
fix_ingred_service_3_3();
fix_ingred_service_3_4();
fix_ingred_service_3_5();
fix_ingred_service_3_6();
fix_ingred_service_3_7();
fix_ingred_service_3_9();
fix_ingred_service_3_11();
fix_ingred_service_3_12();
fix_ingred_service_3_13();
fix_ingred_service_3_15();
}
