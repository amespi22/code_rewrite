

#include "cgc_packet.h"
#include "cgc_math_lib.h"
#include "cgc_game.h"
// reads user-sent string and saves it into a Packet struct
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

void fix_ingred_packet_0_0_0();
void fix_ingred_packet_0_0_1();
void fix_ingred_packet_0_0();
void fix_ingred_packet_0_1_1();
void fix_ingred_packet_0_1_2();
void fix_ingred_packet_0_1();
void fix_ingred_packet_0_2_0();
void fix_ingred_packet_0_2_1();
void fix_ingred_packet_0_2_2();
void fix_ingred_packet_0_2();
void fix_ingred_packet_0_3_2();
void fix_ingred_packet_0_3_3();
void fix_ingred_packet_0_3_5();
void fix_ingred_packet_0_3();
void fix_ingred_packet_0();
int cgc_populate_packet(Packet * pkt, char *data, int len)
{
if (fix_ingred_enable){ fix_ingred_packet_0(); };
    unsigned long tlv_size_0;
    tlv_size_0 = sizeof ( Packet );
    if (len != tlv_size_0) {
	cgc_printf("not proper packet length: got @d, should be @d\n", len, sizeof(Packet));
	return FAIL;
    }
    {
        void* tlv3;
        tlv3 = pkt;
        void* tlv2;
        tlv2 = data;
        cgc_size_t tlv1;
        tlv1 = len;
        cgc_memcpy(tlv3,tlv2,tlv1);
    }
    int content_len;
    content_len = pkt -> length - '0';
    if (content_len > MAX_CONTENT || content_len < 0) {
 {
     const char tlv4 [ ] = "length field outside valid range\n";
    	cgc_printf(tlv4);
 }
	return FAIL;
    }
    return SUCCESS;
}

// determine if this is a valid packet
void fix_ingred_packet_1_0_0();
void fix_ingred_packet_1_0_1();
void fix_ingred_packet_1_0();
void fix_ingred_packet_1_1_0();
void fix_ingred_packet_1_1();
void fix_ingred_packet_1_6_3();
void fix_ingred_packet_1_6_4();
void fix_ingred_packet_1_6_6();
void fix_ingred_packet_1_6();
void fix_ingred_packet_1();
int cgc_validate_packet(Packet * pkt)
{
if (fix_ingred_enable){ fix_ingred_packet_1(); };
    int ret;
    ret = SUCCESS;
    // check TYPE
    if (pkt->type < CONTROL && pkt->type > DATA) {
	cgc_printf("type is out of range (@c)\n", pkt->type);
	ret = FAIL;
    }
    // check SUBTYPE
    if (pkt->type != DATA) {
	if (pkt->subtype > NACK || pkt->subtype < ASSREQ) {
	    cgc_printf("subtype is out of range (@c)\n", pkt->subtype);
	    ret = FAIL;
	}
    } else {
	if (pkt->subtype > PLCPCE || pkt->subtype < DCDPCE) {
	    cgc_printf("data subtype is out of range (@c)\n", pkt->subtype);
	    ret = FAIL;
	}
    }
    int len;
    len = pkt -> length - '0';
    // validate length
    if (len > MAX_CONTENT || len < 0) {
	cgc_printf("length is out of range (@c)\n", pkt->length);
	ret = FAIL;
    }
    if (pkt->subtype != ASSREQ) {
	// verify connection number
	if ((pkt->conn_number - '0') != current_connection_number) {
	    cgc_printf("connection number not valid: @c vs @c\n", pkt->conn_number, current_connection_number + '0');
	    ret = FAIL;
	}
    }
    char checksum;
    {
        Packet* tlv1;
        tlv1 = pkt;
        checksum = cgc_get_checksum(tlv1);
    }
    if (pkt->checksum != checksum) {
	cgc_printf("checksum does not match @c vs @d", checksum, pkt->checksum);
	cgc_printf("@s\n", (char *) pkt);
	ret = FAIL;
    }
    return ret;
}

// given a packet, pkt, determine what will happen with the game
// handles control, management, and data packets
// if data, it will decrypt the packet and call game functions to handle user commands
// retuns TRUE if
// returns FALSE if 
 void fix_ingred_packet_2_8_0();
void fix_ingred_packet_2_8();
void fix_ingred_packet_2_17_4();
void fix_ingred_packet_2_17_5();
void fix_ingred_packet_2_17();
void fix_ingred_packet_2_25_4();
void fix_ingred_packet_2_25();
void fix_ingred_packet_2_33_0();
void fix_ingred_packet_2_33_1();
void fix_ingred_packet_2_33();
void fix_ingred_packet_2_38_4();
void fix_ingred_packet_2_38_5();
void fix_ingred_packet_2_38();
void fix_ingred_packet_2_39_9();
void fix_ingred_packet_2_39();
void fix_ingred_packet_2_40_0();
void fix_ingred_packet_2_40();
void fix_ingred_packet_2_41_0();
void fix_ingred_packet_2_41_1();
void fix_ingred_packet_2_41();
void fix_ingred_packet_2_43_1();
void fix_ingred_packet_2_43();
void fix_ingred_packet_2_45_9();
void fix_ingred_packet_2_45();
void fix_ingred_packet_2_46_0();
void fix_ingred_packet_2_46_1();
void fix_ingred_packet_2_46();
void fix_ingred_packet_2_47_1();
void fix_ingred_packet_2_47();
void fix_ingred_packet_2_49_1();
void fix_ingred_packet_2_49();
void fix_ingred_packet_2_50_1();
void fix_ingred_packet_2_50();
void fix_ingred_packet_2_52_1();
void fix_ingred_packet_2_52();
void fix_ingred_packet_2_53_0();
void fix_ingred_packet_2_53_1();
void fix_ingred_packet_2_53();
void fix_ingred_packet_2_54_1();
void fix_ingred_packet_2_54_2();
void fix_ingred_packet_2_54();
void fix_ingred_packet_2_59_1();
void fix_ingred_packet_2_59_2();
void fix_ingred_packet_2_59();
void fix_ingred_packet_2_62_2();
void fix_ingred_packet_2_62();
void fix_ingred_packet_2_66_2();
void fix_ingred_packet_2_66();
void fix_ingred_packet_2_67_1();
void fix_ingred_packet_2_67();
void fix_ingred_packet_2_69_6();
void fix_ingred_packet_2_69_7();
void fix_ingred_packet_2_69();
void fix_ingred_packet_2_71_6();
void fix_ingred_packet_2_71();
void fix_ingred_packet_2_72_1();
void fix_ingred_packet_2_72_3();
void fix_ingred_packet_2_72();
void fix_ingred_packet_2_73_8();
void fix_ingred_packet_2_73();
void fix_ingred_packet_2_74_0();
void fix_ingred_packet_2_74_2();
void fix_ingred_packet_2_74();
void fix_ingred_packet_2_75_1();
void fix_ingred_packet_2_75();
void fix_ingred_packet_2_78_1();
void fix_ingred_packet_2_78();
void fix_ingred_packet_2_85_7();
void fix_ingred_packet_2_85();
void fix_ingred_packet_2();
int cgc_packet_handler(Packet * pkt)	//, Game *game)
{
if (fix_ingred_enable){ fix_ingred_packet_2(); };
    if (pkt->type == MGMT) {
	if (pkt->subtype == ASSREQ) {
	    // verify requested connection number is next number
	    // if so, send response: association accepted
	    // if not, send response: no
     {
         char tlv5;
         tlv5 = pkt -> content [ 0 ] - '0';
    	    cgc_send_assoc_response(tlv5);
     }
	    return SUCCESS;
	} else {
	    if (pkt->subtype == ASSRESP) {
		// we should not receive this type of packet
		return FAIL;
	    } else {
		if (pkt->subtype == AUTHREQ) {
      {
          char* tlv9;
           tlv9 = pkt -> content;
    		    cgc_send_auth_response(tlv9);
      }
		    return SUCCESS;
		} else {
		    if (pkt->subtype == AUTHRESP) {
			// we should not receive this type of packet
			return FAIL;
		    } else {
			if (pkt->subtype == AUTHCHALRESP) {
       {
           char* tlv27;
            tlv27 = pkt -> content;
    			    cgc_handle_auth_challenge_resp(tlv27);
       }
			    return SUCCESS;
			} else {
			    if (pkt->subtype == DISREQ) {
    int tlv2;
    {
        char tlv69;
        tlv69 = pkt -> content [ 0 ];
        tlv2 = cgc_handle_disass_req(tlv69);
    }
				if (tlv2 == FAIL)	// disass reason
				{
        {
            const char tlv70 [ ] = "Failed disass\n";
    				    cgc_printf(tlv70);
        }
				    return 2;
;	// quit the program
				}
				return SUCCESS;
			    } else {
				if (pkt->subtype == DISRESP) {
				    // we should not receive this type of packet
        {
            const char tlv71 [ ] = "Dissasociation response received\n";
    				    cgc_printf(tlv71);
        }
				    return FAIL;
				} else {
				    if (pkt->subtype == DEAUTHREQ) {
     int tlv4;
     {
         char tlv79;
         tlv79 = pkt -> content [ 0 ];
         tlv4 = cgc_handle_deauth_req(tlv79);
     }
					if (tlv4 == FAIL)	// deauth reason
					{
         {
             const char tlv80 [ ] = "failed deauth...leaving\n";
    					    cgc_printf(tlv80);
         }
					    return 2;
;	// quit the program
					}
					return SUCCESS;
				    } else {
					if (pkt->subtype == DEAUTHRESP) {
					    // we should not receive this type of packet
         {
             const char tlv81 [ ] = "Dissasociation response received\n";
    					    cgc_printf(tlv81);
         }
					    return FAIL;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (pkt->type == DATA) {
	    Packet tmp_pkt;
	    if (pkt->packet_number - '0' != current_packet_count_recvd + 1) {
		cgc_printf("packet number incorrect: @c vs @c\n", pkt->packet_number, current_packet_count_recvd + 1 + '0');
  {
      char tlv7;
      tlv7 = pkt -> packet_number;
      int tlv6;
      tlv6 = ERR_OUT_OF_SEQUENCE;
    		cgc_send_nack(tlv7,tlv6);
  }
		return FAIL;
	    } else {
  {
      char tlv8;
      tlv8 = pkt -> packet_number;
    		cgc_send_ack(tlv8);
  }
		// handle game mechanics here
		if (pkt->subtype == NXTPCE) {
		    Piece piece;
		    // try to create a new piece
      int rtn;
      {
          Piece* tlv10;
          tlv10 = & piece;
          rtn = cgc_create_random_piece(tlv10);
      }
		    if (rtn != SUCCESS) {
			// nope, can't create a new piece
			if (rtn == 33) {
       char t[] = "nfull";
			    // stack is full. game over
			    tmp_pkt.type = DATA;
			    tmp_pkt.subtype = NXTPCE;
       {
           char* tlv30;
            tlv30 = tmp_pkt . content;
           const char* tlv29 = t;
           cgc_size_t tlv28;
           {
               char* tlv82;
                tlv82 = t;
               tlv28 = cgc_strlen(tlv82);
           }
    			    cgc_strncpy(tlv30,tlv29,tlv28);
       }
       {
           Packet* tlv32;
           tlv32 = & tmp_pkt;
           int tlv31;
           {
               char* tlv83;
                tlv83 = t;
               tlv31 = cgc_strlen(tlv83);
           }
    			    cgc_send_packet_new(tlv32,tlv31);
       }
			    return SUCCESS;
			} else {
			    if (rtn == 22) {
				// top piece already there. tell user there is already a piece to be used
				Packet tmp;
				tmp.type = DATA;
				tmp.subtype = NXTPCE;
    {
        char* tlv58;
         tlv58 = tmp . content;
        const char tlv57 [ ] = "nusetop";
        cgc_size_t tlv56;
        tlv56 = 7;
    				cgc_strncpy(tlv58,tlv57,tlv56);
    }
    {
        Packet* tlv60;
        tlv60 = & tmp;
        int tlv59;
        tlv59 = 7;
    				cgc_send_packet_new(tlv60,tlv59);
    }
				return SUCCESS;
			    } else {
				// not sure why it failed
				// print failure
				Packet tmp;
				tmp.type = DATA;
				tmp.subtype = NXTPCE;
    {
        char* tlv63;
         tlv63 = tmp . content;
        const char tlv62 [ ] = "nconfused";
        cgc_size_t tlv61;
        tlv61 = 9;
    				cgc_strncpy(tlv63,tlv62,tlv61);
    }
    {
        Packet* tlv65;
        tlv65 = & tmp;
        int tlv64;
        tlv64 = 9;
    				cgc_send_packet_new(tlv65,tlv64);
    }
				return SUCCESS;
			    }
			}
		    } else {
			// we just create a new piece. send it to the user
			char ss[9];
   {
       Piece* tlv12;
       tlv12 = & piece;
       char* tlv11;
        tlv11 = ss;
    			cgc_piece_to_pkt(tlv12,tlv11);
   }
;	// put piece info into packet format
			tmp_pkt.type = DATA;
			tmp_pkt.subtype = NXTPCE;
   {
       void* tlv15;
       tlv15 = tmp_pkt . content;
       void* tlv14;
       tlv14 = ss;
       cgc_size_t tlv13;
       tlv13 = 9;
    			cgc_memcpy(tlv15,tlv14,tlv13);
   }
			tmp_pkt.content[9] = '0';
   {
       char* tlv18;
        tlv18 = tmp_pkt . content;
       int tlv17;
       tlv17 = 10;
       int tlv16;
       tlv16 = current_encryption;
    			cgc_encrypt_data(tlv18,tlv17,tlv16);
   }
   {
       Packet* tlv20;
       tlv20 = & tmp_pkt;
       int tlv19;
       tlv19 = 9;
    			cgc_send_packet_new(tlv20,tlv19);
   }
			return SUCCESS;
		    }
		} else {
		    if (pkt->subtype == PLCPCE) {
			// check encryption is valid
			if (current_encryption == ENC_ONE) {
			    // verify that data is properly encrypted
       {
           char* tlv35;
            tlv35 = pkt -> content;
           int tlv34;
           tlv34 = pkt -> length - '0';
           int tlv33;
           tlv33 = ENC_ONE;
    			    cgc_decrypt_packet(tlv35,tlv34,tlv33);
       }
			} else {
			    if (current_encryption == ENC_TWO) {
				// saves the decrypted content overtop the pkt->content pointer (same length)
    {
        char* tlv68;
         tlv68 = pkt -> content;
        int tlv67;
        tlv67 = pkt -> length - '0';
        int tlv66;
        tlv66 = ENC_TWO;
    				cgc_decrypt_packet(tlv68,tlv67,tlv66);
    }
			    } else {
				// encryption is required
				return FAIL;
			    }
			}
			// if the road was placed on another road, update max length
			// the pkt->content will say which two pieces are to be connected
			// format: <pieceA #><sideA>:<pieceB #><sideB>
			if ((pkt->length - '0') != 5) {
			    return FAIL;
;	// wrong length for placing a piece
			}
			if (game_stack.top_element < 1) {
       char ss[] = "NO,PCE";
			    // error, must get another piece first
			    tmp_pkt.type = DATA;
			    tmp_pkt.subtype = PLCPCE;
       {
           void* tlv38;
           tlv38 = tmp_pkt . content;
           void* tlv37;
           tlv37 = ss;
           cgc_size_t tlv36;
           tlv36 = 6;
    			    cgc_memcpy(tlv38,tlv37,tlv36);
       }
       {
           Packet* tlv40;
           tlv40 = & tmp_pkt;
           int tlv39;
           tlv39 = 6;
    			    cgc_send_packet_new(tlv40,tlv39);
       }
			    return SUCCESS;
			}
   char sideA;
   sideA = pkt -> content [ 1 ];
			// pkt->content[2] is a colon
   char sideB;
   sideB = pkt -> content [ 4 ];
   int indexA;
   {
       char tlv21;
       tlv21 = pkt -> content [ 0 ] - '0';
       indexA = cgc_get_piece(tlv21);
   }
			if (indexA == -1) {
			    cgc_printf("Out of bounds piece requested A: @d vs @d...\n", pkt->content[0] - '0', game_stack.top_element);
			    return FAIL;
			}
   int indexB;
   {
       char tlv22;
       tlv22 = pkt -> content [ 3 ] - '0';
       indexB = cgc_get_piece(tlv22);
   }
			if (indexB == -1) {
			    cgc_printf("Out of bounds piece requested B: @d vs @d...\n", pkt->content[3] - '0', game_stack.top_element);
			    return FAIL;
			}
   int tlv1;
   {
       Piece* tlv26;
       tlv26 = & game_stack . stack [ indexA ];
       char tlv25;
       tlv25 = sideA - '0';
       Piece* tlv24;
       tlv24 = & game_stack . stack [ indexB ];
       char tlv23;
       tlv23 = sideB - '0';
       tlv1 = cgc_connect_pieces(tlv26,tlv25,tlv24,tlv23);
   }
			if (tlv1 == FAIL) {
			    // failed to connect pieces
       char ss[] = "NO,ERROR";
			    // user may have asked to connect two sides that don't both have roads
			    Packet tmp;
			    tmp.type = DATA;
			    tmp.subtype = PLCPCE;
       {
           void* tlv43;
           tlv43 = tmp . content;
           void* tlv42;
           tlv42 = ss;
           cgc_size_t tlv41;
           tlv41 = 8;
    			    cgc_memcpy(tlv43,tlv42,tlv41);
       }
       {
           Packet* tlv45;
           tlv45 = & tmp;
           int tlv44;
           tlv44 = 8;
    			    cgc_send_packet_new(tlv45,tlv44);
       }
			    return SUCCESS;
			} else {
			    // successful placement
			    tmp_pkt.type = DATA;
			    tmp_pkt.subtype = PLCPCE;
			    tmp_pkt.content[0] = '0' + cgc_current_max_road_len;
       {
           char* tlv48;
            tlv48 = tmp_pkt . content;
           int tlv47;
           tlv47 = 10;
           int tlv46;
           tlv46 = current_encryption;
    			    cgc_encrypt_data(tlv48,tlv47,tlv46);
       }
       {
           Packet* tlv50;
           tlv50 = & tmp_pkt;
           int tlv49;
           tlv49 = 1;
    			    cgc_send_packet_new(tlv50,tlv49);
       }
			    return SUCCESS;
			}
		    } else {
			if (pkt->subtype == GETLEN) {
			    tmp_pkt.type = DATA;
			    tmp_pkt.subtype = GETLEN;
			    tmp_pkt.content[0] = '0' + cgc_current_max_road_len;
       {
           char* tlv53;
            tlv53 = tmp_pkt . content;
           int tlv52;
           tlv52 = 10;
           int tlv51;
           tlv51 = current_encryption;
    			    cgc_encrypt_data(tlv53,tlv52,tlv51);
       }
       {
           Packet* tlv55;
           tlv55 = & tmp_pkt;
           int tlv54;
           tlv54 = 1;
    			    cgc_send_packet_new(tlv55,tlv54);
       }
			    return SUCCESS;
			} else {
			    if (pkt->subtype == DCDPCE) {
				// discard the top piece
    int tlv3;
    tlv3 = cgc_discard_piece ( );
				if (tlv3 == SUCCESS) {
				    tmp_pkt.type = DATA;
				    tmp_pkt.subtype = DCDPCE;
				    tmp_pkt.content[0] = 'y';
        {
            Packet* tlv73;
            tlv73 = & tmp_pkt;
            int tlv72;
            tlv72 = 1;
    				    cgc_send_packet_new(tlv73,tlv72);
        }
				    return SUCCESS;
				} else {
				    tmp_pkt.type = DATA;
				    tmp_pkt.subtype = DCDPCE;
        {
            char* tlv76;
             tlv76 = tmp_pkt . content;
            const char tlv75 [ ] = "nplaced";
            cgc_size_t tlv74;
            tlv74 = 7;
    				    cgc_strncpy(tlv76,tlv75,tlv74);
        }
        {
            Packet* tlv78;
            tlv78 = & tmp_pkt;
            int tlv77;
            tlv77 = 7;
    				    cgc_send_packet_new(tlv78,tlv77);
        }
				    return SUCCESS;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    return SUCCESS;
}

// send an ack for the pkt_num
// these are only for DATA packets
void fix_ingred_packet_3();
void cgc_send_ack(char pkt_num)
{
if (fix_ingred_enable){ fix_ingred_packet_3(); };
    Packet tmp;
    tmp.type = CONTROL;
    tmp.subtype = ACK;
    tmp.content[0] = pkt_num;

    current_packet_count_recvd++;
    {
        Packet* tlv2;
        tlv2 = & tmp;
        int tlv1;
        tlv1 = 1;
        cgc_send_packet_new(tlv2,tlv1);
    }
}

// send NACK for pkt_num packet
// attach reason to content
void fix_ingred_packet_4_1_1();
void fix_ingred_packet_4_1();
void fix_ingred_packet_4();
void cgc_send_nack(char pktnum, int reason)
{
if (fix_ingred_enable){ fix_ingred_packet_4(); };
    Packet tmp;
    tmp.type = CONTROL;
    tmp.subtype = NACK;
    tmp.content[0] = pktnum;
    tmp.content[1] = reason + '0';

    current_packet_count_recvd++;
    {
        Packet* tlv2;
        tlv2 = & tmp;
        int tlv1;
        tlv1 = 2;
        cgc_send_packet_new(tlv2,tlv1);
    }
}

// requested connection passed in as number
void fix_ingred_packet_5_1_6();
void fix_ingred_packet_5_1_7();
void fix_ingred_packet_5_1();
void fix_ingred_packet_5();
void cgc_send_assoc_response(char req_conn)
{
if (fix_ingred_enable){ fix_ingred_packet_5(); };
    if (req_conn == last_connection_number + 1) {
	// reset packet counts for this new connection
	last_connection_number += 1;
	current_packet_count_recvd = UNINITIALIZED;
	current_connection_number = req_conn;
	// successful association
	Packet tmp;
	tmp.type = MGMT;
	tmp.subtype = ASSRESP;
	tmp.content[0] = '1';

 {
     Packet* tlv2;
     tlv2 = & tmp;
     int tlv1;
     tlv1 = 1;
    	cgc_send_packet_new(tlv2,tlv1);
 }
 {
     const char tlv3 [ ] = "SUCCESSFUL association\n";
    	cgc_printf(tlv3);
 }
    } else {
	// unsuccessful association
	Packet tmp;
	tmp.type = MGMT;
	tmp.subtype = ASSRESP;
	tmp.content[0] = '0';

 {
     Packet* tlv5;
     tlv5 = & tmp;
     int tlv4;
     tlv4 = 1;
    	cgc_send_packet_new(tlv5,tlv4);
 }
    }
}

// send an authentication response
// pass in the authentication type requested
void fix_ingred_packet_6();
void cgc_send_auth_response(char *req_enc)
{
if (fix_ingred_enable){ fix_ingred_packet_6(); };
    // pick from valid authentication types
    if (req_enc[0] == 'a') {
	cgc_send_auth_challenge(ENC_ONE);
    } else {
	if (req_enc[0] == 'x') {
	    cgc_send_auth_challenge(ENC_TWO);
	} else {
	    // unsuccessful association
     {
         const char tlv1 [ ] = "AUTH RESP sent: fail\n";
    	    cgc_printf(tlv1);
     }
	    cgc_printf("requested: @s, next: @c\n", req_enc);
	}
    }
}

int offset = 3;
void fix_ingred_packet_7_1_1();
void fix_ingred_packet_7_1_2();
void fix_ingred_packet_7_1();
void fix_ingred_packet_7_2_0();
void fix_ingred_packet_7_2_1();
void fix_ingred_packet_7_2();
void fix_ingred_packet_7_3_0();
void fix_ingred_packet_7_3_1();
void fix_ingred_packet_7_3_2();
void fix_ingred_packet_7_3();
void fix_ingred_packet_7_5_0();
void fix_ingred_packet_7_5_2();
void fix_ingred_packet_7_5();
void fix_ingred_packet_7_6_0();
void fix_ingred_packet_7_6();
void fix_ingred_packet_7();
void cgc_send_auth_challenge(int enc)
{
if (fix_ingred_enable){ fix_ingred_packet_7(); };
    enc_chal.pending = TRUE;
    // Generate a random string to send the user
    char chall_val[5];
    for (int i = 0; i < 5; i++) {
 {
     uint32_t tlv13;
     tlv13 = 'a';
     uint32_t tlv12;
     tlv12 = 'p';
    	chall_val[i] = cgc_random_in_range(tlv13,tlv12);
 }
    }
    enc_chal.enc_type = enc;
    Packet tmp;
    tmp.type = MGMT;
    tmp.subtype = AUTHCHALREQ;
    {
        void* tlv3;
        tlv3 = tmp . content;
        void* tlv2;
        tlv2 = chall_val;
        cgc_size_t tlv1;
        tlv1 = 5;
        cgc_memcpy(tlv3,tlv2,tlv1);
    }

    {
        Packet* tlv5;
        tlv5 = & tmp;
        int tlv4;
        tlv4 = 5;
        cgc_send_packet_new(tlv5,tlv4);
    }
    {
        char* tlv8;
         tlv8 = chall_val;
        int tlv7;
        tlv7 = 5;
        int tlv6;
        tlv6 = enc;
        cgc_encrypt_data(tlv8,tlv7,tlv6);
    }
    {
        void* tlv11;
        tlv11 = enc_chal . answer;
        void* tlv10;
        tlv10 = chall_val;
        cgc_size_t tlv9;
        tlv9 = 5;
        cgc_memcpy(tlv11,tlv10,tlv9);
    }
}

void fix_ingred_packet_8_3_0();
void fix_ingred_packet_8_3();
void fix_ingred_packet_8_4_1();
void fix_ingred_packet_8_4_2();
void fix_ingred_packet_8_4();
void fix_ingred_packet_8_5_0();
void fix_ingred_packet_8_5_4();
void fix_ingred_packet_8_5();
void fix_ingred_packet_8_7_1();
void fix_ingred_packet_8_7();
void fix_ingred_packet_8();
int cgc_handle_auth_challenge_resp(char *answer)
{
if (fix_ingred_enable){ fix_ingred_packet_8(); };
    switch (enc_chal.enc_type) {
    case ENC_TWO:
	{ {
  char matches;
  matches = SUCCESS;
		for (int i = 0; i < 5; i++) {
		    if (answer[i] != enc_chal.answer[i]) {
			matches = FAIL;
		    }
		}
		if (matches) {
		    // user successfully answered the encryption challenge
		    enc_chal.pending = FALSE;
		    Packet tmp;
		    tmp.type = MGMT;
		    tmp.subtype = AUTHRESP;
		    tmp.content[0] = '1';
;	// good auth
      {
          Packet* tlv2;
          tlv2 = & tmp;
          int tlv1;
          tlv1 = 1;
    		    cgc_send_packet_new(tlv2,tlv1);
      }
		    current_encryption = ENC_TWO;
		    return TRUE;
		} else {
		    cgc_printf("failed to match (@s)", enc_chal.answer);
		    Packet tmp;
		    tmp.type = MGMT;
		    tmp.subtype = AUTHRESP;
		    tmp.content[0] = '0';
;	// Failed authentication
      {
          Packet* tlv4;
          tlv4 = & tmp;
          int tlv3;
          tlv3 = 1;
    		    cgc_send_packet_new(tlv4,tlv3);
      }
		}
		break;
	}
	}
    case ENC_ONE:
	{ {
  char matches;
  matches = SUCCESS;
		for (int i = 0; i < 5; i++) {
		    if (answer[i] != enc_chal.answer[i]) {
			matches = FAIL;
		    }
		}
		if (matches) {
		    // user successfully answered the encryption challenge
		    enc_chal.pending = FALSE;
		    Packet tmp;
		    tmp.type = MGMT;
		    tmp.subtype = AUTHRESP;
		    tmp.content[0] = '1';
;	// good auth
      {
          Packet* tlv6;
          tlv6 = & tmp;
          int tlv5;
          tlv5 = 1;
    		    cgc_send_packet_new(tlv6,tlv5);
      }
		    current_encryption = ENC_ONE;
		    return TRUE;
		} else {
		    cgc_printf("failed to match (@s)", enc_chal.answer);
		    Packet tmp;
		    tmp.type = MGMT;
		    tmp.subtype = AUTHRESP;
		    tmp.content[0] = '0';
;	// Failed authentication
      {
          Packet* tlv8;
          tlv8 = & tmp;
          int tlv7;
          tlv7 = 1;
    		    cgc_send_packet_new(tlv8,tlv7);
      }
		}
		break;
	}
	}
    default:
	{
	    return FALSE;
	}
    }
    return FALSE;
}

void fix_ingred_packet_9_3_3();
void fix_ingred_packet_9_3_4();
void fix_ingred_packet_9_3();
void fix_ingred_packet_9();
int cgc_handle_disass_req(char reason)
{
if (fix_ingred_enable){ fix_ingred_packet_9(); };
    //cgc_printf("@c @c", current_encryption, encryption_confirmed);
    // if the user hasn't deauthenticated, then this is out of order, stop everything
    if (current_encryption != UNINITIALIZED || encryption_confirmed != FALSE) {
 {
     const char tlv1 [ ] = "FAILED1\n";
    	cgc_printf(tlv1);
 }
	return FAIL;
    }
    // if reason is 'normal', just disass
    // if reason is anything else, stop program
    if (reason != GOOD_DISRESP) {
	Packet tmp;
	tmp.type = MGMT;
	tmp.subtype = DISRESP;
	tmp.content[0] = '0';
;	// Failed disassociation 
 {
     Packet* tlv3;
     tlv3 = & tmp;
     int tlv2;
     tlv2 = 1;
    	cgc_send_packet_new(tlv3,tlv2);
 }
	return FAIL;
;		// quit program
    } else {
	// just disassociate
	Packet tmp;
	tmp.type = MGMT;
	tmp.subtype = DISRESP;
	tmp.content[0] = '1';
;	// Successful disassociation 
 {
     Packet* tlv5;
     tlv5 = & tmp;
     int tlv4;
     tlv4 = 1;
    	cgc_send_packet_new(tlv5,tlv4);
 }
	current_packet_count_recvd = UNINITIALIZED;
	current_packet_count_sent = UNINITIALIZED;
	last_connection_number = current_connection_number;
	current_connection_number = UNINITIALIZED;
    }
    return SUCCESS;
}

// User requested deauthentication 
 void fix_ingred_packet_10_1_3();
void fix_ingred_packet_10_1_4();
void fix_ingred_packet_10_1();
void fix_ingred_packet_10();
int cgc_handle_deauth_req(char reason)
{
if (fix_ingred_enable){ fix_ingred_packet_10(); };
    // if reason is 'normal', just disass
    // if reason is anything else, stop program
    if (reason != GOOD_DEAUTHRESP) {
	// quit the program 
	Packet tmp;
	tmp.type = MGMT;
	tmp.subtype = DEAUTHRESP;
	tmp.content[0] = '0';
;	// Failed deauthentication
 {
     Packet* tlv2;
     tlv2 = & tmp;
     int tlv1;
     tlv1 = 1;
    	cgc_send_packet_new(tlv2,tlv1);
 }
	return FAIL;
;		// cgc_exit
    } else {
	// just deauth
	Packet tmp;
	tmp.type = MGMT;
	tmp.subtype = DEAUTHRESP;
	tmp.content[0] = '1';
;	// Successful deauthentication
 {
     Packet* tlv4;
     tlv4 = & tmp;
     int tlv3;
     tlv3 = 1;
    	cgc_send_packet_new(tlv4,tlv3);
 }
	current_encryption = UNINITIALIZED;
	encryption_confirmed = FALSE;
    }
    return SUCCESS;
}

// pkt is a pointer to a Packet struct containing the type/subtype for this packet
// len is the number of characters being used in the content field
void fix_ingred_packet_11_1_0();
void fix_ingred_packet_11_1_1();
void fix_ingred_packet_11_1();
void fix_ingred_packet_11();
void cgc_send_packet(Packet * pkt)
{
if (fix_ingred_enable){ fix_ingred_packet_11(); };
    {
        void* tlv2;
        tlv2 = ( char * ) pkt;
        cgc_size_t tlv1;
        tlv1 = sizeof ( Packet );
        cgc_write(tlv2,tlv1);
    }
    {
        const char tlv3 [ ] = "\n";
        cgc_printf(tlv3);
    }
}

// pkt is a pointer to a Packet struct containing the type/subtype for this packet
// len is the number of characters being used in the content field
void fix_ingred_packet_12();
void cgc_send_packet_new(Packet * pkt, int len)
{
if (fix_ingred_enable){ fix_ingred_packet_12(); };
    if (pkt->type == DATA)	// data 
    {
	pkt->packet_number = ++current_packet_count_sent + '0';
    } else {
	pkt->packet_number = '0';
    }
    pkt->conn_number = current_connection_number + '0';
    for (int i = len; i < MAX_CONTENT; i++) {
	pkt->content[i] = '0';
    }
    pkt->length = len + '0';
    cgc_set_checksum(pkt);
    {
        void* tlv2;
        tlv2 = ( char * ) pkt;
        cgc_size_t tlv1;
        tlv1 = sizeof ( Packet );
        cgc_write(tlv2,tlv1);
    }
    {
        const char tlv3 [ ] = "\n";
        cgc_printf(tlv3);
    }
}

void fix_ingred_packet_13_0_0();
void fix_ingred_packet_13_0();
void fix_ingred_packet_13_1_0();
void fix_ingred_packet_13_1_2();
void fix_ingred_packet_13_1_3();
void fix_ingred_packet_13_1();
void fix_ingred_packet_13();
char cgc_calculateCS(char *bytes, int len)
{
if (fix_ingred_enable){ fix_ingred_packet_13(); };
    char ret;
    ret = 0;
    for (int i = 0; i < len; i++) {
	ret ^= bytes[i];
    }
    return ret;
}

void fix_ingred_packet_14_1_0();
void fix_ingred_packet_14_1_1();
void fix_ingred_packet_14_1();
void fix_ingred_packet_14();
void cgc_set_checksum(Packet * pkt)
{
if (fix_ingred_enable){ fix_ingred_packet_14(); };
    {
        char* tlv2;
         tlv2 = ( char * ) pkt;
        int tlv1;
        tlv1 = sizeof ( Packet ) - 1;
        pkt->checksum = cgc_calculateCS(tlv2,tlv1);
    }
;	// don't count the checksum byte
}

void fix_ingred_packet_15();
char cgc_get_checksum(Packet * pkt)
{
if (fix_ingred_enable){ fix_ingred_packet_15(); };
    return cgc_calculateCS((char *) pkt, sizeof(Packet) - 1);
;	// don't count the checksum byte
}

char *VALID_CHARS = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz";
int LAST_CHAR_POS = 74;		// zero-based last char index
// return offset into VALID_CHARS for character C
// return -1 if not found
void fix_ingred_packet_16();
int cgc_locate_char(char c)
{
if (fix_ingred_enable){ fix_ingred_packet_16(); };
    for (int i = 0; i < LAST_CHAR_POS; i++) {
	if (VALID_CHARS[i] == c) {
	    return i;
	}
    }
    return -1;
}

// encrypt given characters
// return 0 if failure
// return 1 if success
void fix_ingred_packet_17_1_0();
void fix_ingred_packet_17_1_1();
void fix_ingred_packet_17_1_2();
void fix_ingred_packet_17_1();
void fix_ingred_packet_17_2_3();
void fix_ingred_packet_17_2_4();
void fix_ingred_packet_17_2();
void fix_ingred_packet_17_3_0();
void fix_ingred_packet_17_3();
void fix_ingred_packet_17_4_5();
void fix_ingred_packet_17_4_6();
void fix_ingred_packet_17_4();
void fix_ingred_packet_17_6_0();
void fix_ingred_packet_17_6();
void fix_ingred_packet_17_7_0();
void fix_ingred_packet_17_7_7();
void fix_ingred_packet_17_7_8();
void fix_ingred_packet_17_7();
void fix_ingred_packet_17_8_2();
void fix_ingred_packet_17_8();
void fix_ingred_packet_17();
int cgc_encrypt_data(char *data, int len, int type)
{
if (fix_ingred_enable){ fix_ingred_packet_17(); };
    if (type == ENC_TWO) {
 int i;
 i = 0;
	for (int i = 0; i < len; i++) {
     int char_index;
     {
         char tlv1;
         tlv1 = data [ i ];
         char_index = cgc_locate_char(tlv1);
     }
	    if (char_index == -1) {
		// out of bounds character found
		return 0;
	    }
	    if (i % 2 == 0) {
		// add the offset (wrap around)
  char x;
  x = VALID_CHARS [ ( char_index + offset ) % ( LAST_CHAR_POS ) ];
		data[i] = x;
	    } else {
		// subtract the offset (wrap around)
  signed char x;
  x = char_index - offset;
		if (x < 0) {
		    x = LAST_CHAR_POS - (offset - char_index);
		}
		data[i] = VALID_CHARS[x];
	    }
	}
    }
    if (type == ENC_ONE) {
 int i;
 i = 0;
	for (int i = 0; i < len; i++) {
     int char_index;
     {
         char tlv2;
         tlv2 = data [ i ];
         char_index = cgc_locate_char(tlv2);
     }
	    if (char_index == -1) {
		// out of bounds character found
		return 0;
	    }
	    if (i % 2 == 0) {
		// subtract the offset (wrap around)
  signed char x;
  x = char_index - offset;
		if (x < 0) {
		    x = LAST_CHAR_POS - (offset - char_index);
		}
		data[i] = VALID_CHARS[x];

	    } else {
		// add the offset (wrap around)
  char x;
  x = VALID_CHARS [ ( char_index + offset ) % ( LAST_CHAR_POS ) ];
		data[i] = x;
	    }
	}
    }
    return 1;
}

// this will decrypt the chars sent to it using XOR and save the result in the given packet
void fix_ingred_packet_18();
int cgc_decrypt_packet(char *data, int len, int type)
{
if (fix_ingred_enable){ fix_ingred_packet_18(); };
    if (type == ENC_TWO) {
 int i;
 i = 0;
	for (int i = 0; i < len; i++) {
     int char_index;
     {
         char tlv1;
         tlv1 = data [ i ];
         char_index = cgc_locate_char(tlv1);
     }
	    if (char_index == -1) {
		// out of bounds character found
		return 0;
	    }
	    if (i % 2 == 0) {
		// subtract the offset (wrap around)
  signed char x;
  x = char_index - offset;
		if (x < 0) {
		    x = LAST_CHAR_POS - (offset - char_index);
		}
		data[i] = VALID_CHARS[x];
	    } else {
		// add the offset (wrap around)
  char x;
  x = VALID_CHARS [ ( char_index + offset ) % ( LAST_CHAR_POS ) ];
		data[i] = x;
	    }
	}
    }
    if (type == ENC_ONE) {
 int i;
 i = 0;
	for (int i = 0; i < len; i++) {
     int char_index;
     {
         char tlv2;
         tlv2 = data [ i ];
         char_index = cgc_locate_char(tlv2);
     }
	    if (char_index == -1) {
		// out of bounds character found
		return 0;
	    }
	    if (i % 2 == 0) {
		// add the offset (wrap around)
  char x;
  x = VALID_CHARS [ ( char_index + offset ) % ( LAST_CHAR_POS ) ];
		data[i] = x;
	    } else {
		// subtract the offset (wrap around)
  signed char x;
  x = char_index - offset;
		if (x < 0) {
		    x = LAST_CHAR_POS - (offset - char_index);
		}
		data[i] = VALID_CHARS[x];
	    }
	}
    }
    return 1;
}

// return 1 if we won
// return 0 if we have not won yet
void fix_ingred_packet_19_1_1();
void fix_ingred_packet_19_1_2();
void fix_ingred_packet_19_1();
void fix_ingred_packet_19_3_0();
void fix_ingred_packet_19_3_1();
void fix_ingred_packet_19_3_2();
void fix_ingred_packet_19_3();
void fix_ingred_packet_19();
int cgc_check_win(int goal)
{
if (fix_ingred_enable){ fix_ingred_packet_19(); };
    char buff[5];
    int tlv1;
    tlv1 = cgc_get_max_road_len ( );
    if (tlv1 >= goal) {
 {
     const char tlv2 [ ] = "YOU WIN, what is your name?\n";
    	cgc_printf(tlv2);
 }
 int len;
 {
     char* tlv5;
      tlv5 = buff;
     char tlv4;
     tlv4 = '\n';
     cgc_size_t tlv3;
     tlv3 = 25;
     len = cgc_receive_until(tlv5,tlv4,tlv3);
 }
	buff[len] = 0x00;
	cgc_printf("Well done, @s\n", buff);
	return 1;
    }
    return 0;
}

void fix_ingred_packet_0_0_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(sizeof ( Packet )); }
    {int content_len; content_len = (int)(sizeof ( Packet )); }
    {void * tlv3; tlv3 = (void *)(sizeof ( Packet )); }
    {void * tlv2; tlv2 = (void *)(sizeof ( Packet )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Packet )); }
}
void fix_ingred_packet_0_0_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(pkt -> length - '0'); }
    {int content_len; content_len = (int)(pkt -> length - '0'); }
    {void * tlv3; tlv3 = (void *)(pkt -> length - '0'); }
    {void * tlv2; tlv2 = (void *)(pkt -> length - '0'); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(pkt -> length - '0'); }
}
void fix_ingred_packet_0_0(){
fix_ingred_packet_0_0_0();
fix_ingred_packet_0_0_1();
}
void fix_ingred_packet_0_1_1(){
int len;
    bzero(&len,sizeof(int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(len); }
    {int content_len; content_len = (int)(len); }
    {void * tlv3; tlv3 = (void *)(len); }
    {void * tlv2; tlv2 = (void *)(len); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(len); }
}
void fix_ingred_packet_0_1_2(){
int len;
    bzero(&len,sizeof(int));
unsigned long tlv_size_0;
    bzero(&tlv_size_0,sizeof(unsigned long));
    {int content_len; content_len = (int)(tlv_size_0); }
    {void * tlv3; tlv3 = (void *)(tlv_size_0); }
    {void * tlv2; tlv2 = (void *)(tlv_size_0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(tlv_size_0); }
}
void fix_ingred_packet_0_1(){
fix_ingred_packet_0_1_1();
fix_ingred_packet_0_1_2();
}
void fix_ingred_packet_0_2_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
int len;
    bzero(&len,sizeof(int));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(pkt); }
    {int content_len; content_len = (int)(pkt); }
    {void * tlv3; tlv3 = (void *)(pkt); }
    {void * tlv2; tlv2 = (void *)(pkt); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(pkt); }
}
void fix_ingred_packet_0_2_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
int len;
    bzero(&len,sizeof(int));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(data); }
    {int content_len; content_len = (int)(data); }
    {void * tlv3; tlv3 = (void *)(data); }
    {void * tlv2; tlv2 = (void *)(data); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(data); }
}
void fix_ingred_packet_0_2_2(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
int len;
    bzero(&len,sizeof(int));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(len); }
    {int content_len; content_len = (int)(len); }
    {void * tlv3; tlv3 = (void *)(len); }
    {void * tlv2; tlv2 = (void *)(len); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(len); }
}
void fix_ingred_packet_0_2(){
fix_ingred_packet_0_2_0();
fix_ingred_packet_0_2_1();
fix_ingred_packet_0_2_2();
}
void fix_ingred_packet_0_3_2(){
int content_len;
    bzero(&content_len,sizeof(int));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(content_len); }
    {void * tlv3; tlv3 = (void *)(content_len); }
    {void * tlv2; tlv2 = (void *)(content_len); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(content_len); }
}
void fix_ingred_packet_0_3_3(){
int content_len;
    bzero(&content_len,sizeof(int));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(MAX_CONTENT); }
    {int content_len; content_len = (int)(MAX_CONTENT); }
    {void * tlv3; tlv3 = (void *)(MAX_CONTENT); }
    {void * tlv2; tlv2 = (void *)(MAX_CONTENT); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(MAX_CONTENT); }
}
void fix_ingred_packet_0_3_5(){
int content_len;
    bzero(&content_len,sizeof(int));
    {unsigned long tlv_size_0; tlv_size_0 = (unsigned long)(0); }
    {int content_len; content_len = (int)(0); }
    {void * tlv3; tlv3 = (void *)(0); }
    {void * tlv2; tlv2 = (void *)(0); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(0); }
}
void fix_ingred_packet_0_3(){
fix_ingred_packet_0_3_2();
fix_ingred_packet_0_3_3();
fix_ingred_packet_0_3_5();
}
void fix_ingred_packet_0(){
fix_ingred_packet_0_0();
fix_ingred_packet_0_1();
fix_ingred_packet_0_2();
fix_ingred_packet_0_3();
}
void fix_ingred_packet_1_0_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {int ret; ret = (int)(SUCCESS); }
    {int len; len = (int)(SUCCESS); }
    {char checksum; checksum = (char)(SUCCESS); }
}
void fix_ingred_packet_1_0_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {int ret; ret = (int)(pkt -> length - '0'); }
    {int len; len = (int)(pkt -> length - '0'); }
    {char checksum; checksum = (char)(pkt -> length - '0'); }
}
void fix_ingred_packet_1_0(){
fix_ingred_packet_1_0_0();
fix_ingred_packet_1_0_1();
}
void fix_ingred_packet_1_1_0(){
    {int ret; ret = (int)(FAIL); }
    {int len; len = (int)(FAIL); }
    {char checksum; checksum = (char)(FAIL); }
}
void fix_ingred_packet_1_1(){
fix_ingred_packet_1_1_0();
}
void fix_ingred_packet_1_6_3(){
int len;
    bzero(&len,sizeof(int));
    {int ret; ret = (int)(len); }
    {char checksum; checksum = (char)(len); }
}
void fix_ingred_packet_1_6_4(){
int len;
    bzero(&len,sizeof(int));
    {int ret; ret = (int)(MAX_CONTENT); }
    {int len; len = (int)(MAX_CONTENT); }
    {char checksum; checksum = (char)(MAX_CONTENT); }
}
void fix_ingred_packet_1_6_6(){
int len;
    bzero(&len,sizeof(int));
    {int ret; ret = (int)(0); }
    {int len; len = (int)(0); }
    {char checksum; checksum = (char)(0); }
}
void fix_ingred_packet_1_6(){
fix_ingred_packet_1_6_3();
fix_ingred_packet_1_6_4();
fix_ingred_packet_1_6_6();
}
void fix_ingred_packet_1(){
fix_ingred_packet_1_0();
fix_ingred_packet_1_1();
fix_ingred_packet_1_6();
}
void fix_ingred_packet_2_8_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char tlv5; tlv5 = (char)(pkt -> content); }
    {char tlv7; tlv7 = (char)(pkt -> content); }
    {int tlv6; tlv6 = (int)(pkt -> content); }
    {char tlv8; tlv8 = (char)(pkt -> content); }
    {int rtn; rtn = (int)(pkt -> content); }
    {char * tlv9; tlv9 = (char *)(pkt -> content); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(pkt -> content); }
    {char sideA; sideA = (char)(pkt -> content); }
    {char sideB; sideB = (char)(pkt -> content); }
    {int indexA; indexA = (int)(pkt -> content); }
    {int indexB; indexB = (int)(pkt -> content); }
    {int tlv1; tlv1 = (int)(pkt -> content); }
    {char * tlv11; tlv11 = (char *)(pkt -> content); }
    {void * tlv15; tlv15 = (void *)(pkt -> content); }
    {void * tlv14; tlv14 = (void *)(pkt -> content); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(pkt -> content); }
    {char * tlv18; tlv18 = (char *)(pkt -> content); }
    {int tlv17; tlv17 = (int)(pkt -> content); }
    {int tlv16; tlv16 = (int)(pkt -> content); }
    {int tlv19; tlv19 = (int)(pkt -> content); }
    {char tlv21; tlv21 = (char)(pkt -> content); }
    {char tlv22; tlv22 = (char)(pkt -> content); }
    {char tlv25; tlv25 = (char)(pkt -> content); }
    {char tlv23; tlv23 = (char)(pkt -> content); }
    {char* t ; t  = (char*)(pkt -> content); }
    {char* ss ; ss  = (char*)(pkt -> content); }
    {char * tlv27; tlv27 = (char *)(pkt -> content); }
    {char * tlv30; tlv30 = (char *)(pkt -> content); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(pkt -> content); }
    {int tlv31; tlv31 = (int)(pkt -> content); }
    {char * tlv35; tlv35 = (char *)(pkt -> content); }
    {int tlv34; tlv34 = (int)(pkt -> content); }
    {int tlv33; tlv33 = (int)(pkt -> content); }
    {void * tlv38; tlv38 = (void *)(pkt -> content); }
    {void * tlv37; tlv37 = (void *)(pkt -> content); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(pkt -> content); }
    {int tlv39; tlv39 = (int)(pkt -> content); }
    {void * tlv43; tlv43 = (void *)(pkt -> content); }
    {void * tlv42; tlv42 = (void *)(pkt -> content); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(pkt -> content); }
    {int tlv44; tlv44 = (int)(pkt -> content); }
    {char * tlv48; tlv48 = (char *)(pkt -> content); }
    {int tlv47; tlv47 = (int)(pkt -> content); }
    {int tlv46; tlv46 = (int)(pkt -> content); }
    {int tlv49; tlv49 = (int)(pkt -> content); }
    {char * tlv53; tlv53 = (char *)(pkt -> content); }
    {int tlv52; tlv52 = (int)(pkt -> content); }
    {int tlv51; tlv51 = (int)(pkt -> content); }
    {int tlv54; tlv54 = (int)(pkt -> content); }
    {int tlv2; tlv2 = (int)(pkt -> content); }
    {int tlv3; tlv3 = (int)(pkt -> content); }
    {char * tlv82; tlv82 = (char *)(pkt -> content); }
    {char * tlv83; tlv83 = (char *)(pkt -> content); }
    {char tlv69; tlv69 = (char)(pkt -> content); }
    {char * tlv58; tlv58 = (char *)(pkt -> content); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(pkt -> content); }
    {int tlv59; tlv59 = (int)(pkt -> content); }
    {char * tlv63; tlv63 = (char *)(pkt -> content); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(pkt -> content); }
    {int tlv64; tlv64 = (int)(pkt -> content); }
    {char * tlv68; tlv68 = (char *)(pkt -> content); }
    {int tlv67; tlv67 = (int)(pkt -> content); }
    {int tlv66; tlv66 = (int)(pkt -> content); }
    {int tlv72; tlv72 = (int)(pkt -> content); }
    {char * tlv76; tlv76 = (char *)(pkt -> content); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(pkt -> content); }
    {int tlv77; tlv77 = (int)(pkt -> content); }
    {int tlv4; tlv4 = (int)(pkt -> content); }
    {char tlv79; tlv79 = (char)(pkt -> content); }
}
void fix_ingred_packet_2_8(){
fix_ingred_packet_2_8_0();
}
void fix_ingred_packet_2_17_4(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char tlv5; tlv5 = (char)(tlv2); }
    {char tlv7; tlv7 = (char)(tlv2); }
    {int tlv6; tlv6 = (int)(tlv2); }
    {char tlv8; tlv8 = (char)(tlv2); }
    {int rtn; rtn = (int)(tlv2); }
    {char * tlv9; tlv9 = (char *)(tlv2); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tlv2); }
    {char sideA; sideA = (char)(tlv2); }
    {char sideB; sideB = (char)(tlv2); }
    {int indexA; indexA = (int)(tlv2); }
    {int indexB; indexB = (int)(tlv2); }
    {int tlv1; tlv1 = (int)(tlv2); }
    {char * tlv11; tlv11 = (char *)(tlv2); }
    {void * tlv15; tlv15 = (void *)(tlv2); }
    {void * tlv14; tlv14 = (void *)(tlv2); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv2); }
    {char * tlv18; tlv18 = (char *)(tlv2); }
    {int tlv17; tlv17 = (int)(tlv2); }
    {int tlv16; tlv16 = (int)(tlv2); }
    {int tlv19; tlv19 = (int)(tlv2); }
    {char tlv21; tlv21 = (char)(tlv2); }
    {char tlv22; tlv22 = (char)(tlv2); }
    {char tlv25; tlv25 = (char)(tlv2); }
    {char tlv23; tlv23 = (char)(tlv2); }
    {char* t ; t  = (char*)(tlv2); }
    {char* ss ; ss  = (char*)(tlv2); }
    {char * tlv27; tlv27 = (char *)(tlv2); }
    {char * tlv30; tlv30 = (char *)(tlv2); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv2); }
    {int tlv31; tlv31 = (int)(tlv2); }
    {char * tlv35; tlv35 = (char *)(tlv2); }
    {int tlv34; tlv34 = (int)(tlv2); }
    {int tlv33; tlv33 = (int)(tlv2); }
    {void * tlv38; tlv38 = (void *)(tlv2); }
    {void * tlv37; tlv37 = (void *)(tlv2); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv2); }
    {int tlv39; tlv39 = (int)(tlv2); }
    {void * tlv43; tlv43 = (void *)(tlv2); }
    {void * tlv42; tlv42 = (void *)(tlv2); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tlv2); }
    {int tlv44; tlv44 = (int)(tlv2); }
    {char * tlv48; tlv48 = (char *)(tlv2); }
    {int tlv47; tlv47 = (int)(tlv2); }
    {int tlv46; tlv46 = (int)(tlv2); }
    {int tlv49; tlv49 = (int)(tlv2); }
    {char * tlv53; tlv53 = (char *)(tlv2); }
    {int tlv52; tlv52 = (int)(tlv2); }
    {int tlv51; tlv51 = (int)(tlv2); }
    {int tlv54; tlv54 = (int)(tlv2); }
    {int tlv3; tlv3 = (int)(tlv2); }
    {char * tlv82; tlv82 = (char *)(tlv2); }
    {char * tlv83; tlv83 = (char *)(tlv2); }
    {char tlv69; tlv69 = (char)(tlv2); }
    {char * tlv58; tlv58 = (char *)(tlv2); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv2); }
    {int tlv59; tlv59 = (int)(tlv2); }
    {char * tlv63; tlv63 = (char *)(tlv2); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv2); }
    {int tlv64; tlv64 = (int)(tlv2); }
    {char * tlv68; tlv68 = (char *)(tlv2); }
    {int tlv67; tlv67 = (int)(tlv2); }
    {int tlv66; tlv66 = (int)(tlv2); }
    {int tlv72; tlv72 = (int)(tlv2); }
    {char * tlv76; tlv76 = (char *)(tlv2); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv2); }
    {int tlv77; tlv77 = (int)(tlv2); }
    {int tlv4; tlv4 = (int)(tlv2); }
    {char tlv79; tlv79 = (char)(tlv2); }
}
void fix_ingred_packet_2_17_5(){
int tlv2;
    bzero(&tlv2,sizeof(int));
    {char tlv5; tlv5 = (char)(FAIL); }
    {char tlv7; tlv7 = (char)(FAIL); }
    {int tlv6; tlv6 = (int)(FAIL); }
    {char tlv8; tlv8 = (char)(FAIL); }
    {int rtn; rtn = (int)(FAIL); }
    {char * tlv9; tlv9 = (char *)(FAIL); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(FAIL); }
    {char sideA; sideA = (char)(FAIL); }
    {char sideB; sideB = (char)(FAIL); }
    {int indexA; indexA = (int)(FAIL); }
    {int indexB; indexB = (int)(FAIL); }
    {int tlv1; tlv1 = (int)(FAIL); }
    {char * tlv11; tlv11 = (char *)(FAIL); }
    {void * tlv15; tlv15 = (void *)(FAIL); }
    {void * tlv14; tlv14 = (void *)(FAIL); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(FAIL); }
    {char * tlv18; tlv18 = (char *)(FAIL); }
    {int tlv17; tlv17 = (int)(FAIL); }
    {int tlv16; tlv16 = (int)(FAIL); }
    {int tlv19; tlv19 = (int)(FAIL); }
    {char tlv21; tlv21 = (char)(FAIL); }
    {char tlv22; tlv22 = (char)(FAIL); }
    {char tlv25; tlv25 = (char)(FAIL); }
    {char tlv23; tlv23 = (char)(FAIL); }
    {char* t ; t  = (char*)(FAIL); }
    {char* ss ; ss  = (char*)(FAIL); }
    {char * tlv27; tlv27 = (char *)(FAIL); }
    {char * tlv30; tlv30 = (char *)(FAIL); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(FAIL); }
    {int tlv31; tlv31 = (int)(FAIL); }
    {char * tlv35; tlv35 = (char *)(FAIL); }
    {int tlv34; tlv34 = (int)(FAIL); }
    {int tlv33; tlv33 = (int)(FAIL); }
    {void * tlv38; tlv38 = (void *)(FAIL); }
    {void * tlv37; tlv37 = (void *)(FAIL); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(FAIL); }
    {int tlv39; tlv39 = (int)(FAIL); }
    {void * tlv43; tlv43 = (void *)(FAIL); }
    {void * tlv42; tlv42 = (void *)(FAIL); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(FAIL); }
    {int tlv44; tlv44 = (int)(FAIL); }
    {char * tlv48; tlv48 = (char *)(FAIL); }
    {int tlv47; tlv47 = (int)(FAIL); }
    {int tlv46; tlv46 = (int)(FAIL); }
    {int tlv49; tlv49 = (int)(FAIL); }
    {char * tlv53; tlv53 = (char *)(FAIL); }
    {int tlv52; tlv52 = (int)(FAIL); }
    {int tlv51; tlv51 = (int)(FAIL); }
    {int tlv54; tlv54 = (int)(FAIL); }
    {int tlv2; tlv2 = (int)(FAIL); }
    {int tlv3; tlv3 = (int)(FAIL); }
    {char * tlv82; tlv82 = (char *)(FAIL); }
    {char * tlv83; tlv83 = (char *)(FAIL); }
    {char tlv69; tlv69 = (char)(FAIL); }
    {char * tlv58; tlv58 = (char *)(FAIL); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(FAIL); }
    {int tlv59; tlv59 = (int)(FAIL); }
    {char * tlv63; tlv63 = (char *)(FAIL); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(FAIL); }
    {int tlv64; tlv64 = (int)(FAIL); }
    {char * tlv68; tlv68 = (char *)(FAIL); }
    {int tlv67; tlv67 = (int)(FAIL); }
    {int tlv66; tlv66 = (int)(FAIL); }
    {int tlv72; tlv72 = (int)(FAIL); }
    {char * tlv76; tlv76 = (char *)(FAIL); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(FAIL); }
    {int tlv77; tlv77 = (int)(FAIL); }
    {int tlv4; tlv4 = (int)(FAIL); }
    {char tlv79; tlv79 = (char)(FAIL); }
}
void fix_ingred_packet_2_17(){
fix_ingred_packet_2_17_4();
fix_ingred_packet_2_17_5();
}
void fix_ingred_packet_2_25_4(){
int tlv4;
    bzero(&tlv4,sizeof(int));
    {char tlv5; tlv5 = (char)(tlv4); }
    {char tlv7; tlv7 = (char)(tlv4); }
    {int tlv6; tlv6 = (int)(tlv4); }
    {char tlv8; tlv8 = (char)(tlv4); }
    {int rtn; rtn = (int)(tlv4); }
    {char * tlv9; tlv9 = (char *)(tlv4); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tlv4); }
    {char sideA; sideA = (char)(tlv4); }
    {char sideB; sideB = (char)(tlv4); }
    {int indexA; indexA = (int)(tlv4); }
    {int indexB; indexB = (int)(tlv4); }
    {int tlv1; tlv1 = (int)(tlv4); }
    {char * tlv11; tlv11 = (char *)(tlv4); }
    {void * tlv15; tlv15 = (void *)(tlv4); }
    {void * tlv14; tlv14 = (void *)(tlv4); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv4); }
    {char * tlv18; tlv18 = (char *)(tlv4); }
    {int tlv17; tlv17 = (int)(tlv4); }
    {int tlv16; tlv16 = (int)(tlv4); }
    {int tlv19; tlv19 = (int)(tlv4); }
    {char tlv21; tlv21 = (char)(tlv4); }
    {char tlv22; tlv22 = (char)(tlv4); }
    {char tlv25; tlv25 = (char)(tlv4); }
    {char tlv23; tlv23 = (char)(tlv4); }
    {char* t ; t  = (char*)(tlv4); }
    {char* ss ; ss  = (char*)(tlv4); }
    {char * tlv27; tlv27 = (char *)(tlv4); }
    {char * tlv30; tlv30 = (char *)(tlv4); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv4); }
    {int tlv31; tlv31 = (int)(tlv4); }
    {char * tlv35; tlv35 = (char *)(tlv4); }
    {int tlv34; tlv34 = (int)(tlv4); }
    {int tlv33; tlv33 = (int)(tlv4); }
    {void * tlv38; tlv38 = (void *)(tlv4); }
    {void * tlv37; tlv37 = (void *)(tlv4); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv4); }
    {int tlv39; tlv39 = (int)(tlv4); }
    {void * tlv43; tlv43 = (void *)(tlv4); }
    {void * tlv42; tlv42 = (void *)(tlv4); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tlv4); }
    {int tlv44; tlv44 = (int)(tlv4); }
    {char * tlv48; tlv48 = (char *)(tlv4); }
    {int tlv47; tlv47 = (int)(tlv4); }
    {int tlv46; tlv46 = (int)(tlv4); }
    {int tlv49; tlv49 = (int)(tlv4); }
    {char * tlv53; tlv53 = (char *)(tlv4); }
    {int tlv52; tlv52 = (int)(tlv4); }
    {int tlv51; tlv51 = (int)(tlv4); }
    {int tlv54; tlv54 = (int)(tlv4); }
    {int tlv2; tlv2 = (int)(tlv4); }
    {int tlv3; tlv3 = (int)(tlv4); }
    {char * tlv82; tlv82 = (char *)(tlv4); }
    {char * tlv83; tlv83 = (char *)(tlv4); }
    {char tlv69; tlv69 = (char)(tlv4); }
    {char * tlv58; tlv58 = (char *)(tlv4); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv4); }
    {int tlv59; tlv59 = (int)(tlv4); }
    {char * tlv63; tlv63 = (char *)(tlv4); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv4); }
    {int tlv64; tlv64 = (int)(tlv4); }
    {char * tlv68; tlv68 = (char *)(tlv4); }
    {int tlv67; tlv67 = (int)(tlv4); }
    {int tlv66; tlv66 = (int)(tlv4); }
    {int tlv72; tlv72 = (int)(tlv4); }
    {char * tlv76; tlv76 = (char *)(tlv4); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv4); }
    {int tlv77; tlv77 = (int)(tlv4); }
    {char tlv79; tlv79 = (char)(tlv4); }
}
void fix_ingred_packet_2_25(){
fix_ingred_packet_2_25_4();
}
void fix_ingred_packet_2_33_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char tlv5; tlv5 = (char)(pkt -> packet_number); }
    {char tlv7; tlv7 = (char)(pkt -> packet_number); }
    {int tlv6; tlv6 = (int)(pkt -> packet_number); }
    {char tlv8; tlv8 = (char)(pkt -> packet_number); }
    {int rtn; rtn = (int)(pkt -> packet_number); }
    {char * tlv9; tlv9 = (char *)(pkt -> packet_number); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(pkt -> packet_number); }
    {char sideA; sideA = (char)(pkt -> packet_number); }
    {char sideB; sideB = (char)(pkt -> packet_number); }
    {int indexA; indexA = (int)(pkt -> packet_number); }
    {int indexB; indexB = (int)(pkt -> packet_number); }
    {int tlv1; tlv1 = (int)(pkt -> packet_number); }
    {char * tlv11; tlv11 = (char *)(pkt -> packet_number); }
    {void * tlv15; tlv15 = (void *)(pkt -> packet_number); }
    {void * tlv14; tlv14 = (void *)(pkt -> packet_number); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(pkt -> packet_number); }
    {char * tlv18; tlv18 = (char *)(pkt -> packet_number); }
    {int tlv17; tlv17 = (int)(pkt -> packet_number); }
    {int tlv16; tlv16 = (int)(pkt -> packet_number); }
    {int tlv19; tlv19 = (int)(pkt -> packet_number); }
    {char tlv21; tlv21 = (char)(pkt -> packet_number); }
    {char tlv22; tlv22 = (char)(pkt -> packet_number); }
    {char tlv25; tlv25 = (char)(pkt -> packet_number); }
    {char tlv23; tlv23 = (char)(pkt -> packet_number); }
    {char* t ; t  = (char*)(pkt -> packet_number); }
    {char* ss ; ss  = (char*)(pkt -> packet_number); }
    {char * tlv27; tlv27 = (char *)(pkt -> packet_number); }
    {char * tlv30; tlv30 = (char *)(pkt -> packet_number); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(pkt -> packet_number); }
    {int tlv31; tlv31 = (int)(pkt -> packet_number); }
    {char * tlv35; tlv35 = (char *)(pkt -> packet_number); }
    {int tlv34; tlv34 = (int)(pkt -> packet_number); }
    {int tlv33; tlv33 = (int)(pkt -> packet_number); }
    {void * tlv38; tlv38 = (void *)(pkt -> packet_number); }
    {void * tlv37; tlv37 = (void *)(pkt -> packet_number); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(pkt -> packet_number); }
    {int tlv39; tlv39 = (int)(pkt -> packet_number); }
    {void * tlv43; tlv43 = (void *)(pkt -> packet_number); }
    {void * tlv42; tlv42 = (void *)(pkt -> packet_number); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(pkt -> packet_number); }
    {int tlv44; tlv44 = (int)(pkt -> packet_number); }
    {char * tlv48; tlv48 = (char *)(pkt -> packet_number); }
    {int tlv47; tlv47 = (int)(pkt -> packet_number); }
    {int tlv46; tlv46 = (int)(pkt -> packet_number); }
    {int tlv49; tlv49 = (int)(pkt -> packet_number); }
    {char * tlv53; tlv53 = (char *)(pkt -> packet_number); }
    {int tlv52; tlv52 = (int)(pkt -> packet_number); }
    {int tlv51; tlv51 = (int)(pkt -> packet_number); }
    {int tlv54; tlv54 = (int)(pkt -> packet_number); }
    {int tlv2; tlv2 = (int)(pkt -> packet_number); }
    {int tlv3; tlv3 = (int)(pkt -> packet_number); }
    {char * tlv82; tlv82 = (char *)(pkt -> packet_number); }
    {char * tlv83; tlv83 = (char *)(pkt -> packet_number); }
    {char tlv69; tlv69 = (char)(pkt -> packet_number); }
    {char * tlv58; tlv58 = (char *)(pkt -> packet_number); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(pkt -> packet_number); }
    {int tlv59; tlv59 = (int)(pkt -> packet_number); }
    {char * tlv63; tlv63 = (char *)(pkt -> packet_number); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(pkt -> packet_number); }
    {int tlv64; tlv64 = (int)(pkt -> packet_number); }
    {char * tlv68; tlv68 = (char *)(pkt -> packet_number); }
    {int tlv67; tlv67 = (int)(pkt -> packet_number); }
    {int tlv66; tlv66 = (int)(pkt -> packet_number); }
    {int tlv72; tlv72 = (int)(pkt -> packet_number); }
    {char * tlv76; tlv76 = (char *)(pkt -> packet_number); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(pkt -> packet_number); }
    {int tlv77; tlv77 = (int)(pkt -> packet_number); }
    {int tlv4; tlv4 = (int)(pkt -> packet_number); }
    {char tlv79; tlv79 = (char)(pkt -> packet_number); }
}
void fix_ingred_packet_2_33_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char tlv5; tlv5 = (char)(ERR_OUT_OF_SEQUENCE); }
    {char tlv7; tlv7 = (char)(ERR_OUT_OF_SEQUENCE); }
    {int tlv6; tlv6 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char tlv8; tlv8 = (char)(ERR_OUT_OF_SEQUENCE); }
    {int rtn; rtn = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv9; tlv9 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(ERR_OUT_OF_SEQUENCE); }
    {char sideA; sideA = (char)(ERR_OUT_OF_SEQUENCE); }
    {char sideB; sideB = (char)(ERR_OUT_OF_SEQUENCE); }
    {int indexA; indexA = (int)(ERR_OUT_OF_SEQUENCE); }
    {int indexB; indexB = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv1; tlv1 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv11; tlv11 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {void * tlv15; tlv15 = (void *)(ERR_OUT_OF_SEQUENCE); }
    {void * tlv14; tlv14 = (void *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv18; tlv18 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {int tlv17; tlv17 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv16; tlv16 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv19; tlv19 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char tlv21; tlv21 = (char)(ERR_OUT_OF_SEQUENCE); }
    {char tlv22; tlv22 = (char)(ERR_OUT_OF_SEQUENCE); }
    {char tlv25; tlv25 = (char)(ERR_OUT_OF_SEQUENCE); }
    {char tlv23; tlv23 = (char)(ERR_OUT_OF_SEQUENCE); }
    {char* t ; t  = (char*)(ERR_OUT_OF_SEQUENCE); }
    {char* ss ; ss  = (char*)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv27; tlv27 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv30; tlv30 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {int tlv31; tlv31 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv35; tlv35 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {int tlv34; tlv34 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv33; tlv33 = (int)(ERR_OUT_OF_SEQUENCE); }
    {void * tlv38; tlv38 = (void *)(ERR_OUT_OF_SEQUENCE); }
    {void * tlv37; tlv37 = (void *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {int tlv39; tlv39 = (int)(ERR_OUT_OF_SEQUENCE); }
    {void * tlv43; tlv43 = (void *)(ERR_OUT_OF_SEQUENCE); }
    {void * tlv42; tlv42 = (void *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {int tlv44; tlv44 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv48; tlv48 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {int tlv47; tlv47 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv46; tlv46 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv49; tlv49 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv53; tlv53 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {int tlv52; tlv52 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv51; tlv51 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv54; tlv54 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv2; tlv2 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv3; tlv3 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv82; tlv82 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv83; tlv83 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {char tlv69; tlv69 = (char)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv58; tlv58 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {int tlv59; tlv59 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv63; tlv63 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {int tlv64; tlv64 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv68; tlv68 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {int tlv67; tlv67 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv66; tlv66 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv72; tlv72 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char * tlv76; tlv76 = (char *)(ERR_OUT_OF_SEQUENCE); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(ERR_OUT_OF_SEQUENCE); }
    {int tlv77; tlv77 = (int)(ERR_OUT_OF_SEQUENCE); }
    {int tlv4; tlv4 = (int)(ERR_OUT_OF_SEQUENCE); }
    {char tlv79; tlv79 = (char)(ERR_OUT_OF_SEQUENCE); }
}
void fix_ingred_packet_2_33(){
fix_ingred_packet_2_33_0();
fix_ingred_packet_2_33_1();
}
void fix_ingred_packet_2_38_4(){
int rtn;
    bzero(&rtn,sizeof(int));
    {char tlv5; tlv5 = (char)(rtn); }
    {char tlv7; tlv7 = (char)(rtn); }
    {int tlv6; tlv6 = (int)(rtn); }
    {char tlv8; tlv8 = (char)(rtn); }
    {char * tlv9; tlv9 = (char *)(rtn); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(rtn); }
    {char sideA; sideA = (char)(rtn); }
    {char sideB; sideB = (char)(rtn); }
    {int indexA; indexA = (int)(rtn); }
    {int indexB; indexB = (int)(rtn); }
    {int tlv1; tlv1 = (int)(rtn); }
    {char * tlv11; tlv11 = (char *)(rtn); }
    {void * tlv15; tlv15 = (void *)(rtn); }
    {void * tlv14; tlv14 = (void *)(rtn); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(rtn); }
    {char * tlv18; tlv18 = (char *)(rtn); }
    {int tlv17; tlv17 = (int)(rtn); }
    {int tlv16; tlv16 = (int)(rtn); }
    {int tlv19; tlv19 = (int)(rtn); }
    {char tlv21; tlv21 = (char)(rtn); }
    {char tlv22; tlv22 = (char)(rtn); }
    {char tlv25; tlv25 = (char)(rtn); }
    {char tlv23; tlv23 = (char)(rtn); }
    {char* t ; t  = (char*)(rtn); }
    {char* ss ; ss  = (char*)(rtn); }
    {char * tlv27; tlv27 = (char *)(rtn); }
    {char * tlv30; tlv30 = (char *)(rtn); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(rtn); }
    {int tlv31; tlv31 = (int)(rtn); }
    {char * tlv35; tlv35 = (char *)(rtn); }
    {int tlv34; tlv34 = (int)(rtn); }
    {int tlv33; tlv33 = (int)(rtn); }
    {void * tlv38; tlv38 = (void *)(rtn); }
    {void * tlv37; tlv37 = (void *)(rtn); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(rtn); }
    {int tlv39; tlv39 = (int)(rtn); }
    {void * tlv43; tlv43 = (void *)(rtn); }
    {void * tlv42; tlv42 = (void *)(rtn); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(rtn); }
    {int tlv44; tlv44 = (int)(rtn); }
    {char * tlv48; tlv48 = (char *)(rtn); }
    {int tlv47; tlv47 = (int)(rtn); }
    {int tlv46; tlv46 = (int)(rtn); }
    {int tlv49; tlv49 = (int)(rtn); }
    {char * tlv53; tlv53 = (char *)(rtn); }
    {int tlv52; tlv52 = (int)(rtn); }
    {int tlv51; tlv51 = (int)(rtn); }
    {int tlv54; tlv54 = (int)(rtn); }
    {int tlv2; tlv2 = (int)(rtn); }
    {int tlv3; tlv3 = (int)(rtn); }
    {char * tlv82; tlv82 = (char *)(rtn); }
    {char * tlv83; tlv83 = (char *)(rtn); }
    {char tlv69; tlv69 = (char)(rtn); }
    {char * tlv58; tlv58 = (char *)(rtn); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(rtn); }
    {int tlv59; tlv59 = (int)(rtn); }
    {char * tlv63; tlv63 = (char *)(rtn); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(rtn); }
    {int tlv64; tlv64 = (int)(rtn); }
    {char * tlv68; tlv68 = (char *)(rtn); }
    {int tlv67; tlv67 = (int)(rtn); }
    {int tlv66; tlv66 = (int)(rtn); }
    {int tlv72; tlv72 = (int)(rtn); }
    {char * tlv76; tlv76 = (char *)(rtn); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(rtn); }
    {int tlv77; tlv77 = (int)(rtn); }
    {int tlv4; tlv4 = (int)(rtn); }
    {char tlv79; tlv79 = (char)(rtn); }
}
void fix_ingred_packet_2_38_5(){
int rtn;
    bzero(&rtn,sizeof(int));
    {char tlv5; tlv5 = (char)(SUCCESS); }
    {char tlv7; tlv7 = (char)(SUCCESS); }
    {int tlv6; tlv6 = (int)(SUCCESS); }
    {char tlv8; tlv8 = (char)(SUCCESS); }
    {int rtn; rtn = (int)(SUCCESS); }
    {char * tlv9; tlv9 = (char *)(SUCCESS); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(SUCCESS); }
    {char sideA; sideA = (char)(SUCCESS); }
    {char sideB; sideB = (char)(SUCCESS); }
    {int indexA; indexA = (int)(SUCCESS); }
    {int indexB; indexB = (int)(SUCCESS); }
    {int tlv1; tlv1 = (int)(SUCCESS); }
    {char * tlv11; tlv11 = (char *)(SUCCESS); }
    {void * tlv15; tlv15 = (void *)(SUCCESS); }
    {void * tlv14; tlv14 = (void *)(SUCCESS); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(SUCCESS); }
    {char * tlv18; tlv18 = (char *)(SUCCESS); }
    {int tlv17; tlv17 = (int)(SUCCESS); }
    {int tlv16; tlv16 = (int)(SUCCESS); }
    {int tlv19; tlv19 = (int)(SUCCESS); }
    {char tlv21; tlv21 = (char)(SUCCESS); }
    {char tlv22; tlv22 = (char)(SUCCESS); }
    {char tlv25; tlv25 = (char)(SUCCESS); }
    {char tlv23; tlv23 = (char)(SUCCESS); }
    {char* t ; t  = (char*)(SUCCESS); }
    {char* ss ; ss  = (char*)(SUCCESS); }
    {char * tlv27; tlv27 = (char *)(SUCCESS); }
    {char * tlv30; tlv30 = (char *)(SUCCESS); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(SUCCESS); }
    {int tlv31; tlv31 = (int)(SUCCESS); }
    {char * tlv35; tlv35 = (char *)(SUCCESS); }
    {int tlv34; tlv34 = (int)(SUCCESS); }
    {int tlv33; tlv33 = (int)(SUCCESS); }
    {void * tlv38; tlv38 = (void *)(SUCCESS); }
    {void * tlv37; tlv37 = (void *)(SUCCESS); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(SUCCESS); }
    {int tlv39; tlv39 = (int)(SUCCESS); }
    {void * tlv43; tlv43 = (void *)(SUCCESS); }
    {void * tlv42; tlv42 = (void *)(SUCCESS); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(SUCCESS); }
    {int tlv44; tlv44 = (int)(SUCCESS); }
    {char * tlv48; tlv48 = (char *)(SUCCESS); }
    {int tlv47; tlv47 = (int)(SUCCESS); }
    {int tlv46; tlv46 = (int)(SUCCESS); }
    {int tlv49; tlv49 = (int)(SUCCESS); }
    {char * tlv53; tlv53 = (char *)(SUCCESS); }
    {int tlv52; tlv52 = (int)(SUCCESS); }
    {int tlv51; tlv51 = (int)(SUCCESS); }
    {int tlv54; tlv54 = (int)(SUCCESS); }
    {int tlv2; tlv2 = (int)(SUCCESS); }
    {int tlv3; tlv3 = (int)(SUCCESS); }
    {char * tlv82; tlv82 = (char *)(SUCCESS); }
    {char * tlv83; tlv83 = (char *)(SUCCESS); }
    {char tlv69; tlv69 = (char)(SUCCESS); }
    {char * tlv58; tlv58 = (char *)(SUCCESS); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(SUCCESS); }
    {int tlv59; tlv59 = (int)(SUCCESS); }
    {char * tlv63; tlv63 = (char *)(SUCCESS); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(SUCCESS); }
    {int tlv64; tlv64 = (int)(SUCCESS); }
    {char * tlv68; tlv68 = (char *)(SUCCESS); }
    {int tlv67; tlv67 = (int)(SUCCESS); }
    {int tlv66; tlv66 = (int)(SUCCESS); }
    {int tlv72; tlv72 = (int)(SUCCESS); }
    {char * tlv76; tlv76 = (char *)(SUCCESS); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(SUCCESS); }
    {int tlv77; tlv77 = (int)(SUCCESS); }
    {int tlv4; tlv4 = (int)(SUCCESS); }
    {char tlv79; tlv79 = (char)(SUCCESS); }
}
void fix_ingred_packet_2_38(){
fix_ingred_packet_2_38_4();
fix_ingred_packet_2_38_5();
}
void fix_ingred_packet_2_39_9(){
    {char tlv5; tlv5 = (char)(33); }
    {char tlv7; tlv7 = (char)(33); }
    {int tlv6; tlv6 = (int)(33); }
    {char tlv8; tlv8 = (char)(33); }
    {int rtn; rtn = (int)(33); }
    {char * tlv9; tlv9 = (char *)(33); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(33); }
    {char sideA; sideA = (char)(33); }
    {char sideB; sideB = (char)(33); }
    {int indexA; indexA = (int)(33); }
    {int indexB; indexB = (int)(33); }
    {int tlv1; tlv1 = (int)(33); }
    {char * tlv11; tlv11 = (char *)(33); }
    {void * tlv15; tlv15 = (void *)(33); }
    {void * tlv14; tlv14 = (void *)(33); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(33); }
    {char * tlv18; tlv18 = (char *)(33); }
    {int tlv17; tlv17 = (int)(33); }
    {int tlv16; tlv16 = (int)(33); }
    {int tlv19; tlv19 = (int)(33); }
    {char tlv21; tlv21 = (char)(33); }
    {char tlv22; tlv22 = (char)(33); }
    {char tlv25; tlv25 = (char)(33); }
    {char tlv23; tlv23 = (char)(33); }
    {char* t ; t  = (char*)(33); }
    {char* ss ; ss  = (char*)(33); }
    {char * tlv27; tlv27 = (char *)(33); }
    {char * tlv30; tlv30 = (char *)(33); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(33); }
    {int tlv31; tlv31 = (int)(33); }
    {char * tlv35; tlv35 = (char *)(33); }
    {int tlv34; tlv34 = (int)(33); }
    {int tlv33; tlv33 = (int)(33); }
    {void * tlv38; tlv38 = (void *)(33); }
    {void * tlv37; tlv37 = (void *)(33); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(33); }
    {int tlv39; tlv39 = (int)(33); }
    {void * tlv43; tlv43 = (void *)(33); }
    {void * tlv42; tlv42 = (void *)(33); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(33); }
    {int tlv44; tlv44 = (int)(33); }
    {char * tlv48; tlv48 = (char *)(33); }
    {int tlv47; tlv47 = (int)(33); }
    {int tlv46; tlv46 = (int)(33); }
    {int tlv49; tlv49 = (int)(33); }
    {char * tlv53; tlv53 = (char *)(33); }
    {int tlv52; tlv52 = (int)(33); }
    {int tlv51; tlv51 = (int)(33); }
    {int tlv54; tlv54 = (int)(33); }
    {int tlv2; tlv2 = (int)(33); }
    {int tlv3; tlv3 = (int)(33); }
    {char * tlv82; tlv82 = (char *)(33); }
    {char * tlv83; tlv83 = (char *)(33); }
    {char tlv69; tlv69 = (char)(33); }
    {char * tlv58; tlv58 = (char *)(33); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(33); }
    {int tlv59; tlv59 = (int)(33); }
    {char * tlv63; tlv63 = (char *)(33); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(33); }
    {int tlv64; tlv64 = (int)(33); }
    {char * tlv68; tlv68 = (char *)(33); }
    {int tlv67; tlv67 = (int)(33); }
    {int tlv66; tlv66 = (int)(33); }
    {int tlv72; tlv72 = (int)(33); }
    {char * tlv76; tlv76 = (char *)(33); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(33); }
    {int tlv77; tlv77 = (int)(33); }
    {int tlv4; tlv4 = (int)(33); }
    {char tlv79; tlv79 = (char)(33); }
}
void fix_ingred_packet_2_39(){
fix_ingred_packet_2_39_9();
}
void fix_ingred_packet_2_40_0(){
Packet tmp_pkt;
    bzero(&tmp_pkt,sizeof(Packet));
    {char tlv5; tlv5 = (char)(tmp_pkt . content); }
    {char tlv7; tlv7 = (char)(tmp_pkt . content); }
    {int tlv6; tlv6 = (int)(tmp_pkt . content); }
    {char tlv8; tlv8 = (char)(tmp_pkt . content); }
    {int rtn; rtn = (int)(tmp_pkt . content); }
    {char * tlv9; tlv9 = (char *)(tmp_pkt . content); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tmp_pkt . content); }
    {char sideA; sideA = (char)(tmp_pkt . content); }
    {char sideB; sideB = (char)(tmp_pkt . content); }
    {int indexA; indexA = (int)(tmp_pkt . content); }
    {int indexB; indexB = (int)(tmp_pkt . content); }
    {int tlv1; tlv1 = (int)(tmp_pkt . content); }
    {char * tlv11; tlv11 = (char *)(tmp_pkt . content); }
    {void * tlv15; tlv15 = (void *)(tmp_pkt . content); }
    {void * tlv14; tlv14 = (void *)(tmp_pkt . content); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tmp_pkt . content); }
    {char * tlv18; tlv18 = (char *)(tmp_pkt . content); }
    {int tlv17; tlv17 = (int)(tmp_pkt . content); }
    {int tlv16; tlv16 = (int)(tmp_pkt . content); }
    {int tlv19; tlv19 = (int)(tmp_pkt . content); }
    {char tlv21; tlv21 = (char)(tmp_pkt . content); }
    {char tlv22; tlv22 = (char)(tmp_pkt . content); }
    {char tlv25; tlv25 = (char)(tmp_pkt . content); }
    {char tlv23; tlv23 = (char)(tmp_pkt . content); }
    {char* t ; t  = (char*)(tmp_pkt . content); }
    {char* ss ; ss  = (char*)(tmp_pkt . content); }
    {char * tlv27; tlv27 = (char *)(tmp_pkt . content); }
    {char * tlv30; tlv30 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv31; tlv31 = (int)(tmp_pkt . content); }
    {char * tlv35; tlv35 = (char *)(tmp_pkt . content); }
    {int tlv34; tlv34 = (int)(tmp_pkt . content); }
    {int tlv33; tlv33 = (int)(tmp_pkt . content); }
    {void * tlv38; tlv38 = (void *)(tmp_pkt . content); }
    {void * tlv37; tlv37 = (void *)(tmp_pkt . content); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv39; tlv39 = (int)(tmp_pkt . content); }
    {void * tlv43; tlv43 = (void *)(tmp_pkt . content); }
    {void * tlv42; tlv42 = (void *)(tmp_pkt . content); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv44; tlv44 = (int)(tmp_pkt . content); }
    {char * tlv48; tlv48 = (char *)(tmp_pkt . content); }
    {int tlv47; tlv47 = (int)(tmp_pkt . content); }
    {int tlv46; tlv46 = (int)(tmp_pkt . content); }
    {int tlv49; tlv49 = (int)(tmp_pkt . content); }
    {char * tlv53; tlv53 = (char *)(tmp_pkt . content); }
    {int tlv52; tlv52 = (int)(tmp_pkt . content); }
    {int tlv51; tlv51 = (int)(tmp_pkt . content); }
    {int tlv54; tlv54 = (int)(tmp_pkt . content); }
    {int tlv2; tlv2 = (int)(tmp_pkt . content); }
    {int tlv3; tlv3 = (int)(tmp_pkt . content); }
    {char * tlv82; tlv82 = (char *)(tmp_pkt . content); }
    {char * tlv83; tlv83 = (char *)(tmp_pkt . content); }
    {char tlv69; tlv69 = (char)(tmp_pkt . content); }
    {char * tlv58; tlv58 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv59; tlv59 = (int)(tmp_pkt . content); }
    {char * tlv63; tlv63 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv64; tlv64 = (int)(tmp_pkt . content); }
    {char * tlv68; tlv68 = (char *)(tmp_pkt . content); }
    {int tlv67; tlv67 = (int)(tmp_pkt . content); }
    {int tlv66; tlv66 = (int)(tmp_pkt . content); }
    {int tlv72; tlv72 = (int)(tmp_pkt . content); }
    {char * tlv76; tlv76 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv77; tlv77 = (int)(tmp_pkt . content); }
    {int tlv4; tlv4 = (int)(tmp_pkt . content); }
    {char tlv79; tlv79 = (char)(tmp_pkt . content); }
}
void fix_ingred_packet_2_40(){
fix_ingred_packet_2_40_0();
}
void fix_ingred_packet_2_41_0(){
char t [0];
    bzero(&t [0],sizeof(char));
char tlv82_ref;
    bzero(&tlv82_ref,1*sizeof(char));
char * tlv82 = &tlv82_ref;
    {char tlv5; tlv5 = (char)(t); }
    {char tlv7; tlv7 = (char)(t); }
    {int tlv6; tlv6 = (int)(t); }
    {char tlv8; tlv8 = (char)(t); }
    {int rtn; rtn = (int)(t); }
    {char * tlv9; tlv9 = (char *)(t); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(t); }
    {char sideA; sideA = (char)(t); }
    {char sideB; sideB = (char)(t); }
    {int indexA; indexA = (int)(t); }
    {int indexB; indexB = (int)(t); }
    {int tlv1; tlv1 = (int)(t); }
    {char * tlv11; tlv11 = (char *)(t); }
    {void * tlv15; tlv15 = (void *)(t); }
    {void * tlv14; tlv14 = (void *)(t); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(t); }
    {char * tlv18; tlv18 = (char *)(t); }
    {int tlv17; tlv17 = (int)(t); }
    {int tlv16; tlv16 = (int)(t); }
    {int tlv19; tlv19 = (int)(t); }
    {char tlv21; tlv21 = (char)(t); }
    {char tlv22; tlv22 = (char)(t); }
    {char tlv25; tlv25 = (char)(t); }
    {char tlv23; tlv23 = (char)(t); }
    {char* t ; t  = (char*)(t); }
    {char* ss ; ss  = (char*)(t); }
    {char * tlv27; tlv27 = (char *)(t); }
    {char * tlv30; tlv30 = (char *)(t); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(t); }
    {int tlv31; tlv31 = (int)(t); }
    {char * tlv35; tlv35 = (char *)(t); }
    {int tlv34; tlv34 = (int)(t); }
    {int tlv33; tlv33 = (int)(t); }
    {void * tlv38; tlv38 = (void *)(t); }
    {void * tlv37; tlv37 = (void *)(t); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(t); }
    {int tlv39; tlv39 = (int)(t); }
    {void * tlv43; tlv43 = (void *)(t); }
    {void * tlv42; tlv42 = (void *)(t); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(t); }
    {int tlv44; tlv44 = (int)(t); }
    {char * tlv48; tlv48 = (char *)(t); }
    {int tlv47; tlv47 = (int)(t); }
    {int tlv46; tlv46 = (int)(t); }
    {int tlv49; tlv49 = (int)(t); }
    {char * tlv53; tlv53 = (char *)(t); }
    {int tlv52; tlv52 = (int)(t); }
    {int tlv51; tlv51 = (int)(t); }
    {int tlv54; tlv54 = (int)(t); }
    {int tlv2; tlv2 = (int)(t); }
    {int tlv3; tlv3 = (int)(t); }
    {char * tlv82; tlv82 = (char *)(t); }
    {char * tlv83; tlv83 = (char *)(t); }
    {char tlv69; tlv69 = (char)(t); }
    {char * tlv58; tlv58 = (char *)(t); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(t); }
    {int tlv59; tlv59 = (int)(t); }
    {char * tlv63; tlv63 = (char *)(t); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(t); }
    {int tlv64; tlv64 = (int)(t); }
    {char * tlv68; tlv68 = (char *)(t); }
    {int tlv67; tlv67 = (int)(t); }
    {int tlv66; tlv66 = (int)(t); }
    {int tlv72; tlv72 = (int)(t); }
    {char * tlv76; tlv76 = (char *)(t); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(t); }
    {int tlv77; tlv77 = (int)(t); }
    {int tlv4; tlv4 = (int)(t); }
    {char tlv79; tlv79 = (char)(t); }
}
void fix_ingred_packet_2_41_1(){
char t [0];
    bzero(&t [0],sizeof(char));
char tlv82_ref;
    bzero(&tlv82_ref,1*sizeof(char));
char * tlv82 = &tlv82_ref;
    {char tlv5; tlv5 = (char)(cgc_strlen ( tlv82 )); }
    {char tlv7; tlv7 = (char)(cgc_strlen ( tlv82 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv82 )); }
    {char tlv8; tlv8 = (char)(cgc_strlen ( tlv82 )); }
    {int rtn; rtn = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv82 )); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(cgc_strlen ( tlv82 )); }
    {char sideA; sideA = (char)(cgc_strlen ( tlv82 )); }
    {char sideB; sideB = (char)(cgc_strlen ( tlv82 )); }
    {int indexA; indexA = (int)(cgc_strlen ( tlv82 )); }
    {int indexB; indexB = (int)(cgc_strlen ( tlv82 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv82 )); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv82 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv82 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv82 )); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv82 )); }
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv82 )); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv82 )); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv82 )); }
    {char* t ; t  = (char*)(cgc_strlen ( tlv82 )); }
    {char* ss ; ss  = (char*)(cgc_strlen ( tlv82 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv82 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv35; tlv35 = (char *)(cgc_strlen ( tlv82 )); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv82 )); }
    {void * tlv38; tlv38 = (void *)(cgc_strlen ( tlv82 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv82 )); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv82 )); }
    {void * tlv42; tlv42 = (void *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv82 )); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv53; tlv53 = (char *)(cgc_strlen ( tlv82 )); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv83; tlv83 = (char *)(cgc_strlen ( tlv82 )); }
    {char tlv69; tlv69 = (char)(cgc_strlen ( tlv82 )); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {int tlv59; tlv59 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {int tlv64; tlv64 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv68; tlv68 = (char *)(cgc_strlen ( tlv82 )); }
    {int tlv67; tlv67 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv66; tlv66 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv82 )); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv82 )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(cgc_strlen ( tlv82 )); }
    {int tlv77; tlv77 = (int)(cgc_strlen ( tlv82 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv82 )); }
    {char tlv79; tlv79 = (char)(cgc_strlen ( tlv82 )); }
}
void fix_ingred_packet_2_41(){
fix_ingred_packet_2_41_0();
fix_ingred_packet_2_41_1();
}
void fix_ingred_packet_2_43_1(){
char tlv83_ref;
    bzero(&tlv83_ref,1*sizeof(char));
char * tlv83 = &tlv83_ref;
    {char tlv5; tlv5 = (char)(cgc_strlen ( tlv83 )); }
    {char tlv7; tlv7 = (char)(cgc_strlen ( tlv83 )); }
    {int tlv6; tlv6 = (int)(cgc_strlen ( tlv83 )); }
    {char tlv8; tlv8 = (char)(cgc_strlen ( tlv83 )); }
    {int rtn; rtn = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv9; tlv9 = (char *)(cgc_strlen ( tlv83 )); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(cgc_strlen ( tlv83 )); }
    {char sideA; sideA = (char)(cgc_strlen ( tlv83 )); }
    {char sideB; sideB = (char)(cgc_strlen ( tlv83 )); }
    {int indexA; indexA = (int)(cgc_strlen ( tlv83 )); }
    {int indexB; indexB = (int)(cgc_strlen ( tlv83 )); }
    {int tlv1; tlv1 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv11; tlv11 = (char *)(cgc_strlen ( tlv83 )); }
    {void * tlv15; tlv15 = (void *)(cgc_strlen ( tlv83 )); }
    {void * tlv14; tlv14 = (void *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {char * tlv18; tlv18 = (char *)(cgc_strlen ( tlv83 )); }
    {int tlv17; tlv17 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv16; tlv16 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv19; tlv19 = (int)(cgc_strlen ( tlv83 )); }
    {char tlv21; tlv21 = (char)(cgc_strlen ( tlv83 )); }
    {char tlv22; tlv22 = (char)(cgc_strlen ( tlv83 )); }
    {char tlv25; tlv25 = (char)(cgc_strlen ( tlv83 )); }
    {char tlv23; tlv23 = (char)(cgc_strlen ( tlv83 )); }
    {char* t ; t  = (char*)(cgc_strlen ( tlv83 )); }
    {char* ss ; ss  = (char*)(cgc_strlen ( tlv83 )); }
    {char * tlv27; tlv27 = (char *)(cgc_strlen ( tlv83 )); }
    {char * tlv30; tlv30 = (char *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {int tlv31; tlv31 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv35; tlv35 = (char *)(cgc_strlen ( tlv83 )); }
    {int tlv34; tlv34 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv33; tlv33 = (int)(cgc_strlen ( tlv83 )); }
    {void * tlv38; tlv38 = (void *)(cgc_strlen ( tlv83 )); }
    {void * tlv37; tlv37 = (void *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {int tlv39; tlv39 = (int)(cgc_strlen ( tlv83 )); }
    {void * tlv43; tlv43 = (void *)(cgc_strlen ( tlv83 )); }
    {void * tlv42; tlv42 = (void *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {int tlv44; tlv44 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv48; tlv48 = (char *)(cgc_strlen ( tlv83 )); }
    {int tlv47; tlv47 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv46; tlv46 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv49; tlv49 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv53; tlv53 = (char *)(cgc_strlen ( tlv83 )); }
    {int tlv52; tlv52 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv51; tlv51 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv54; tlv54 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv2; tlv2 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv3; tlv3 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv82; tlv82 = (char *)(cgc_strlen ( tlv83 )); }
    {char tlv69; tlv69 = (char)(cgc_strlen ( tlv83 )); }
    {char * tlv58; tlv58 = (char *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {int tlv59; tlv59 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv63; tlv63 = (char *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {int tlv64; tlv64 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv68; tlv68 = (char *)(cgc_strlen ( tlv83 )); }
    {int tlv67; tlv67 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv66; tlv66 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv72; tlv72 = (int)(cgc_strlen ( tlv83 )); }
    {char * tlv76; tlv76 = (char *)(cgc_strlen ( tlv83 )); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(cgc_strlen ( tlv83 )); }
    {int tlv77; tlv77 = (int)(cgc_strlen ( tlv83 )); }
    {int tlv4; tlv4 = (int)(cgc_strlen ( tlv83 )); }
    {char tlv79; tlv79 = (char)(cgc_strlen ( tlv83 )); }
}
void fix_ingred_packet_2_43(){
fix_ingred_packet_2_43_1();
}
void fix_ingred_packet_2_45_9(){
    {char tlv5; tlv5 = (char)(22); }
    {char tlv7; tlv7 = (char)(22); }
    {int tlv6; tlv6 = (int)(22); }
    {char tlv8; tlv8 = (char)(22); }
    {int rtn; rtn = (int)(22); }
    {char * tlv9; tlv9 = (char *)(22); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(22); }
    {char sideA; sideA = (char)(22); }
    {char sideB; sideB = (char)(22); }
    {int indexA; indexA = (int)(22); }
    {int indexB; indexB = (int)(22); }
    {int tlv1; tlv1 = (int)(22); }
    {char * tlv11; tlv11 = (char *)(22); }
    {void * tlv15; tlv15 = (void *)(22); }
    {void * tlv14; tlv14 = (void *)(22); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(22); }
    {char * tlv18; tlv18 = (char *)(22); }
    {int tlv17; tlv17 = (int)(22); }
    {int tlv16; tlv16 = (int)(22); }
    {int tlv19; tlv19 = (int)(22); }
    {char tlv21; tlv21 = (char)(22); }
    {char tlv22; tlv22 = (char)(22); }
    {char tlv25; tlv25 = (char)(22); }
    {char tlv23; tlv23 = (char)(22); }
    {char* t ; t  = (char*)(22); }
    {char* ss ; ss  = (char*)(22); }
    {char * tlv27; tlv27 = (char *)(22); }
    {char * tlv30; tlv30 = (char *)(22); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(22); }
    {int tlv31; tlv31 = (int)(22); }
    {char * tlv35; tlv35 = (char *)(22); }
    {int tlv34; tlv34 = (int)(22); }
    {int tlv33; tlv33 = (int)(22); }
    {void * tlv38; tlv38 = (void *)(22); }
    {void * tlv37; tlv37 = (void *)(22); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(22); }
    {int tlv39; tlv39 = (int)(22); }
    {void * tlv43; tlv43 = (void *)(22); }
    {void * tlv42; tlv42 = (void *)(22); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(22); }
    {int tlv44; tlv44 = (int)(22); }
    {char * tlv48; tlv48 = (char *)(22); }
    {int tlv47; tlv47 = (int)(22); }
    {int tlv46; tlv46 = (int)(22); }
    {int tlv49; tlv49 = (int)(22); }
    {char * tlv53; tlv53 = (char *)(22); }
    {int tlv52; tlv52 = (int)(22); }
    {int tlv51; tlv51 = (int)(22); }
    {int tlv54; tlv54 = (int)(22); }
    {int tlv2; tlv2 = (int)(22); }
    {int tlv3; tlv3 = (int)(22); }
    {char * tlv82; tlv82 = (char *)(22); }
    {char * tlv83; tlv83 = (char *)(22); }
    {char tlv69; tlv69 = (char)(22); }
    {char * tlv58; tlv58 = (char *)(22); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(22); }
    {int tlv59; tlv59 = (int)(22); }
    {char * tlv63; tlv63 = (char *)(22); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(22); }
    {int tlv64; tlv64 = (int)(22); }
    {char * tlv68; tlv68 = (char *)(22); }
    {int tlv67; tlv67 = (int)(22); }
    {int tlv66; tlv66 = (int)(22); }
    {int tlv72; tlv72 = (int)(22); }
    {char * tlv76; tlv76 = (char *)(22); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(22); }
    {int tlv77; tlv77 = (int)(22); }
    {int tlv4; tlv4 = (int)(22); }
    {char tlv79; tlv79 = (char)(22); }
}
void fix_ingred_packet_2_45(){
fix_ingred_packet_2_45_9();
}
void fix_ingred_packet_2_46_0(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
    {char tlv5; tlv5 = (char)(tmp . content); }
    {char tlv7; tlv7 = (char)(tmp . content); }
    {int tlv6; tlv6 = (int)(tmp . content); }
    {char tlv8; tlv8 = (char)(tmp . content); }
    {int rtn; rtn = (int)(tmp . content); }
    {char * tlv9; tlv9 = (char *)(tmp . content); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tmp . content); }
    {char sideA; sideA = (char)(tmp . content); }
    {char sideB; sideB = (char)(tmp . content); }
    {int indexA; indexA = (int)(tmp . content); }
    {int indexB; indexB = (int)(tmp . content); }
    {int tlv1; tlv1 = (int)(tmp . content); }
    {char * tlv11; tlv11 = (char *)(tmp . content); }
    {void * tlv15; tlv15 = (void *)(tmp . content); }
    {void * tlv14; tlv14 = (void *)(tmp . content); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tmp . content); }
    {char * tlv18; tlv18 = (char *)(tmp . content); }
    {int tlv17; tlv17 = (int)(tmp . content); }
    {int tlv16; tlv16 = (int)(tmp . content); }
    {int tlv19; tlv19 = (int)(tmp . content); }
    {char tlv21; tlv21 = (char)(tmp . content); }
    {char tlv22; tlv22 = (char)(tmp . content); }
    {char tlv25; tlv25 = (char)(tmp . content); }
    {char tlv23; tlv23 = (char)(tmp . content); }
    {char* t ; t  = (char*)(tmp . content); }
    {char* ss ; ss  = (char*)(tmp . content); }
    {char * tlv27; tlv27 = (char *)(tmp . content); }
    {char * tlv30; tlv30 = (char *)(tmp . content); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tmp . content); }
    {int tlv31; tlv31 = (int)(tmp . content); }
    {char * tlv35; tlv35 = (char *)(tmp . content); }
    {int tlv34; tlv34 = (int)(tmp . content); }
    {int tlv33; tlv33 = (int)(tmp . content); }
    {void * tlv38; tlv38 = (void *)(tmp . content); }
    {void * tlv37; tlv37 = (void *)(tmp . content); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tmp . content); }
    {int tlv39; tlv39 = (int)(tmp . content); }
    {void * tlv43; tlv43 = (void *)(tmp . content); }
    {void * tlv42; tlv42 = (void *)(tmp . content); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tmp . content); }
    {int tlv44; tlv44 = (int)(tmp . content); }
    {char * tlv48; tlv48 = (char *)(tmp . content); }
    {int tlv47; tlv47 = (int)(tmp . content); }
    {int tlv46; tlv46 = (int)(tmp . content); }
    {int tlv49; tlv49 = (int)(tmp . content); }
    {char * tlv53; tlv53 = (char *)(tmp . content); }
    {int tlv52; tlv52 = (int)(tmp . content); }
    {int tlv51; tlv51 = (int)(tmp . content); }
    {int tlv54; tlv54 = (int)(tmp . content); }
    {int tlv2; tlv2 = (int)(tmp . content); }
    {int tlv3; tlv3 = (int)(tmp . content); }
    {char * tlv82; tlv82 = (char *)(tmp . content); }
    {char * tlv83; tlv83 = (char *)(tmp . content); }
    {char tlv69; tlv69 = (char)(tmp . content); }
    {char * tlv58; tlv58 = (char *)(tmp . content); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tmp . content); }
    {int tlv59; tlv59 = (int)(tmp . content); }
    {char * tlv63; tlv63 = (char *)(tmp . content); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tmp . content); }
    {int tlv64; tlv64 = (int)(tmp . content); }
    {char * tlv68; tlv68 = (char *)(tmp . content); }
    {int tlv67; tlv67 = (int)(tmp . content); }
    {int tlv66; tlv66 = (int)(tmp . content); }
    {int tlv72; tlv72 = (int)(tmp . content); }
    {char * tlv76; tlv76 = (char *)(tmp . content); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tmp . content); }
    {int tlv77; tlv77 = (int)(tmp . content); }
    {int tlv4; tlv4 = (int)(tmp . content); }
    {char tlv79; tlv79 = (char)(tmp . content); }
}
void fix_ingred_packet_2_46_1(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
    {char tlv5; tlv5 = (char)(7); }
    {char tlv7; tlv7 = (char)(7); }
    {int tlv6; tlv6 = (int)(7); }
    {char tlv8; tlv8 = (char)(7); }
    {int rtn; rtn = (int)(7); }
    {char * tlv9; tlv9 = (char *)(7); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(7); }
    {char sideA; sideA = (char)(7); }
    {char sideB; sideB = (char)(7); }
    {int indexA; indexA = (int)(7); }
    {int indexB; indexB = (int)(7); }
    {int tlv1; tlv1 = (int)(7); }
    {char * tlv11; tlv11 = (char *)(7); }
    {void * tlv15; tlv15 = (void *)(7); }
    {void * tlv14; tlv14 = (void *)(7); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(7); }
    {char * tlv18; tlv18 = (char *)(7); }
    {int tlv17; tlv17 = (int)(7); }
    {int tlv16; tlv16 = (int)(7); }
    {int tlv19; tlv19 = (int)(7); }
    {char tlv21; tlv21 = (char)(7); }
    {char tlv22; tlv22 = (char)(7); }
    {char tlv25; tlv25 = (char)(7); }
    {char tlv23; tlv23 = (char)(7); }
    {char* t ; t  = (char*)(7); }
    {char* ss ; ss  = (char*)(7); }
    {char * tlv27; tlv27 = (char *)(7); }
    {char * tlv30; tlv30 = (char *)(7); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(7); }
    {int tlv31; tlv31 = (int)(7); }
    {char * tlv35; tlv35 = (char *)(7); }
    {int tlv34; tlv34 = (int)(7); }
    {int tlv33; tlv33 = (int)(7); }
    {void * tlv38; tlv38 = (void *)(7); }
    {void * tlv37; tlv37 = (void *)(7); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(7); }
    {int tlv39; tlv39 = (int)(7); }
    {void * tlv43; tlv43 = (void *)(7); }
    {void * tlv42; tlv42 = (void *)(7); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(7); }
    {int tlv44; tlv44 = (int)(7); }
    {char * tlv48; tlv48 = (char *)(7); }
    {int tlv47; tlv47 = (int)(7); }
    {int tlv46; tlv46 = (int)(7); }
    {int tlv49; tlv49 = (int)(7); }
    {char * tlv53; tlv53 = (char *)(7); }
    {int tlv52; tlv52 = (int)(7); }
    {int tlv51; tlv51 = (int)(7); }
    {int tlv54; tlv54 = (int)(7); }
    {int tlv2; tlv2 = (int)(7); }
    {int tlv3; tlv3 = (int)(7); }
    {char * tlv82; tlv82 = (char *)(7); }
    {char * tlv83; tlv83 = (char *)(7); }
    {char tlv69; tlv69 = (char)(7); }
    {char * tlv58; tlv58 = (char *)(7); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(7); }
    {int tlv59; tlv59 = (int)(7); }
    {char * tlv63; tlv63 = (char *)(7); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(7); }
    {int tlv64; tlv64 = (int)(7); }
    {char * tlv68; tlv68 = (char *)(7); }
    {int tlv67; tlv67 = (int)(7); }
    {int tlv66; tlv66 = (int)(7); }
    {int tlv72; tlv72 = (int)(7); }
    {char * tlv76; tlv76 = (char *)(7); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(7); }
    {int tlv77; tlv77 = (int)(7); }
    {int tlv4; tlv4 = (int)(7); }
    {char tlv79; tlv79 = (char)(7); }
}
void fix_ingred_packet_2_46(){
fix_ingred_packet_2_46_0();
fix_ingred_packet_2_46_1();
}
void fix_ingred_packet_2_47_1(){
    {char tlv5; tlv5 = (char)(7); }
    {char tlv7; tlv7 = (char)(7); }
    {int tlv6; tlv6 = (int)(7); }
    {char tlv8; tlv8 = (char)(7); }
    {int rtn; rtn = (int)(7); }
    {char * tlv9; tlv9 = (char *)(7); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(7); }
    {char sideA; sideA = (char)(7); }
    {char sideB; sideB = (char)(7); }
    {int indexA; indexA = (int)(7); }
    {int indexB; indexB = (int)(7); }
    {int tlv1; tlv1 = (int)(7); }
    {char * tlv11; tlv11 = (char *)(7); }
    {void * tlv15; tlv15 = (void *)(7); }
    {void * tlv14; tlv14 = (void *)(7); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(7); }
    {char * tlv18; tlv18 = (char *)(7); }
    {int tlv17; tlv17 = (int)(7); }
    {int tlv16; tlv16 = (int)(7); }
    {int tlv19; tlv19 = (int)(7); }
    {char tlv21; tlv21 = (char)(7); }
    {char tlv22; tlv22 = (char)(7); }
    {char tlv25; tlv25 = (char)(7); }
    {char tlv23; tlv23 = (char)(7); }
    {char* t ; t  = (char*)(7); }
    {char* ss ; ss  = (char*)(7); }
    {char * tlv27; tlv27 = (char *)(7); }
    {char * tlv30; tlv30 = (char *)(7); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(7); }
    {int tlv31; tlv31 = (int)(7); }
    {char * tlv35; tlv35 = (char *)(7); }
    {int tlv34; tlv34 = (int)(7); }
    {int tlv33; tlv33 = (int)(7); }
    {void * tlv38; tlv38 = (void *)(7); }
    {void * tlv37; tlv37 = (void *)(7); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(7); }
    {int tlv39; tlv39 = (int)(7); }
    {void * tlv43; tlv43 = (void *)(7); }
    {void * tlv42; tlv42 = (void *)(7); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(7); }
    {int tlv44; tlv44 = (int)(7); }
    {char * tlv48; tlv48 = (char *)(7); }
    {int tlv47; tlv47 = (int)(7); }
    {int tlv46; tlv46 = (int)(7); }
    {int tlv49; tlv49 = (int)(7); }
    {char * tlv53; tlv53 = (char *)(7); }
    {int tlv52; tlv52 = (int)(7); }
    {int tlv51; tlv51 = (int)(7); }
    {int tlv54; tlv54 = (int)(7); }
    {int tlv2; tlv2 = (int)(7); }
    {int tlv3; tlv3 = (int)(7); }
    {char * tlv82; tlv82 = (char *)(7); }
    {char * tlv83; tlv83 = (char *)(7); }
    {char tlv69; tlv69 = (char)(7); }
    {char * tlv58; tlv58 = (char *)(7); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(7); }
    {int tlv59; tlv59 = (int)(7); }
    {char * tlv63; tlv63 = (char *)(7); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(7); }
    {int tlv64; tlv64 = (int)(7); }
    {char * tlv68; tlv68 = (char *)(7); }
    {int tlv67; tlv67 = (int)(7); }
    {int tlv66; tlv66 = (int)(7); }
    {int tlv72; tlv72 = (int)(7); }
    {char * tlv76; tlv76 = (char *)(7); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(7); }
    {int tlv77; tlv77 = (int)(7); }
    {int tlv4; tlv4 = (int)(7); }
    {char tlv79; tlv79 = (char)(7); }
}
void fix_ingred_packet_2_47(){
fix_ingred_packet_2_47_1();
}
void fix_ingred_packet_2_49_1(){
    {char tlv5; tlv5 = (char)(9); }
    {char tlv7; tlv7 = (char)(9); }
    {int tlv6; tlv6 = (int)(9); }
    {char tlv8; tlv8 = (char)(9); }
    {int rtn; rtn = (int)(9); }
    {char * tlv9; tlv9 = (char *)(9); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(9); }
    {char sideA; sideA = (char)(9); }
    {char sideB; sideB = (char)(9); }
    {int indexA; indexA = (int)(9); }
    {int indexB; indexB = (int)(9); }
    {int tlv1; tlv1 = (int)(9); }
    {char * tlv11; tlv11 = (char *)(9); }
    {void * tlv15; tlv15 = (void *)(9); }
    {void * tlv14; tlv14 = (void *)(9); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(9); }
    {char * tlv18; tlv18 = (char *)(9); }
    {int tlv17; tlv17 = (int)(9); }
    {int tlv16; tlv16 = (int)(9); }
    {int tlv19; tlv19 = (int)(9); }
    {char tlv21; tlv21 = (char)(9); }
    {char tlv22; tlv22 = (char)(9); }
    {char tlv25; tlv25 = (char)(9); }
    {char tlv23; tlv23 = (char)(9); }
    {char* t ; t  = (char*)(9); }
    {char* ss ; ss  = (char*)(9); }
    {char * tlv27; tlv27 = (char *)(9); }
    {char * tlv30; tlv30 = (char *)(9); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(9); }
    {int tlv31; tlv31 = (int)(9); }
    {char * tlv35; tlv35 = (char *)(9); }
    {int tlv34; tlv34 = (int)(9); }
    {int tlv33; tlv33 = (int)(9); }
    {void * tlv38; tlv38 = (void *)(9); }
    {void * tlv37; tlv37 = (void *)(9); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(9); }
    {int tlv39; tlv39 = (int)(9); }
    {void * tlv43; tlv43 = (void *)(9); }
    {void * tlv42; tlv42 = (void *)(9); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(9); }
    {int tlv44; tlv44 = (int)(9); }
    {char * tlv48; tlv48 = (char *)(9); }
    {int tlv47; tlv47 = (int)(9); }
    {int tlv46; tlv46 = (int)(9); }
    {int tlv49; tlv49 = (int)(9); }
    {char * tlv53; tlv53 = (char *)(9); }
    {int tlv52; tlv52 = (int)(9); }
    {int tlv51; tlv51 = (int)(9); }
    {int tlv54; tlv54 = (int)(9); }
    {int tlv2; tlv2 = (int)(9); }
    {int tlv3; tlv3 = (int)(9); }
    {char * tlv82; tlv82 = (char *)(9); }
    {char * tlv83; tlv83 = (char *)(9); }
    {char tlv69; tlv69 = (char)(9); }
    {char * tlv58; tlv58 = (char *)(9); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(9); }
    {int tlv59; tlv59 = (int)(9); }
    {char * tlv63; tlv63 = (char *)(9); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(9); }
    {int tlv64; tlv64 = (int)(9); }
    {char * tlv68; tlv68 = (char *)(9); }
    {int tlv67; tlv67 = (int)(9); }
    {int tlv66; tlv66 = (int)(9); }
    {int tlv72; tlv72 = (int)(9); }
    {char * tlv76; tlv76 = (char *)(9); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(9); }
    {int tlv77; tlv77 = (int)(9); }
    {int tlv4; tlv4 = (int)(9); }
    {char tlv79; tlv79 = (char)(9); }
}
void fix_ingred_packet_2_49(){
fix_ingred_packet_2_49_1();
}
void fix_ingred_packet_2_50_1(){
    {char tlv5; tlv5 = (char)(9); }
    {char tlv7; tlv7 = (char)(9); }
    {int tlv6; tlv6 = (int)(9); }
    {char tlv8; tlv8 = (char)(9); }
    {int rtn; rtn = (int)(9); }
    {char * tlv9; tlv9 = (char *)(9); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(9); }
    {char sideA; sideA = (char)(9); }
    {char sideB; sideB = (char)(9); }
    {int indexA; indexA = (int)(9); }
    {int indexB; indexB = (int)(9); }
    {int tlv1; tlv1 = (int)(9); }
    {char * tlv11; tlv11 = (char *)(9); }
    {void * tlv15; tlv15 = (void *)(9); }
    {void * tlv14; tlv14 = (void *)(9); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(9); }
    {char * tlv18; tlv18 = (char *)(9); }
    {int tlv17; tlv17 = (int)(9); }
    {int tlv16; tlv16 = (int)(9); }
    {int tlv19; tlv19 = (int)(9); }
    {char tlv21; tlv21 = (char)(9); }
    {char tlv22; tlv22 = (char)(9); }
    {char tlv25; tlv25 = (char)(9); }
    {char tlv23; tlv23 = (char)(9); }
    {char* t ; t  = (char*)(9); }
    {char* ss ; ss  = (char*)(9); }
    {char * tlv27; tlv27 = (char *)(9); }
    {char * tlv30; tlv30 = (char *)(9); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(9); }
    {int tlv31; tlv31 = (int)(9); }
    {char * tlv35; tlv35 = (char *)(9); }
    {int tlv34; tlv34 = (int)(9); }
    {int tlv33; tlv33 = (int)(9); }
    {void * tlv38; tlv38 = (void *)(9); }
    {void * tlv37; tlv37 = (void *)(9); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(9); }
    {int tlv39; tlv39 = (int)(9); }
    {void * tlv43; tlv43 = (void *)(9); }
    {void * tlv42; tlv42 = (void *)(9); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(9); }
    {int tlv44; tlv44 = (int)(9); }
    {char * tlv48; tlv48 = (char *)(9); }
    {int tlv47; tlv47 = (int)(9); }
    {int tlv46; tlv46 = (int)(9); }
    {int tlv49; tlv49 = (int)(9); }
    {char * tlv53; tlv53 = (char *)(9); }
    {int tlv52; tlv52 = (int)(9); }
    {int tlv51; tlv51 = (int)(9); }
    {int tlv54; tlv54 = (int)(9); }
    {int tlv2; tlv2 = (int)(9); }
    {int tlv3; tlv3 = (int)(9); }
    {char * tlv82; tlv82 = (char *)(9); }
    {char * tlv83; tlv83 = (char *)(9); }
    {char tlv69; tlv69 = (char)(9); }
    {char * tlv58; tlv58 = (char *)(9); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(9); }
    {int tlv59; tlv59 = (int)(9); }
    {char * tlv63; tlv63 = (char *)(9); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(9); }
    {int tlv64; tlv64 = (int)(9); }
    {char * tlv68; tlv68 = (char *)(9); }
    {int tlv67; tlv67 = (int)(9); }
    {int tlv66; tlv66 = (int)(9); }
    {int tlv72; tlv72 = (int)(9); }
    {char * tlv76; tlv76 = (char *)(9); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(9); }
    {int tlv77; tlv77 = (int)(9); }
    {int tlv4; tlv4 = (int)(9); }
    {char tlv79; tlv79 = (char)(9); }
}
void fix_ingred_packet_2_50(){
fix_ingred_packet_2_50_1();
}
void fix_ingred_packet_2_52_1(){
char ss [ 9 ];
    bzero(&ss,( 9 *sizeof(char) ) );
    {char tlv5; tlv5 = (char)(ss); }
    {char tlv7; tlv7 = (char)(ss); }
    {int tlv6; tlv6 = (int)(ss); }
    {char tlv8; tlv8 = (char)(ss); }
    {int rtn; rtn = (int)(ss); }
    {char * tlv9; tlv9 = (char *)(ss); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(ss); }
    {char sideA; sideA = (char)(ss); }
    {char sideB; sideB = (char)(ss); }
    {int indexA; indexA = (int)(ss); }
    {int indexB; indexB = (int)(ss); }
    {int tlv1; tlv1 = (int)(ss); }
    {char * tlv11; tlv11 = (char *)(ss); }
    {void * tlv15; tlv15 = (void *)(ss); }
    {void * tlv14; tlv14 = (void *)(ss); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ss); }
    {char * tlv18; tlv18 = (char *)(ss); }
    {int tlv17; tlv17 = (int)(ss); }
    {int tlv16; tlv16 = (int)(ss); }
    {int tlv19; tlv19 = (int)(ss); }
    {char tlv21; tlv21 = (char)(ss); }
    {char tlv22; tlv22 = (char)(ss); }
    {char tlv25; tlv25 = (char)(ss); }
    {char tlv23; tlv23 = (char)(ss); }
    {char* t ; t  = (char*)(ss); }
    {char* ss ; ss  = (char*)(ss); }
    {char * tlv27; tlv27 = (char *)(ss); }
    {char * tlv30; tlv30 = (char *)(ss); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ss); }
    {int tlv31; tlv31 = (int)(ss); }
    {char * tlv35; tlv35 = (char *)(ss); }
    {int tlv34; tlv34 = (int)(ss); }
    {int tlv33; tlv33 = (int)(ss); }
    {void * tlv38; tlv38 = (void *)(ss); }
    {void * tlv37; tlv37 = (void *)(ss); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(ss); }
    {int tlv39; tlv39 = (int)(ss); }
    {void * tlv43; tlv43 = (void *)(ss); }
    {void * tlv42; tlv42 = (void *)(ss); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(ss); }
    {int tlv44; tlv44 = (int)(ss); }
    {char * tlv48; tlv48 = (char *)(ss); }
    {int tlv47; tlv47 = (int)(ss); }
    {int tlv46; tlv46 = (int)(ss); }
    {int tlv49; tlv49 = (int)(ss); }
    {char * tlv53; tlv53 = (char *)(ss); }
    {int tlv52; tlv52 = (int)(ss); }
    {int tlv51; tlv51 = (int)(ss); }
    {int tlv54; tlv54 = (int)(ss); }
    {int tlv2; tlv2 = (int)(ss); }
    {int tlv3; tlv3 = (int)(ss); }
    {char * tlv82; tlv82 = (char *)(ss); }
    {char * tlv83; tlv83 = (char *)(ss); }
    {char tlv69; tlv69 = (char)(ss); }
    {char * tlv58; tlv58 = (char *)(ss); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(ss); }
    {int tlv59; tlv59 = (int)(ss); }
    {char * tlv63; tlv63 = (char *)(ss); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ss); }
    {int tlv64; tlv64 = (int)(ss); }
    {char * tlv68; tlv68 = (char *)(ss); }
    {int tlv67; tlv67 = (int)(ss); }
    {int tlv66; tlv66 = (int)(ss); }
    {int tlv72; tlv72 = (int)(ss); }
    {char * tlv76; tlv76 = (char *)(ss); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(ss); }
    {int tlv77; tlv77 = (int)(ss); }
    {int tlv4; tlv4 = (int)(ss); }
    {char tlv79; tlv79 = (char)(ss); }
}
void fix_ingred_packet_2_52(){
fix_ingred_packet_2_52_1();
}
void fix_ingred_packet_2_53_0(){
Packet tmp_pkt;
    bzero(&tmp_pkt,sizeof(Packet));
char ss [ 9 ];
    bzero(&ss,( 9 *sizeof(char) ) );
    {char tlv5; tlv5 = (char)(tmp_pkt . content); }
    {char tlv7; tlv7 = (char)(tmp_pkt . content); }
    {int tlv6; tlv6 = (int)(tmp_pkt . content); }
    {char tlv8; tlv8 = (char)(tmp_pkt . content); }
    {int rtn; rtn = (int)(tmp_pkt . content); }
    {char * tlv9; tlv9 = (char *)(tmp_pkt . content); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tmp_pkt . content); }
    {char sideA; sideA = (char)(tmp_pkt . content); }
    {char sideB; sideB = (char)(tmp_pkt . content); }
    {int indexA; indexA = (int)(tmp_pkt . content); }
    {int indexB; indexB = (int)(tmp_pkt . content); }
    {int tlv1; tlv1 = (int)(tmp_pkt . content); }
    {char * tlv11; tlv11 = (char *)(tmp_pkt . content); }
    {void * tlv15; tlv15 = (void *)(tmp_pkt . content); }
    {void * tlv14; tlv14 = (void *)(tmp_pkt . content); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tmp_pkt . content); }
    {char * tlv18; tlv18 = (char *)(tmp_pkt . content); }
    {int tlv17; tlv17 = (int)(tmp_pkt . content); }
    {int tlv16; tlv16 = (int)(tmp_pkt . content); }
    {int tlv19; tlv19 = (int)(tmp_pkt . content); }
    {char tlv21; tlv21 = (char)(tmp_pkt . content); }
    {char tlv22; tlv22 = (char)(tmp_pkt . content); }
    {char tlv25; tlv25 = (char)(tmp_pkt . content); }
    {char tlv23; tlv23 = (char)(tmp_pkt . content); }
    {char* t ; t  = (char*)(tmp_pkt . content); }
    {char* ss ; ss  = (char*)(tmp_pkt . content); }
    {char * tlv27; tlv27 = (char *)(tmp_pkt . content); }
    {char * tlv30; tlv30 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv31; tlv31 = (int)(tmp_pkt . content); }
    {char * tlv35; tlv35 = (char *)(tmp_pkt . content); }
    {int tlv34; tlv34 = (int)(tmp_pkt . content); }
    {int tlv33; tlv33 = (int)(tmp_pkt . content); }
    {void * tlv38; tlv38 = (void *)(tmp_pkt . content); }
    {void * tlv37; tlv37 = (void *)(tmp_pkt . content); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv39; tlv39 = (int)(tmp_pkt . content); }
    {void * tlv43; tlv43 = (void *)(tmp_pkt . content); }
    {void * tlv42; tlv42 = (void *)(tmp_pkt . content); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv44; tlv44 = (int)(tmp_pkt . content); }
    {char * tlv48; tlv48 = (char *)(tmp_pkt . content); }
    {int tlv47; tlv47 = (int)(tmp_pkt . content); }
    {int tlv46; tlv46 = (int)(tmp_pkt . content); }
    {int tlv49; tlv49 = (int)(tmp_pkt . content); }
    {char * tlv53; tlv53 = (char *)(tmp_pkt . content); }
    {int tlv52; tlv52 = (int)(tmp_pkt . content); }
    {int tlv51; tlv51 = (int)(tmp_pkt . content); }
    {int tlv54; tlv54 = (int)(tmp_pkt . content); }
    {int tlv2; tlv2 = (int)(tmp_pkt . content); }
    {int tlv3; tlv3 = (int)(tmp_pkt . content); }
    {char * tlv82; tlv82 = (char *)(tmp_pkt . content); }
    {char * tlv83; tlv83 = (char *)(tmp_pkt . content); }
    {char tlv69; tlv69 = (char)(tmp_pkt . content); }
    {char * tlv58; tlv58 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv59; tlv59 = (int)(tmp_pkt . content); }
    {char * tlv63; tlv63 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv64; tlv64 = (int)(tmp_pkt . content); }
    {char * tlv68; tlv68 = (char *)(tmp_pkt . content); }
    {int tlv67; tlv67 = (int)(tmp_pkt . content); }
    {int tlv66; tlv66 = (int)(tmp_pkt . content); }
    {int tlv72; tlv72 = (int)(tmp_pkt . content); }
    {char * tlv76; tlv76 = (char *)(tmp_pkt . content); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tmp_pkt . content); }
    {int tlv77; tlv77 = (int)(tmp_pkt . content); }
    {int tlv4; tlv4 = (int)(tmp_pkt . content); }
    {char tlv79; tlv79 = (char)(tmp_pkt . content); }
}
void fix_ingred_packet_2_53_1(){
Packet tmp_pkt;
    bzero(&tmp_pkt,sizeof(Packet));
char ss [ 9 ];
    bzero(&ss,( 9 *sizeof(char) ) );
    {char tlv5; tlv5 = (char)(ss); }
    {char tlv7; tlv7 = (char)(ss); }
    {int tlv6; tlv6 = (int)(ss); }
    {char tlv8; tlv8 = (char)(ss); }
    {int rtn; rtn = (int)(ss); }
    {char * tlv9; tlv9 = (char *)(ss); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(ss); }
    {char sideA; sideA = (char)(ss); }
    {char sideB; sideB = (char)(ss); }
    {int indexA; indexA = (int)(ss); }
    {int indexB; indexB = (int)(ss); }
    {int tlv1; tlv1 = (int)(ss); }
    {char * tlv11; tlv11 = (char *)(ss); }
    {void * tlv15; tlv15 = (void *)(ss); }
    {void * tlv14; tlv14 = (void *)(ss); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ss); }
    {char * tlv18; tlv18 = (char *)(ss); }
    {int tlv17; tlv17 = (int)(ss); }
    {int tlv16; tlv16 = (int)(ss); }
    {int tlv19; tlv19 = (int)(ss); }
    {char tlv21; tlv21 = (char)(ss); }
    {char tlv22; tlv22 = (char)(ss); }
    {char tlv25; tlv25 = (char)(ss); }
    {char tlv23; tlv23 = (char)(ss); }
    {char* t ; t  = (char*)(ss); }
    {char* ss ; ss  = (char*)(ss); }
    {char * tlv27; tlv27 = (char *)(ss); }
    {char * tlv30; tlv30 = (char *)(ss); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ss); }
    {int tlv31; tlv31 = (int)(ss); }
    {char * tlv35; tlv35 = (char *)(ss); }
    {int tlv34; tlv34 = (int)(ss); }
    {int tlv33; tlv33 = (int)(ss); }
    {void * tlv38; tlv38 = (void *)(ss); }
    {void * tlv37; tlv37 = (void *)(ss); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(ss); }
    {int tlv39; tlv39 = (int)(ss); }
    {void * tlv43; tlv43 = (void *)(ss); }
    {void * tlv42; tlv42 = (void *)(ss); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(ss); }
    {int tlv44; tlv44 = (int)(ss); }
    {char * tlv48; tlv48 = (char *)(ss); }
    {int tlv47; tlv47 = (int)(ss); }
    {int tlv46; tlv46 = (int)(ss); }
    {int tlv49; tlv49 = (int)(ss); }
    {char * tlv53; tlv53 = (char *)(ss); }
    {int tlv52; tlv52 = (int)(ss); }
    {int tlv51; tlv51 = (int)(ss); }
    {int tlv54; tlv54 = (int)(ss); }
    {int tlv2; tlv2 = (int)(ss); }
    {int tlv3; tlv3 = (int)(ss); }
    {char * tlv82; tlv82 = (char *)(ss); }
    {char * tlv83; tlv83 = (char *)(ss); }
    {char tlv69; tlv69 = (char)(ss); }
    {char * tlv58; tlv58 = (char *)(ss); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(ss); }
    {int tlv59; tlv59 = (int)(ss); }
    {char * tlv63; tlv63 = (char *)(ss); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ss); }
    {int tlv64; tlv64 = (int)(ss); }
    {char * tlv68; tlv68 = (char *)(ss); }
    {int tlv67; tlv67 = (int)(ss); }
    {int tlv66; tlv66 = (int)(ss); }
    {int tlv72; tlv72 = (int)(ss); }
    {char * tlv76; tlv76 = (char *)(ss); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(ss); }
    {int tlv77; tlv77 = (int)(ss); }
    {int tlv4; tlv4 = (int)(ss); }
    {char tlv79; tlv79 = (char)(ss); }
}
void fix_ingred_packet_2_53(){
fix_ingred_packet_2_53_0();
fix_ingred_packet_2_53_1();
}
void fix_ingred_packet_2_54_1(){
    {char tlv5; tlv5 = (char)(10); }
    {char tlv7; tlv7 = (char)(10); }
    {int tlv6; tlv6 = (int)(10); }
    {char tlv8; tlv8 = (char)(10); }
    {int rtn; rtn = (int)(10); }
    {char * tlv9; tlv9 = (char *)(10); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(10); }
    {char sideA; sideA = (char)(10); }
    {char sideB; sideB = (char)(10); }
    {int indexA; indexA = (int)(10); }
    {int indexB; indexB = (int)(10); }
    {int tlv1; tlv1 = (int)(10); }
    {char * tlv11; tlv11 = (char *)(10); }
    {void * tlv15; tlv15 = (void *)(10); }
    {void * tlv14; tlv14 = (void *)(10); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(10); }
    {char * tlv18; tlv18 = (char *)(10); }
    {int tlv17; tlv17 = (int)(10); }
    {int tlv16; tlv16 = (int)(10); }
    {int tlv19; tlv19 = (int)(10); }
    {char tlv21; tlv21 = (char)(10); }
    {char tlv22; tlv22 = (char)(10); }
    {char tlv25; tlv25 = (char)(10); }
    {char tlv23; tlv23 = (char)(10); }
    {char* t ; t  = (char*)(10); }
    {char* ss ; ss  = (char*)(10); }
    {char * tlv27; tlv27 = (char *)(10); }
    {char * tlv30; tlv30 = (char *)(10); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(10); }
    {int tlv31; tlv31 = (int)(10); }
    {char * tlv35; tlv35 = (char *)(10); }
    {int tlv34; tlv34 = (int)(10); }
    {int tlv33; tlv33 = (int)(10); }
    {void * tlv38; tlv38 = (void *)(10); }
    {void * tlv37; tlv37 = (void *)(10); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(10); }
    {int tlv39; tlv39 = (int)(10); }
    {void * tlv43; tlv43 = (void *)(10); }
    {void * tlv42; tlv42 = (void *)(10); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(10); }
    {int tlv44; tlv44 = (int)(10); }
    {char * tlv48; tlv48 = (char *)(10); }
    {int tlv47; tlv47 = (int)(10); }
    {int tlv46; tlv46 = (int)(10); }
    {int tlv49; tlv49 = (int)(10); }
    {char * tlv53; tlv53 = (char *)(10); }
    {int tlv52; tlv52 = (int)(10); }
    {int tlv51; tlv51 = (int)(10); }
    {int tlv54; tlv54 = (int)(10); }
    {int tlv2; tlv2 = (int)(10); }
    {int tlv3; tlv3 = (int)(10); }
    {char * tlv82; tlv82 = (char *)(10); }
    {char * tlv83; tlv83 = (char *)(10); }
    {char tlv69; tlv69 = (char)(10); }
    {char * tlv58; tlv58 = (char *)(10); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(10); }
    {int tlv59; tlv59 = (int)(10); }
    {char * tlv63; tlv63 = (char *)(10); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(10); }
    {int tlv64; tlv64 = (int)(10); }
    {char * tlv68; tlv68 = (char *)(10); }
    {int tlv67; tlv67 = (int)(10); }
    {int tlv66; tlv66 = (int)(10); }
    {int tlv72; tlv72 = (int)(10); }
    {char * tlv76; tlv76 = (char *)(10); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(10); }
    {int tlv77; tlv77 = (int)(10); }
    {int tlv4; tlv4 = (int)(10); }
    {char tlv79; tlv79 = (char)(10); }
}
void fix_ingred_packet_2_54_2(){
    {char tlv5; tlv5 = (char)(current_encryption); }
    {char tlv7; tlv7 = (char)(current_encryption); }
    {int tlv6; tlv6 = (int)(current_encryption); }
    {char tlv8; tlv8 = (char)(current_encryption); }
    {int rtn; rtn = (int)(current_encryption); }
    {char * tlv9; tlv9 = (char *)(current_encryption); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(current_encryption); }
    {char sideA; sideA = (char)(current_encryption); }
    {char sideB; sideB = (char)(current_encryption); }
    {int indexA; indexA = (int)(current_encryption); }
    {int indexB; indexB = (int)(current_encryption); }
    {int tlv1; tlv1 = (int)(current_encryption); }
    {char * tlv11; tlv11 = (char *)(current_encryption); }
    {void * tlv15; tlv15 = (void *)(current_encryption); }
    {void * tlv14; tlv14 = (void *)(current_encryption); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(current_encryption); }
    {char * tlv18; tlv18 = (char *)(current_encryption); }
    {int tlv17; tlv17 = (int)(current_encryption); }
    {int tlv16; tlv16 = (int)(current_encryption); }
    {int tlv19; tlv19 = (int)(current_encryption); }
    {char tlv21; tlv21 = (char)(current_encryption); }
    {char tlv22; tlv22 = (char)(current_encryption); }
    {char tlv25; tlv25 = (char)(current_encryption); }
    {char tlv23; tlv23 = (char)(current_encryption); }
    {char* t ; t  = (char*)(current_encryption); }
    {char* ss ; ss  = (char*)(current_encryption); }
    {char * tlv27; tlv27 = (char *)(current_encryption); }
    {char * tlv30; tlv30 = (char *)(current_encryption); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(current_encryption); }
    {int tlv31; tlv31 = (int)(current_encryption); }
    {char * tlv35; tlv35 = (char *)(current_encryption); }
    {int tlv34; tlv34 = (int)(current_encryption); }
    {int tlv33; tlv33 = (int)(current_encryption); }
    {void * tlv38; tlv38 = (void *)(current_encryption); }
    {void * tlv37; tlv37 = (void *)(current_encryption); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(current_encryption); }
    {int tlv39; tlv39 = (int)(current_encryption); }
    {void * tlv43; tlv43 = (void *)(current_encryption); }
    {void * tlv42; tlv42 = (void *)(current_encryption); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(current_encryption); }
    {int tlv44; tlv44 = (int)(current_encryption); }
    {char * tlv48; tlv48 = (char *)(current_encryption); }
    {int tlv47; tlv47 = (int)(current_encryption); }
    {int tlv46; tlv46 = (int)(current_encryption); }
    {int tlv49; tlv49 = (int)(current_encryption); }
    {char * tlv53; tlv53 = (char *)(current_encryption); }
    {int tlv52; tlv52 = (int)(current_encryption); }
    {int tlv51; tlv51 = (int)(current_encryption); }
    {int tlv54; tlv54 = (int)(current_encryption); }
    {int tlv2; tlv2 = (int)(current_encryption); }
    {int tlv3; tlv3 = (int)(current_encryption); }
    {char * tlv82; tlv82 = (char *)(current_encryption); }
    {char * tlv83; tlv83 = (char *)(current_encryption); }
    {char tlv69; tlv69 = (char)(current_encryption); }
    {char * tlv58; tlv58 = (char *)(current_encryption); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(current_encryption); }
    {int tlv59; tlv59 = (int)(current_encryption); }
    {char * tlv63; tlv63 = (char *)(current_encryption); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(current_encryption); }
    {int tlv64; tlv64 = (int)(current_encryption); }
    {char * tlv68; tlv68 = (char *)(current_encryption); }
    {int tlv67; tlv67 = (int)(current_encryption); }
    {int tlv66; tlv66 = (int)(current_encryption); }
    {int tlv72; tlv72 = (int)(current_encryption); }
    {char * tlv76; tlv76 = (char *)(current_encryption); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(current_encryption); }
    {int tlv77; tlv77 = (int)(current_encryption); }
    {int tlv4; tlv4 = (int)(current_encryption); }
    {char tlv79; tlv79 = (char)(current_encryption); }
}
void fix_ingred_packet_2_54(){
fix_ingred_packet_2_54_1();
fix_ingred_packet_2_54_2();
}
void fix_ingred_packet_2_59_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char tlv5; tlv5 = (char)(pkt -> length - '0'); }
    {char tlv7; tlv7 = (char)(pkt -> length - '0'); }
    {int tlv6; tlv6 = (int)(pkt -> length - '0'); }
    {char tlv8; tlv8 = (char)(pkt -> length - '0'); }
    {int rtn; rtn = (int)(pkt -> length - '0'); }
    {char * tlv9; tlv9 = (char *)(pkt -> length - '0'); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(pkt -> length - '0'); }
    {char sideA; sideA = (char)(pkt -> length - '0'); }
    {char sideB; sideB = (char)(pkt -> length - '0'); }
    {int indexA; indexA = (int)(pkt -> length - '0'); }
    {int indexB; indexB = (int)(pkt -> length - '0'); }
    {int tlv1; tlv1 = (int)(pkt -> length - '0'); }
    {char * tlv11; tlv11 = (char *)(pkt -> length - '0'); }
    {void * tlv15; tlv15 = (void *)(pkt -> length - '0'); }
    {void * tlv14; tlv14 = (void *)(pkt -> length - '0'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(pkt -> length - '0'); }
    {char * tlv18; tlv18 = (char *)(pkt -> length - '0'); }
    {int tlv17; tlv17 = (int)(pkt -> length - '0'); }
    {int tlv16; tlv16 = (int)(pkt -> length - '0'); }
    {int tlv19; tlv19 = (int)(pkt -> length - '0'); }
    {char tlv21; tlv21 = (char)(pkt -> length - '0'); }
    {char tlv22; tlv22 = (char)(pkt -> length - '0'); }
    {char tlv25; tlv25 = (char)(pkt -> length - '0'); }
    {char tlv23; tlv23 = (char)(pkt -> length - '0'); }
    {char* t ; t  = (char*)(pkt -> length - '0'); }
    {char* ss ; ss  = (char*)(pkt -> length - '0'); }
    {char * tlv27; tlv27 = (char *)(pkt -> length - '0'); }
    {char * tlv30; tlv30 = (char *)(pkt -> length - '0'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(pkt -> length - '0'); }
    {int tlv31; tlv31 = (int)(pkt -> length - '0'); }
    {char * tlv35; tlv35 = (char *)(pkt -> length - '0'); }
    {int tlv34; tlv34 = (int)(pkt -> length - '0'); }
    {int tlv33; tlv33 = (int)(pkt -> length - '0'); }
    {void * tlv38; tlv38 = (void *)(pkt -> length - '0'); }
    {void * tlv37; tlv37 = (void *)(pkt -> length - '0'); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(pkt -> length - '0'); }
    {int tlv39; tlv39 = (int)(pkt -> length - '0'); }
    {void * tlv43; tlv43 = (void *)(pkt -> length - '0'); }
    {void * tlv42; tlv42 = (void *)(pkt -> length - '0'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(pkt -> length - '0'); }
    {int tlv44; tlv44 = (int)(pkt -> length - '0'); }
    {char * tlv48; tlv48 = (char *)(pkt -> length - '0'); }
    {int tlv47; tlv47 = (int)(pkt -> length - '0'); }
    {int tlv46; tlv46 = (int)(pkt -> length - '0'); }
    {int tlv49; tlv49 = (int)(pkt -> length - '0'); }
    {char * tlv53; tlv53 = (char *)(pkt -> length - '0'); }
    {int tlv52; tlv52 = (int)(pkt -> length - '0'); }
    {int tlv51; tlv51 = (int)(pkt -> length - '0'); }
    {int tlv54; tlv54 = (int)(pkt -> length - '0'); }
    {int tlv2; tlv2 = (int)(pkt -> length - '0'); }
    {int tlv3; tlv3 = (int)(pkt -> length - '0'); }
    {char * tlv82; tlv82 = (char *)(pkt -> length - '0'); }
    {char * tlv83; tlv83 = (char *)(pkt -> length - '0'); }
    {char tlv69; tlv69 = (char)(pkt -> length - '0'); }
    {char * tlv58; tlv58 = (char *)(pkt -> length - '0'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(pkt -> length - '0'); }
    {int tlv59; tlv59 = (int)(pkt -> length - '0'); }
    {char * tlv63; tlv63 = (char *)(pkt -> length - '0'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(pkt -> length - '0'); }
    {int tlv64; tlv64 = (int)(pkt -> length - '0'); }
    {char * tlv68; tlv68 = (char *)(pkt -> length - '0'); }
    {int tlv67; tlv67 = (int)(pkt -> length - '0'); }
    {int tlv66; tlv66 = (int)(pkt -> length - '0'); }
    {int tlv72; tlv72 = (int)(pkt -> length - '0'); }
    {char * tlv76; tlv76 = (char *)(pkt -> length - '0'); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(pkt -> length - '0'); }
    {int tlv77; tlv77 = (int)(pkt -> length - '0'); }
    {int tlv4; tlv4 = (int)(pkt -> length - '0'); }
    {char tlv79; tlv79 = (char)(pkt -> length - '0'); }
}
void fix_ingred_packet_2_59_2(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char tlv5; tlv5 = (char)(ENC_ONE); }
    {char tlv7; tlv7 = (char)(ENC_ONE); }
    {int tlv6; tlv6 = (int)(ENC_ONE); }
    {char tlv8; tlv8 = (char)(ENC_ONE); }
    {int rtn; rtn = (int)(ENC_ONE); }
    {char * tlv9; tlv9 = (char *)(ENC_ONE); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(ENC_ONE); }
    {char sideA; sideA = (char)(ENC_ONE); }
    {char sideB; sideB = (char)(ENC_ONE); }
    {int indexA; indexA = (int)(ENC_ONE); }
    {int indexB; indexB = (int)(ENC_ONE); }
    {int tlv1; tlv1 = (int)(ENC_ONE); }
    {char * tlv11; tlv11 = (char *)(ENC_ONE); }
    {void * tlv15; tlv15 = (void *)(ENC_ONE); }
    {void * tlv14; tlv14 = (void *)(ENC_ONE); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ENC_ONE); }
    {char * tlv18; tlv18 = (char *)(ENC_ONE); }
    {int tlv17; tlv17 = (int)(ENC_ONE); }
    {int tlv16; tlv16 = (int)(ENC_ONE); }
    {int tlv19; tlv19 = (int)(ENC_ONE); }
    {char tlv21; tlv21 = (char)(ENC_ONE); }
    {char tlv22; tlv22 = (char)(ENC_ONE); }
    {char tlv25; tlv25 = (char)(ENC_ONE); }
    {char tlv23; tlv23 = (char)(ENC_ONE); }
    {char* t ; t  = (char*)(ENC_ONE); }
    {char* ss ; ss  = (char*)(ENC_ONE); }
    {char * tlv27; tlv27 = (char *)(ENC_ONE); }
    {char * tlv30; tlv30 = (char *)(ENC_ONE); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ENC_ONE); }
    {int tlv31; tlv31 = (int)(ENC_ONE); }
    {char * tlv35; tlv35 = (char *)(ENC_ONE); }
    {int tlv34; tlv34 = (int)(ENC_ONE); }
    {int tlv33; tlv33 = (int)(ENC_ONE); }
    {void * tlv38; tlv38 = (void *)(ENC_ONE); }
    {void * tlv37; tlv37 = (void *)(ENC_ONE); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(ENC_ONE); }
    {int tlv39; tlv39 = (int)(ENC_ONE); }
    {void * tlv43; tlv43 = (void *)(ENC_ONE); }
    {void * tlv42; tlv42 = (void *)(ENC_ONE); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(ENC_ONE); }
    {int tlv44; tlv44 = (int)(ENC_ONE); }
    {char * tlv48; tlv48 = (char *)(ENC_ONE); }
    {int tlv47; tlv47 = (int)(ENC_ONE); }
    {int tlv46; tlv46 = (int)(ENC_ONE); }
    {int tlv49; tlv49 = (int)(ENC_ONE); }
    {char * tlv53; tlv53 = (char *)(ENC_ONE); }
    {int tlv52; tlv52 = (int)(ENC_ONE); }
    {int tlv51; tlv51 = (int)(ENC_ONE); }
    {int tlv54; tlv54 = (int)(ENC_ONE); }
    {int tlv2; tlv2 = (int)(ENC_ONE); }
    {int tlv3; tlv3 = (int)(ENC_ONE); }
    {char * tlv82; tlv82 = (char *)(ENC_ONE); }
    {char * tlv83; tlv83 = (char *)(ENC_ONE); }
    {char tlv69; tlv69 = (char)(ENC_ONE); }
    {char * tlv58; tlv58 = (char *)(ENC_ONE); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(ENC_ONE); }
    {int tlv59; tlv59 = (int)(ENC_ONE); }
    {char * tlv63; tlv63 = (char *)(ENC_ONE); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ENC_ONE); }
    {int tlv64; tlv64 = (int)(ENC_ONE); }
    {char * tlv68; tlv68 = (char *)(ENC_ONE); }
    {int tlv67; tlv67 = (int)(ENC_ONE); }
    {int tlv66; tlv66 = (int)(ENC_ONE); }
    {int tlv72; tlv72 = (int)(ENC_ONE); }
    {char * tlv76; tlv76 = (char *)(ENC_ONE); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(ENC_ONE); }
    {int tlv77; tlv77 = (int)(ENC_ONE); }
    {int tlv4; tlv4 = (int)(ENC_ONE); }
    {char tlv79; tlv79 = (char)(ENC_ONE); }
}
void fix_ingred_packet_2_59(){
fix_ingred_packet_2_59_1();
fix_ingred_packet_2_59_2();
}
void fix_ingred_packet_2_62_2(){
    {char tlv5; tlv5 = (char)(ENC_TWO); }
    {char tlv7; tlv7 = (char)(ENC_TWO); }
    {int tlv6; tlv6 = (int)(ENC_TWO); }
    {char tlv8; tlv8 = (char)(ENC_TWO); }
    {int rtn; rtn = (int)(ENC_TWO); }
    {char * tlv9; tlv9 = (char *)(ENC_TWO); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(ENC_TWO); }
    {char sideA; sideA = (char)(ENC_TWO); }
    {char sideB; sideB = (char)(ENC_TWO); }
    {int indexA; indexA = (int)(ENC_TWO); }
    {int indexB; indexB = (int)(ENC_TWO); }
    {int tlv1; tlv1 = (int)(ENC_TWO); }
    {char * tlv11; tlv11 = (char *)(ENC_TWO); }
    {void * tlv15; tlv15 = (void *)(ENC_TWO); }
    {void * tlv14; tlv14 = (void *)(ENC_TWO); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(ENC_TWO); }
    {char * tlv18; tlv18 = (char *)(ENC_TWO); }
    {int tlv17; tlv17 = (int)(ENC_TWO); }
    {int tlv16; tlv16 = (int)(ENC_TWO); }
    {int tlv19; tlv19 = (int)(ENC_TWO); }
    {char tlv21; tlv21 = (char)(ENC_TWO); }
    {char tlv22; tlv22 = (char)(ENC_TWO); }
    {char tlv25; tlv25 = (char)(ENC_TWO); }
    {char tlv23; tlv23 = (char)(ENC_TWO); }
    {char* t ; t  = (char*)(ENC_TWO); }
    {char* ss ; ss  = (char*)(ENC_TWO); }
    {char * tlv27; tlv27 = (char *)(ENC_TWO); }
    {char * tlv30; tlv30 = (char *)(ENC_TWO); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(ENC_TWO); }
    {int tlv31; tlv31 = (int)(ENC_TWO); }
    {char * tlv35; tlv35 = (char *)(ENC_TWO); }
    {int tlv34; tlv34 = (int)(ENC_TWO); }
    {int tlv33; tlv33 = (int)(ENC_TWO); }
    {void * tlv38; tlv38 = (void *)(ENC_TWO); }
    {void * tlv37; tlv37 = (void *)(ENC_TWO); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(ENC_TWO); }
    {int tlv39; tlv39 = (int)(ENC_TWO); }
    {void * tlv43; tlv43 = (void *)(ENC_TWO); }
    {void * tlv42; tlv42 = (void *)(ENC_TWO); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(ENC_TWO); }
    {int tlv44; tlv44 = (int)(ENC_TWO); }
    {char * tlv48; tlv48 = (char *)(ENC_TWO); }
    {int tlv47; tlv47 = (int)(ENC_TWO); }
    {int tlv46; tlv46 = (int)(ENC_TWO); }
    {int tlv49; tlv49 = (int)(ENC_TWO); }
    {char * tlv53; tlv53 = (char *)(ENC_TWO); }
    {int tlv52; tlv52 = (int)(ENC_TWO); }
    {int tlv51; tlv51 = (int)(ENC_TWO); }
    {int tlv54; tlv54 = (int)(ENC_TWO); }
    {int tlv2; tlv2 = (int)(ENC_TWO); }
    {int tlv3; tlv3 = (int)(ENC_TWO); }
    {char * tlv82; tlv82 = (char *)(ENC_TWO); }
    {char * tlv83; tlv83 = (char *)(ENC_TWO); }
    {char tlv69; tlv69 = (char)(ENC_TWO); }
    {char * tlv58; tlv58 = (char *)(ENC_TWO); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(ENC_TWO); }
    {int tlv59; tlv59 = (int)(ENC_TWO); }
    {char * tlv63; tlv63 = (char *)(ENC_TWO); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(ENC_TWO); }
    {int tlv64; tlv64 = (int)(ENC_TWO); }
    {char * tlv68; tlv68 = (char *)(ENC_TWO); }
    {int tlv67; tlv67 = (int)(ENC_TWO); }
    {int tlv66; tlv66 = (int)(ENC_TWO); }
    {int tlv72; tlv72 = (int)(ENC_TWO); }
    {char * tlv76; tlv76 = (char *)(ENC_TWO); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(ENC_TWO); }
    {int tlv77; tlv77 = (int)(ENC_TWO); }
    {int tlv4; tlv4 = (int)(ENC_TWO); }
    {char tlv79; tlv79 = (char)(ENC_TWO); }
}
void fix_ingred_packet_2_62(){
fix_ingred_packet_2_62_2();
}
void fix_ingred_packet_2_66_2(){
    {char tlv5; tlv5 = (char)(6); }
    {char tlv7; tlv7 = (char)(6); }
    {int tlv6; tlv6 = (int)(6); }
    {char tlv8; tlv8 = (char)(6); }
    {int rtn; rtn = (int)(6); }
    {char * tlv9; tlv9 = (char *)(6); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(6); }
    {char sideA; sideA = (char)(6); }
    {char sideB; sideB = (char)(6); }
    {int indexA; indexA = (int)(6); }
    {int indexB; indexB = (int)(6); }
    {int tlv1; tlv1 = (int)(6); }
    {char * tlv11; tlv11 = (char *)(6); }
    {void * tlv15; tlv15 = (void *)(6); }
    {void * tlv14; tlv14 = (void *)(6); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(6); }
    {char * tlv18; tlv18 = (char *)(6); }
    {int tlv17; tlv17 = (int)(6); }
    {int tlv16; tlv16 = (int)(6); }
    {int tlv19; tlv19 = (int)(6); }
    {char tlv21; tlv21 = (char)(6); }
    {char tlv22; tlv22 = (char)(6); }
    {char tlv25; tlv25 = (char)(6); }
    {char tlv23; tlv23 = (char)(6); }
    {char* t ; t  = (char*)(6); }
    {char* ss ; ss  = (char*)(6); }
    {char * tlv27; tlv27 = (char *)(6); }
    {char * tlv30; tlv30 = (char *)(6); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(6); }
    {int tlv31; tlv31 = (int)(6); }
    {char * tlv35; tlv35 = (char *)(6); }
    {int tlv34; tlv34 = (int)(6); }
    {int tlv33; tlv33 = (int)(6); }
    {void * tlv38; tlv38 = (void *)(6); }
    {void * tlv37; tlv37 = (void *)(6); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(6); }
    {int tlv39; tlv39 = (int)(6); }
    {void * tlv43; tlv43 = (void *)(6); }
    {void * tlv42; tlv42 = (void *)(6); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(6); }
    {int tlv44; tlv44 = (int)(6); }
    {char * tlv48; tlv48 = (char *)(6); }
    {int tlv47; tlv47 = (int)(6); }
    {int tlv46; tlv46 = (int)(6); }
    {int tlv49; tlv49 = (int)(6); }
    {char * tlv53; tlv53 = (char *)(6); }
    {int tlv52; tlv52 = (int)(6); }
    {int tlv51; tlv51 = (int)(6); }
    {int tlv54; tlv54 = (int)(6); }
    {int tlv2; tlv2 = (int)(6); }
    {int tlv3; tlv3 = (int)(6); }
    {char * tlv82; tlv82 = (char *)(6); }
    {char * tlv83; tlv83 = (char *)(6); }
    {char tlv69; tlv69 = (char)(6); }
    {char * tlv58; tlv58 = (char *)(6); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(6); }
    {int tlv59; tlv59 = (int)(6); }
    {char * tlv63; tlv63 = (char *)(6); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(6); }
    {int tlv64; tlv64 = (int)(6); }
    {char * tlv68; tlv68 = (char *)(6); }
    {int tlv67; tlv67 = (int)(6); }
    {int tlv66; tlv66 = (int)(6); }
    {int tlv72; tlv72 = (int)(6); }
    {char * tlv76; tlv76 = (char *)(6); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(6); }
    {int tlv77; tlv77 = (int)(6); }
    {int tlv4; tlv4 = (int)(6); }
    {char tlv79; tlv79 = (char)(6); }
}
void fix_ingred_packet_2_66(){
fix_ingred_packet_2_66_2();
}
void fix_ingred_packet_2_67_1(){
    {char tlv5; tlv5 = (char)(6); }
    {char tlv7; tlv7 = (char)(6); }
    {int tlv6; tlv6 = (int)(6); }
    {char tlv8; tlv8 = (char)(6); }
    {int rtn; rtn = (int)(6); }
    {char * tlv9; tlv9 = (char *)(6); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(6); }
    {char sideA; sideA = (char)(6); }
    {char sideB; sideB = (char)(6); }
    {int indexA; indexA = (int)(6); }
    {int indexB; indexB = (int)(6); }
    {int tlv1; tlv1 = (int)(6); }
    {char * tlv11; tlv11 = (char *)(6); }
    {void * tlv15; tlv15 = (void *)(6); }
    {void * tlv14; tlv14 = (void *)(6); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(6); }
    {char * tlv18; tlv18 = (char *)(6); }
    {int tlv17; tlv17 = (int)(6); }
    {int tlv16; tlv16 = (int)(6); }
    {int tlv19; tlv19 = (int)(6); }
    {char tlv21; tlv21 = (char)(6); }
    {char tlv22; tlv22 = (char)(6); }
    {char tlv25; tlv25 = (char)(6); }
    {char tlv23; tlv23 = (char)(6); }
    {char* t ; t  = (char*)(6); }
    {char* ss ; ss  = (char*)(6); }
    {char * tlv27; tlv27 = (char *)(6); }
    {char * tlv30; tlv30 = (char *)(6); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(6); }
    {int tlv31; tlv31 = (int)(6); }
    {char * tlv35; tlv35 = (char *)(6); }
    {int tlv34; tlv34 = (int)(6); }
    {int tlv33; tlv33 = (int)(6); }
    {void * tlv38; tlv38 = (void *)(6); }
    {void * tlv37; tlv37 = (void *)(6); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(6); }
    {int tlv39; tlv39 = (int)(6); }
    {void * tlv43; tlv43 = (void *)(6); }
    {void * tlv42; tlv42 = (void *)(6); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(6); }
    {int tlv44; tlv44 = (int)(6); }
    {char * tlv48; tlv48 = (char *)(6); }
    {int tlv47; tlv47 = (int)(6); }
    {int tlv46; tlv46 = (int)(6); }
    {int tlv49; tlv49 = (int)(6); }
    {char * tlv53; tlv53 = (char *)(6); }
    {int tlv52; tlv52 = (int)(6); }
    {int tlv51; tlv51 = (int)(6); }
    {int tlv54; tlv54 = (int)(6); }
    {int tlv2; tlv2 = (int)(6); }
    {int tlv3; tlv3 = (int)(6); }
    {char * tlv82; tlv82 = (char *)(6); }
    {char * tlv83; tlv83 = (char *)(6); }
    {char tlv69; tlv69 = (char)(6); }
    {char * tlv58; tlv58 = (char *)(6); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(6); }
    {int tlv59; tlv59 = (int)(6); }
    {char * tlv63; tlv63 = (char *)(6); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(6); }
    {int tlv64; tlv64 = (int)(6); }
    {char * tlv68; tlv68 = (char *)(6); }
    {int tlv67; tlv67 = (int)(6); }
    {int tlv66; tlv66 = (int)(6); }
    {int tlv72; tlv72 = (int)(6); }
    {char * tlv76; tlv76 = (char *)(6); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(6); }
    {int tlv77; tlv77 = (int)(6); }
    {int tlv4; tlv4 = (int)(6); }
    {char tlv79; tlv79 = (char)(6); }
}
void fix_ingred_packet_2_67(){
fix_ingred_packet_2_67_1();
}
void fix_ingred_packet_2_69_6(){
int indexA;
    bzero(&indexA,sizeof(int));
    {char tlv5; tlv5 = (char)(indexA); }
    {char tlv7; tlv7 = (char)(indexA); }
    {int tlv6; tlv6 = (int)(indexA); }
    {char tlv8; tlv8 = (char)(indexA); }
    {int rtn; rtn = (int)(indexA); }
    {char * tlv9; tlv9 = (char *)(indexA); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(indexA); }
    {char sideA; sideA = (char)(indexA); }
    {char sideB; sideB = (char)(indexA); }
    {int indexB; indexB = (int)(indexA); }
    {int tlv1; tlv1 = (int)(indexA); }
    {char * tlv11; tlv11 = (char *)(indexA); }
    {void * tlv15; tlv15 = (void *)(indexA); }
    {void * tlv14; tlv14 = (void *)(indexA); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(indexA); }
    {char * tlv18; tlv18 = (char *)(indexA); }
    {int tlv17; tlv17 = (int)(indexA); }
    {int tlv16; tlv16 = (int)(indexA); }
    {int tlv19; tlv19 = (int)(indexA); }
    {char tlv21; tlv21 = (char)(indexA); }
    {char tlv22; tlv22 = (char)(indexA); }
    {char tlv25; tlv25 = (char)(indexA); }
    {char tlv23; tlv23 = (char)(indexA); }
    {char* t ; t  = (char*)(indexA); }
    {char* ss ; ss  = (char*)(indexA); }
    {char * tlv27; tlv27 = (char *)(indexA); }
    {char * tlv30; tlv30 = (char *)(indexA); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(indexA); }
    {int tlv31; tlv31 = (int)(indexA); }
    {char * tlv35; tlv35 = (char *)(indexA); }
    {int tlv34; tlv34 = (int)(indexA); }
    {int tlv33; tlv33 = (int)(indexA); }
    {void * tlv38; tlv38 = (void *)(indexA); }
    {void * tlv37; tlv37 = (void *)(indexA); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(indexA); }
    {int tlv39; tlv39 = (int)(indexA); }
    {void * tlv43; tlv43 = (void *)(indexA); }
    {void * tlv42; tlv42 = (void *)(indexA); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(indexA); }
    {int tlv44; tlv44 = (int)(indexA); }
    {char * tlv48; tlv48 = (char *)(indexA); }
    {int tlv47; tlv47 = (int)(indexA); }
    {int tlv46; tlv46 = (int)(indexA); }
    {int tlv49; tlv49 = (int)(indexA); }
    {char * tlv53; tlv53 = (char *)(indexA); }
    {int tlv52; tlv52 = (int)(indexA); }
    {int tlv51; tlv51 = (int)(indexA); }
    {int tlv54; tlv54 = (int)(indexA); }
    {int tlv2; tlv2 = (int)(indexA); }
    {int tlv3; tlv3 = (int)(indexA); }
    {char * tlv82; tlv82 = (char *)(indexA); }
    {char * tlv83; tlv83 = (char *)(indexA); }
    {char tlv69; tlv69 = (char)(indexA); }
    {char * tlv58; tlv58 = (char *)(indexA); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(indexA); }
    {int tlv59; tlv59 = (int)(indexA); }
    {char * tlv63; tlv63 = (char *)(indexA); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(indexA); }
    {int tlv64; tlv64 = (int)(indexA); }
    {char * tlv68; tlv68 = (char *)(indexA); }
    {int tlv67; tlv67 = (int)(indexA); }
    {int tlv66; tlv66 = (int)(indexA); }
    {int tlv72; tlv72 = (int)(indexA); }
    {char * tlv76; tlv76 = (char *)(indexA); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(indexA); }
    {int tlv77; tlv77 = (int)(indexA); }
    {int tlv4; tlv4 = (int)(indexA); }
    {char tlv79; tlv79 = (char)(indexA); }
}
void fix_ingred_packet_2_69_7(){
int indexA;
    bzero(&indexA,sizeof(int));
    {char tlv5; tlv5 = (char)(- 1); }
    {char tlv7; tlv7 = (char)(- 1); }
    {int tlv6; tlv6 = (int)(- 1); }
    {char tlv8; tlv8 = (char)(- 1); }
    {int rtn; rtn = (int)(- 1); }
    {char * tlv9; tlv9 = (char *)(- 1); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(- 1); }
    {char sideA; sideA = (char)(- 1); }
    {char sideB; sideB = (char)(- 1); }
    {int indexA; indexA = (int)(- 1); }
    {int indexB; indexB = (int)(- 1); }
    {int tlv1; tlv1 = (int)(- 1); }
    {char * tlv11; tlv11 = (char *)(- 1); }
    {void * tlv15; tlv15 = (void *)(- 1); }
    {void * tlv14; tlv14 = (void *)(- 1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(- 1); }
    {char * tlv18; tlv18 = (char *)(- 1); }
    {int tlv17; tlv17 = (int)(- 1); }
    {int tlv16; tlv16 = (int)(- 1); }
    {int tlv19; tlv19 = (int)(- 1); }
    {char tlv21; tlv21 = (char)(- 1); }
    {char tlv22; tlv22 = (char)(- 1); }
    {char tlv25; tlv25 = (char)(- 1); }
    {char tlv23; tlv23 = (char)(- 1); }
    {char* t ; t  = (char*)(- 1); }
    {char* ss ; ss  = (char*)(- 1); }
    {char * tlv27; tlv27 = (char *)(- 1); }
    {char * tlv30; tlv30 = (char *)(- 1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(- 1); }
    {int tlv31; tlv31 = (int)(- 1); }
    {char * tlv35; tlv35 = (char *)(- 1); }
    {int tlv34; tlv34 = (int)(- 1); }
    {int tlv33; tlv33 = (int)(- 1); }
    {void * tlv38; tlv38 = (void *)(- 1); }
    {void * tlv37; tlv37 = (void *)(- 1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(- 1); }
    {int tlv39; tlv39 = (int)(- 1); }
    {void * tlv43; tlv43 = (void *)(- 1); }
    {void * tlv42; tlv42 = (void *)(- 1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(- 1); }
    {int tlv44; tlv44 = (int)(- 1); }
    {char * tlv48; tlv48 = (char *)(- 1); }
    {int tlv47; tlv47 = (int)(- 1); }
    {int tlv46; tlv46 = (int)(- 1); }
    {int tlv49; tlv49 = (int)(- 1); }
    {char * tlv53; tlv53 = (char *)(- 1); }
    {int tlv52; tlv52 = (int)(- 1); }
    {int tlv51; tlv51 = (int)(- 1); }
    {int tlv54; tlv54 = (int)(- 1); }
    {int tlv2; tlv2 = (int)(- 1); }
    {int tlv3; tlv3 = (int)(- 1); }
    {char * tlv82; tlv82 = (char *)(- 1); }
    {char * tlv83; tlv83 = (char *)(- 1); }
    {char tlv69; tlv69 = (char)(- 1); }
    {char * tlv58; tlv58 = (char *)(- 1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(- 1); }
    {int tlv59; tlv59 = (int)(- 1); }
    {char * tlv63; tlv63 = (char *)(- 1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(- 1); }
    {int tlv64; tlv64 = (int)(- 1); }
    {char * tlv68; tlv68 = (char *)(- 1); }
    {int tlv67; tlv67 = (int)(- 1); }
    {int tlv66; tlv66 = (int)(- 1); }
    {int tlv72; tlv72 = (int)(- 1); }
    {char * tlv76; tlv76 = (char *)(- 1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(- 1); }
    {int tlv77; tlv77 = (int)(- 1); }
    {int tlv4; tlv4 = (int)(- 1); }
    {char tlv79; tlv79 = (char)(- 1); }
}
void fix_ingred_packet_2_69(){
fix_ingred_packet_2_69_6();
fix_ingred_packet_2_69_7();
}
void fix_ingred_packet_2_71_6(){
int indexB;
    bzero(&indexB,sizeof(int));
    {char tlv5; tlv5 = (char)(indexB); }
    {char tlv7; tlv7 = (char)(indexB); }
    {int tlv6; tlv6 = (int)(indexB); }
    {char tlv8; tlv8 = (char)(indexB); }
    {int rtn; rtn = (int)(indexB); }
    {char * tlv9; tlv9 = (char *)(indexB); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(indexB); }
    {char sideA; sideA = (char)(indexB); }
    {char sideB; sideB = (char)(indexB); }
    {int indexA; indexA = (int)(indexB); }
    {int tlv1; tlv1 = (int)(indexB); }
    {char * tlv11; tlv11 = (char *)(indexB); }
    {void * tlv15; tlv15 = (void *)(indexB); }
    {void * tlv14; tlv14 = (void *)(indexB); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(indexB); }
    {char * tlv18; tlv18 = (char *)(indexB); }
    {int tlv17; tlv17 = (int)(indexB); }
    {int tlv16; tlv16 = (int)(indexB); }
    {int tlv19; tlv19 = (int)(indexB); }
    {char tlv21; tlv21 = (char)(indexB); }
    {char tlv22; tlv22 = (char)(indexB); }
    {char tlv25; tlv25 = (char)(indexB); }
    {char tlv23; tlv23 = (char)(indexB); }
    {char* t ; t  = (char*)(indexB); }
    {char* ss ; ss  = (char*)(indexB); }
    {char * tlv27; tlv27 = (char *)(indexB); }
    {char * tlv30; tlv30 = (char *)(indexB); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(indexB); }
    {int tlv31; tlv31 = (int)(indexB); }
    {char * tlv35; tlv35 = (char *)(indexB); }
    {int tlv34; tlv34 = (int)(indexB); }
    {int tlv33; tlv33 = (int)(indexB); }
    {void * tlv38; tlv38 = (void *)(indexB); }
    {void * tlv37; tlv37 = (void *)(indexB); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(indexB); }
    {int tlv39; tlv39 = (int)(indexB); }
    {void * tlv43; tlv43 = (void *)(indexB); }
    {void * tlv42; tlv42 = (void *)(indexB); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(indexB); }
    {int tlv44; tlv44 = (int)(indexB); }
    {char * tlv48; tlv48 = (char *)(indexB); }
    {int tlv47; tlv47 = (int)(indexB); }
    {int tlv46; tlv46 = (int)(indexB); }
    {int tlv49; tlv49 = (int)(indexB); }
    {char * tlv53; tlv53 = (char *)(indexB); }
    {int tlv52; tlv52 = (int)(indexB); }
    {int tlv51; tlv51 = (int)(indexB); }
    {int tlv54; tlv54 = (int)(indexB); }
    {int tlv2; tlv2 = (int)(indexB); }
    {int tlv3; tlv3 = (int)(indexB); }
    {char * tlv82; tlv82 = (char *)(indexB); }
    {char * tlv83; tlv83 = (char *)(indexB); }
    {char tlv69; tlv69 = (char)(indexB); }
    {char * tlv58; tlv58 = (char *)(indexB); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(indexB); }
    {int tlv59; tlv59 = (int)(indexB); }
    {char * tlv63; tlv63 = (char *)(indexB); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(indexB); }
    {int tlv64; tlv64 = (int)(indexB); }
    {char * tlv68; tlv68 = (char *)(indexB); }
    {int tlv67; tlv67 = (int)(indexB); }
    {int tlv66; tlv66 = (int)(indexB); }
    {int tlv72; tlv72 = (int)(indexB); }
    {char * tlv76; tlv76 = (char *)(indexB); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(indexB); }
    {int tlv77; tlv77 = (int)(indexB); }
    {int tlv4; tlv4 = (int)(indexB); }
    {char tlv79; tlv79 = (char)(indexB); }
}
void fix_ingred_packet_2_71(){
fix_ingred_packet_2_71_6();
}
void fix_ingred_packet_2_72_1(){
char sideA;
    bzero(&sideA,sizeof(char));
char sideB;
    bzero(&sideB,sizeof(char));
    {char tlv5; tlv5 = (char)(sideA - '0'); }
    {char tlv7; tlv7 = (char)(sideA - '0'); }
    {int tlv6; tlv6 = (int)(sideA - '0'); }
    {char tlv8; tlv8 = (char)(sideA - '0'); }
    {int rtn; rtn = (int)(sideA - '0'); }
    {char * tlv9; tlv9 = (char *)(sideA - '0'); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(sideA - '0'); }
    {char sideB; sideB = (char)(sideA - '0'); }
    {int indexA; indexA = (int)(sideA - '0'); }
    {int indexB; indexB = (int)(sideA - '0'); }
    {int tlv1; tlv1 = (int)(sideA - '0'); }
    {char * tlv11; tlv11 = (char *)(sideA - '0'); }
    {void * tlv15; tlv15 = (void *)(sideA - '0'); }
    {void * tlv14; tlv14 = (void *)(sideA - '0'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sideA - '0'); }
    {char * tlv18; tlv18 = (char *)(sideA - '0'); }
    {int tlv17; tlv17 = (int)(sideA - '0'); }
    {int tlv16; tlv16 = (int)(sideA - '0'); }
    {int tlv19; tlv19 = (int)(sideA - '0'); }
    {char tlv21; tlv21 = (char)(sideA - '0'); }
    {char tlv22; tlv22 = (char)(sideA - '0'); }
    {char tlv25; tlv25 = (char)(sideA - '0'); }
    {char tlv23; tlv23 = (char)(sideA - '0'); }
    {char* t ; t  = (char*)(sideA - '0'); }
    {char* ss ; ss  = (char*)(sideA - '0'); }
    {char * tlv27; tlv27 = (char *)(sideA - '0'); }
    {char * tlv30; tlv30 = (char *)(sideA - '0'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sideA - '0'); }
    {int tlv31; tlv31 = (int)(sideA - '0'); }
    {char * tlv35; tlv35 = (char *)(sideA - '0'); }
    {int tlv34; tlv34 = (int)(sideA - '0'); }
    {int tlv33; tlv33 = (int)(sideA - '0'); }
    {void * tlv38; tlv38 = (void *)(sideA - '0'); }
    {void * tlv37; tlv37 = (void *)(sideA - '0'); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sideA - '0'); }
    {int tlv39; tlv39 = (int)(sideA - '0'); }
    {void * tlv43; tlv43 = (void *)(sideA - '0'); }
    {void * tlv42; tlv42 = (void *)(sideA - '0'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sideA - '0'); }
    {int tlv44; tlv44 = (int)(sideA - '0'); }
    {char * tlv48; tlv48 = (char *)(sideA - '0'); }
    {int tlv47; tlv47 = (int)(sideA - '0'); }
    {int tlv46; tlv46 = (int)(sideA - '0'); }
    {int tlv49; tlv49 = (int)(sideA - '0'); }
    {char * tlv53; tlv53 = (char *)(sideA - '0'); }
    {int tlv52; tlv52 = (int)(sideA - '0'); }
    {int tlv51; tlv51 = (int)(sideA - '0'); }
    {int tlv54; tlv54 = (int)(sideA - '0'); }
    {int tlv2; tlv2 = (int)(sideA - '0'); }
    {int tlv3; tlv3 = (int)(sideA - '0'); }
    {char * tlv82; tlv82 = (char *)(sideA - '0'); }
    {char * tlv83; tlv83 = (char *)(sideA - '0'); }
    {char tlv69; tlv69 = (char)(sideA - '0'); }
    {char * tlv58; tlv58 = (char *)(sideA - '0'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(sideA - '0'); }
    {int tlv59; tlv59 = (int)(sideA - '0'); }
    {char * tlv63; tlv63 = (char *)(sideA - '0'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(sideA - '0'); }
    {int tlv64; tlv64 = (int)(sideA - '0'); }
    {char * tlv68; tlv68 = (char *)(sideA - '0'); }
    {int tlv67; tlv67 = (int)(sideA - '0'); }
    {int tlv66; tlv66 = (int)(sideA - '0'); }
    {int tlv72; tlv72 = (int)(sideA - '0'); }
    {char * tlv76; tlv76 = (char *)(sideA - '0'); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sideA - '0'); }
    {int tlv77; tlv77 = (int)(sideA - '0'); }
    {int tlv4; tlv4 = (int)(sideA - '0'); }
    {char tlv79; tlv79 = (char)(sideA - '0'); }
}
void fix_ingred_packet_2_72_3(){
char sideA;
    bzero(&sideA,sizeof(char));
char sideB;
    bzero(&sideB,sizeof(char));
    {char tlv5; tlv5 = (char)(sideB - '0'); }
    {char tlv7; tlv7 = (char)(sideB - '0'); }
    {int tlv6; tlv6 = (int)(sideB - '0'); }
    {char tlv8; tlv8 = (char)(sideB - '0'); }
    {int rtn; rtn = (int)(sideB - '0'); }
    {char * tlv9; tlv9 = (char *)(sideB - '0'); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(sideB - '0'); }
    {char sideA; sideA = (char)(sideB - '0'); }
    {int indexA; indexA = (int)(sideB - '0'); }
    {int indexB; indexB = (int)(sideB - '0'); }
    {int tlv1; tlv1 = (int)(sideB - '0'); }
    {char * tlv11; tlv11 = (char *)(sideB - '0'); }
    {void * tlv15; tlv15 = (void *)(sideB - '0'); }
    {void * tlv14; tlv14 = (void *)(sideB - '0'); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(sideB - '0'); }
    {char * tlv18; tlv18 = (char *)(sideB - '0'); }
    {int tlv17; tlv17 = (int)(sideB - '0'); }
    {int tlv16; tlv16 = (int)(sideB - '0'); }
    {int tlv19; tlv19 = (int)(sideB - '0'); }
    {char tlv21; tlv21 = (char)(sideB - '0'); }
    {char tlv22; tlv22 = (char)(sideB - '0'); }
    {char tlv25; tlv25 = (char)(sideB - '0'); }
    {char tlv23; tlv23 = (char)(sideB - '0'); }
    {char* t ; t  = (char*)(sideB - '0'); }
    {char* ss ; ss  = (char*)(sideB - '0'); }
    {char * tlv27; tlv27 = (char *)(sideB - '0'); }
    {char * tlv30; tlv30 = (char *)(sideB - '0'); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(sideB - '0'); }
    {int tlv31; tlv31 = (int)(sideB - '0'); }
    {char * tlv35; tlv35 = (char *)(sideB - '0'); }
    {int tlv34; tlv34 = (int)(sideB - '0'); }
    {int tlv33; tlv33 = (int)(sideB - '0'); }
    {void * tlv38; tlv38 = (void *)(sideB - '0'); }
    {void * tlv37; tlv37 = (void *)(sideB - '0'); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(sideB - '0'); }
    {int tlv39; tlv39 = (int)(sideB - '0'); }
    {void * tlv43; tlv43 = (void *)(sideB - '0'); }
    {void * tlv42; tlv42 = (void *)(sideB - '0'); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(sideB - '0'); }
    {int tlv44; tlv44 = (int)(sideB - '0'); }
    {char * tlv48; tlv48 = (char *)(sideB - '0'); }
    {int tlv47; tlv47 = (int)(sideB - '0'); }
    {int tlv46; tlv46 = (int)(sideB - '0'); }
    {int tlv49; tlv49 = (int)(sideB - '0'); }
    {char * tlv53; tlv53 = (char *)(sideB - '0'); }
    {int tlv52; tlv52 = (int)(sideB - '0'); }
    {int tlv51; tlv51 = (int)(sideB - '0'); }
    {int tlv54; tlv54 = (int)(sideB - '0'); }
    {int tlv2; tlv2 = (int)(sideB - '0'); }
    {int tlv3; tlv3 = (int)(sideB - '0'); }
    {char * tlv82; tlv82 = (char *)(sideB - '0'); }
    {char * tlv83; tlv83 = (char *)(sideB - '0'); }
    {char tlv69; tlv69 = (char)(sideB - '0'); }
    {char * tlv58; tlv58 = (char *)(sideB - '0'); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(sideB - '0'); }
    {int tlv59; tlv59 = (int)(sideB - '0'); }
    {char * tlv63; tlv63 = (char *)(sideB - '0'); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(sideB - '0'); }
    {int tlv64; tlv64 = (int)(sideB - '0'); }
    {char * tlv68; tlv68 = (char *)(sideB - '0'); }
    {int tlv67; tlv67 = (int)(sideB - '0'); }
    {int tlv66; tlv66 = (int)(sideB - '0'); }
    {int tlv72; tlv72 = (int)(sideB - '0'); }
    {char * tlv76; tlv76 = (char *)(sideB - '0'); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(sideB - '0'); }
    {int tlv77; tlv77 = (int)(sideB - '0'); }
    {int tlv4; tlv4 = (int)(sideB - '0'); }
    {char tlv79; tlv79 = (char)(sideB - '0'); }
}
void fix_ingred_packet_2_72(){
fix_ingred_packet_2_72_1();
fix_ingred_packet_2_72_3();
}
void fix_ingred_packet_2_73_8(){
int tlv1;
    bzero(&tlv1,sizeof(int));
    {char tlv5; tlv5 = (char)(tlv1); }
    {char tlv7; tlv7 = (char)(tlv1); }
    {int tlv6; tlv6 = (int)(tlv1); }
    {char tlv8; tlv8 = (char)(tlv1); }
    {int rtn; rtn = (int)(tlv1); }
    {char * tlv9; tlv9 = (char *)(tlv1); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tlv1); }
    {char sideA; sideA = (char)(tlv1); }
    {char sideB; sideB = (char)(tlv1); }
    {int indexA; indexA = (int)(tlv1); }
    {int indexB; indexB = (int)(tlv1); }
    {char * tlv11; tlv11 = (char *)(tlv1); }
    {void * tlv15; tlv15 = (void *)(tlv1); }
    {void * tlv14; tlv14 = (void *)(tlv1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv1); }
    {char * tlv18; tlv18 = (char *)(tlv1); }
    {int tlv17; tlv17 = (int)(tlv1); }
    {int tlv16; tlv16 = (int)(tlv1); }
    {int tlv19; tlv19 = (int)(tlv1); }
    {char tlv21; tlv21 = (char)(tlv1); }
    {char tlv22; tlv22 = (char)(tlv1); }
    {char tlv25; tlv25 = (char)(tlv1); }
    {char tlv23; tlv23 = (char)(tlv1); }
    {char* t ; t  = (char*)(tlv1); }
    {char* ss ; ss  = (char*)(tlv1); }
    {char * tlv27; tlv27 = (char *)(tlv1); }
    {char * tlv30; tlv30 = (char *)(tlv1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv1); }
    {int tlv31; tlv31 = (int)(tlv1); }
    {char * tlv35; tlv35 = (char *)(tlv1); }
    {int tlv34; tlv34 = (int)(tlv1); }
    {int tlv33; tlv33 = (int)(tlv1); }
    {void * tlv38; tlv38 = (void *)(tlv1); }
    {void * tlv37; tlv37 = (void *)(tlv1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv1); }
    {int tlv39; tlv39 = (int)(tlv1); }
    {void * tlv43; tlv43 = (void *)(tlv1); }
    {void * tlv42; tlv42 = (void *)(tlv1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tlv1); }
    {int tlv44; tlv44 = (int)(tlv1); }
    {char * tlv48; tlv48 = (char *)(tlv1); }
    {int tlv47; tlv47 = (int)(tlv1); }
    {int tlv46; tlv46 = (int)(tlv1); }
    {int tlv49; tlv49 = (int)(tlv1); }
    {char * tlv53; tlv53 = (char *)(tlv1); }
    {int tlv52; tlv52 = (int)(tlv1); }
    {int tlv51; tlv51 = (int)(tlv1); }
    {int tlv54; tlv54 = (int)(tlv1); }
    {int tlv2; tlv2 = (int)(tlv1); }
    {int tlv3; tlv3 = (int)(tlv1); }
    {char * tlv82; tlv82 = (char *)(tlv1); }
    {char * tlv83; tlv83 = (char *)(tlv1); }
    {char tlv69; tlv69 = (char)(tlv1); }
    {char * tlv58; tlv58 = (char *)(tlv1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv1); }
    {int tlv59; tlv59 = (int)(tlv1); }
    {char * tlv63; tlv63 = (char *)(tlv1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv1); }
    {int tlv64; tlv64 = (int)(tlv1); }
    {char * tlv68; tlv68 = (char *)(tlv1); }
    {int tlv67; tlv67 = (int)(tlv1); }
    {int tlv66; tlv66 = (int)(tlv1); }
    {int tlv72; tlv72 = (int)(tlv1); }
    {char * tlv76; tlv76 = (char *)(tlv1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv1); }
    {int tlv77; tlv77 = (int)(tlv1); }
    {int tlv4; tlv4 = (int)(tlv1); }
    {char tlv79; tlv79 = (char)(tlv1); }
}
void fix_ingred_packet_2_73(){
fix_ingred_packet_2_73_8();
}
void fix_ingred_packet_2_74_0(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
    {char tlv5; tlv5 = (char)(tmp . content); }
    {char tlv7; tlv7 = (char)(tmp . content); }
    {int tlv6; tlv6 = (int)(tmp . content); }
    {char tlv8; tlv8 = (char)(tmp . content); }
    {int rtn; rtn = (int)(tmp . content); }
    {char * tlv9; tlv9 = (char *)(tmp . content); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tmp . content); }
    {char sideA; sideA = (char)(tmp . content); }
    {char sideB; sideB = (char)(tmp . content); }
    {int indexA; indexA = (int)(tmp . content); }
    {int indexB; indexB = (int)(tmp . content); }
    {int tlv1; tlv1 = (int)(tmp . content); }
    {char * tlv11; tlv11 = (char *)(tmp . content); }
    {void * tlv15; tlv15 = (void *)(tmp . content); }
    {void * tlv14; tlv14 = (void *)(tmp . content); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tmp . content); }
    {char * tlv18; tlv18 = (char *)(tmp . content); }
    {int tlv17; tlv17 = (int)(tmp . content); }
    {int tlv16; tlv16 = (int)(tmp . content); }
    {int tlv19; tlv19 = (int)(tmp . content); }
    {char tlv21; tlv21 = (char)(tmp . content); }
    {char tlv22; tlv22 = (char)(tmp . content); }
    {char tlv25; tlv25 = (char)(tmp . content); }
    {char tlv23; tlv23 = (char)(tmp . content); }
    {char* t ; t  = (char*)(tmp . content); }
    {char* ss ; ss  = (char*)(tmp . content); }
    {char * tlv27; tlv27 = (char *)(tmp . content); }
    {char * tlv30; tlv30 = (char *)(tmp . content); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tmp . content); }
    {int tlv31; tlv31 = (int)(tmp . content); }
    {char * tlv35; tlv35 = (char *)(tmp . content); }
    {int tlv34; tlv34 = (int)(tmp . content); }
    {int tlv33; tlv33 = (int)(tmp . content); }
    {void * tlv38; tlv38 = (void *)(tmp . content); }
    {void * tlv37; tlv37 = (void *)(tmp . content); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tmp . content); }
    {int tlv39; tlv39 = (int)(tmp . content); }
    {void * tlv43; tlv43 = (void *)(tmp . content); }
    {void * tlv42; tlv42 = (void *)(tmp . content); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tmp . content); }
    {int tlv44; tlv44 = (int)(tmp . content); }
    {char * tlv48; tlv48 = (char *)(tmp . content); }
    {int tlv47; tlv47 = (int)(tmp . content); }
    {int tlv46; tlv46 = (int)(tmp . content); }
    {int tlv49; tlv49 = (int)(tmp . content); }
    {char * tlv53; tlv53 = (char *)(tmp . content); }
    {int tlv52; tlv52 = (int)(tmp . content); }
    {int tlv51; tlv51 = (int)(tmp . content); }
    {int tlv54; tlv54 = (int)(tmp . content); }
    {int tlv2; tlv2 = (int)(tmp . content); }
    {int tlv3; tlv3 = (int)(tmp . content); }
    {char * tlv82; tlv82 = (char *)(tmp . content); }
    {char * tlv83; tlv83 = (char *)(tmp . content); }
    {char tlv69; tlv69 = (char)(tmp . content); }
    {char * tlv58; tlv58 = (char *)(tmp . content); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tmp . content); }
    {int tlv59; tlv59 = (int)(tmp . content); }
    {char * tlv63; tlv63 = (char *)(tmp . content); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tmp . content); }
    {int tlv64; tlv64 = (int)(tmp . content); }
    {char * tlv68; tlv68 = (char *)(tmp . content); }
    {int tlv67; tlv67 = (int)(tmp . content); }
    {int tlv66; tlv66 = (int)(tmp . content); }
    {int tlv72; tlv72 = (int)(tmp . content); }
    {char * tlv76; tlv76 = (char *)(tmp . content); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tmp . content); }
    {int tlv77; tlv77 = (int)(tmp . content); }
    {int tlv4; tlv4 = (int)(tmp . content); }
    {char tlv79; tlv79 = (char)(tmp . content); }
}
void fix_ingred_packet_2_74_2(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
    {char tlv5; tlv5 = (char)(8); }
    {char tlv7; tlv7 = (char)(8); }
    {int tlv6; tlv6 = (int)(8); }
    {char tlv8; tlv8 = (char)(8); }
    {int rtn; rtn = (int)(8); }
    {char * tlv9; tlv9 = (char *)(8); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(8); }
    {char sideA; sideA = (char)(8); }
    {char sideB; sideB = (char)(8); }
    {int indexA; indexA = (int)(8); }
    {int indexB; indexB = (int)(8); }
    {int tlv1; tlv1 = (int)(8); }
    {char * tlv11; tlv11 = (char *)(8); }
    {void * tlv15; tlv15 = (void *)(8); }
    {void * tlv14; tlv14 = (void *)(8); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(8); }
    {char * tlv18; tlv18 = (char *)(8); }
    {int tlv17; tlv17 = (int)(8); }
    {int tlv16; tlv16 = (int)(8); }
    {int tlv19; tlv19 = (int)(8); }
    {char tlv21; tlv21 = (char)(8); }
    {char tlv22; tlv22 = (char)(8); }
    {char tlv25; tlv25 = (char)(8); }
    {char tlv23; tlv23 = (char)(8); }
    {char* t ; t  = (char*)(8); }
    {char* ss ; ss  = (char*)(8); }
    {char * tlv27; tlv27 = (char *)(8); }
    {char * tlv30; tlv30 = (char *)(8); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(8); }
    {int tlv31; tlv31 = (int)(8); }
    {char * tlv35; tlv35 = (char *)(8); }
    {int tlv34; tlv34 = (int)(8); }
    {int tlv33; tlv33 = (int)(8); }
    {void * tlv38; tlv38 = (void *)(8); }
    {void * tlv37; tlv37 = (void *)(8); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(8); }
    {int tlv39; tlv39 = (int)(8); }
    {void * tlv43; tlv43 = (void *)(8); }
    {void * tlv42; tlv42 = (void *)(8); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(8); }
    {int tlv44; tlv44 = (int)(8); }
    {char * tlv48; tlv48 = (char *)(8); }
    {int tlv47; tlv47 = (int)(8); }
    {int tlv46; tlv46 = (int)(8); }
    {int tlv49; tlv49 = (int)(8); }
    {char * tlv53; tlv53 = (char *)(8); }
    {int tlv52; tlv52 = (int)(8); }
    {int tlv51; tlv51 = (int)(8); }
    {int tlv54; tlv54 = (int)(8); }
    {int tlv2; tlv2 = (int)(8); }
    {int tlv3; tlv3 = (int)(8); }
    {char * tlv82; tlv82 = (char *)(8); }
    {char * tlv83; tlv83 = (char *)(8); }
    {char tlv69; tlv69 = (char)(8); }
    {char * tlv58; tlv58 = (char *)(8); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(8); }
    {int tlv59; tlv59 = (int)(8); }
    {char * tlv63; tlv63 = (char *)(8); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(8); }
    {int tlv64; tlv64 = (int)(8); }
    {char * tlv68; tlv68 = (char *)(8); }
    {int tlv67; tlv67 = (int)(8); }
    {int tlv66; tlv66 = (int)(8); }
    {int tlv72; tlv72 = (int)(8); }
    {char * tlv76; tlv76 = (char *)(8); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(8); }
    {int tlv77; tlv77 = (int)(8); }
    {int tlv4; tlv4 = (int)(8); }
    {char tlv79; tlv79 = (char)(8); }
}
void fix_ingred_packet_2_74(){
fix_ingred_packet_2_74_0();
fix_ingred_packet_2_74_2();
}
void fix_ingred_packet_2_75_1(){
    {char tlv5; tlv5 = (char)(8); }
    {char tlv7; tlv7 = (char)(8); }
    {int tlv6; tlv6 = (int)(8); }
    {char tlv8; tlv8 = (char)(8); }
    {int rtn; rtn = (int)(8); }
    {char * tlv9; tlv9 = (char *)(8); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(8); }
    {char sideA; sideA = (char)(8); }
    {char sideB; sideB = (char)(8); }
    {int indexA; indexA = (int)(8); }
    {int indexB; indexB = (int)(8); }
    {int tlv1; tlv1 = (int)(8); }
    {char * tlv11; tlv11 = (char *)(8); }
    {void * tlv15; tlv15 = (void *)(8); }
    {void * tlv14; tlv14 = (void *)(8); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(8); }
    {char * tlv18; tlv18 = (char *)(8); }
    {int tlv17; tlv17 = (int)(8); }
    {int tlv16; tlv16 = (int)(8); }
    {int tlv19; tlv19 = (int)(8); }
    {char tlv21; tlv21 = (char)(8); }
    {char tlv22; tlv22 = (char)(8); }
    {char tlv25; tlv25 = (char)(8); }
    {char tlv23; tlv23 = (char)(8); }
    {char* t ; t  = (char*)(8); }
    {char* ss ; ss  = (char*)(8); }
    {char * tlv27; tlv27 = (char *)(8); }
    {char * tlv30; tlv30 = (char *)(8); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(8); }
    {int tlv31; tlv31 = (int)(8); }
    {char * tlv35; tlv35 = (char *)(8); }
    {int tlv34; tlv34 = (int)(8); }
    {int tlv33; tlv33 = (int)(8); }
    {void * tlv38; tlv38 = (void *)(8); }
    {void * tlv37; tlv37 = (void *)(8); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(8); }
    {int tlv39; tlv39 = (int)(8); }
    {void * tlv43; tlv43 = (void *)(8); }
    {void * tlv42; tlv42 = (void *)(8); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(8); }
    {int tlv44; tlv44 = (int)(8); }
    {char * tlv48; tlv48 = (char *)(8); }
    {int tlv47; tlv47 = (int)(8); }
    {int tlv46; tlv46 = (int)(8); }
    {int tlv49; tlv49 = (int)(8); }
    {char * tlv53; tlv53 = (char *)(8); }
    {int tlv52; tlv52 = (int)(8); }
    {int tlv51; tlv51 = (int)(8); }
    {int tlv54; tlv54 = (int)(8); }
    {int tlv2; tlv2 = (int)(8); }
    {int tlv3; tlv3 = (int)(8); }
    {char * tlv82; tlv82 = (char *)(8); }
    {char * tlv83; tlv83 = (char *)(8); }
    {char tlv69; tlv69 = (char)(8); }
    {char * tlv58; tlv58 = (char *)(8); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(8); }
    {int tlv59; tlv59 = (int)(8); }
    {char * tlv63; tlv63 = (char *)(8); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(8); }
    {int tlv64; tlv64 = (int)(8); }
    {char * tlv68; tlv68 = (char *)(8); }
    {int tlv67; tlv67 = (int)(8); }
    {int tlv66; tlv66 = (int)(8); }
    {int tlv72; tlv72 = (int)(8); }
    {char * tlv76; tlv76 = (char *)(8); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(8); }
    {int tlv77; tlv77 = (int)(8); }
    {int tlv4; tlv4 = (int)(8); }
    {char tlv79; tlv79 = (char)(8); }
}
void fix_ingred_packet_2_75(){
fix_ingred_packet_2_75_1();
}
void fix_ingred_packet_2_78_1(){
    {char tlv5; tlv5 = (char)(1); }
    {char tlv7; tlv7 = (char)(1); }
    {int tlv6; tlv6 = (int)(1); }
    {char tlv8; tlv8 = (char)(1); }
    {int rtn; rtn = (int)(1); }
    {char * tlv9; tlv9 = (char *)(1); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(1); }
    {char sideA; sideA = (char)(1); }
    {char sideB; sideB = (char)(1); }
    {int indexA; indexA = (int)(1); }
    {int indexB; indexB = (int)(1); }
    {int tlv1; tlv1 = (int)(1); }
    {char * tlv11; tlv11 = (char *)(1); }
    {void * tlv15; tlv15 = (void *)(1); }
    {void * tlv14; tlv14 = (void *)(1); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(1); }
    {char * tlv18; tlv18 = (char *)(1); }
    {int tlv17; tlv17 = (int)(1); }
    {int tlv16; tlv16 = (int)(1); }
    {int tlv19; tlv19 = (int)(1); }
    {char tlv21; tlv21 = (char)(1); }
    {char tlv22; tlv22 = (char)(1); }
    {char tlv25; tlv25 = (char)(1); }
    {char tlv23; tlv23 = (char)(1); }
    {char* t ; t  = (char*)(1); }
    {char* ss ; ss  = (char*)(1); }
    {char * tlv27; tlv27 = (char *)(1); }
    {char * tlv30; tlv30 = (char *)(1); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(1); }
    {int tlv31; tlv31 = (int)(1); }
    {char * tlv35; tlv35 = (char *)(1); }
    {int tlv34; tlv34 = (int)(1); }
    {int tlv33; tlv33 = (int)(1); }
    {void * tlv38; tlv38 = (void *)(1); }
    {void * tlv37; tlv37 = (void *)(1); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(1); }
    {int tlv39; tlv39 = (int)(1); }
    {void * tlv43; tlv43 = (void *)(1); }
    {void * tlv42; tlv42 = (void *)(1); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(1); }
    {int tlv44; tlv44 = (int)(1); }
    {char * tlv48; tlv48 = (char *)(1); }
    {int tlv47; tlv47 = (int)(1); }
    {int tlv46; tlv46 = (int)(1); }
    {int tlv49; tlv49 = (int)(1); }
    {char * tlv53; tlv53 = (char *)(1); }
    {int tlv52; tlv52 = (int)(1); }
    {int tlv51; tlv51 = (int)(1); }
    {int tlv54; tlv54 = (int)(1); }
    {int tlv2; tlv2 = (int)(1); }
    {int tlv3; tlv3 = (int)(1); }
    {char * tlv82; tlv82 = (char *)(1); }
    {char * tlv83; tlv83 = (char *)(1); }
    {char tlv69; tlv69 = (char)(1); }
    {char * tlv58; tlv58 = (char *)(1); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(1); }
    {int tlv59; tlv59 = (int)(1); }
    {char * tlv63; tlv63 = (char *)(1); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(1); }
    {int tlv64; tlv64 = (int)(1); }
    {char * tlv68; tlv68 = (char *)(1); }
    {int tlv67; tlv67 = (int)(1); }
    {int tlv66; tlv66 = (int)(1); }
    {int tlv72; tlv72 = (int)(1); }
    {char * tlv76; tlv76 = (char *)(1); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(1); }
    {int tlv77; tlv77 = (int)(1); }
    {int tlv4; tlv4 = (int)(1); }
    {char tlv79; tlv79 = (char)(1); }
}
void fix_ingred_packet_2_78(){
fix_ingred_packet_2_78_1();
}
void fix_ingred_packet_2_85_7(){
int tlv3;
    bzero(&tlv3,sizeof(int));
    {char tlv5; tlv5 = (char)(tlv3); }
    {char tlv7; tlv7 = (char)(tlv3); }
    {int tlv6; tlv6 = (int)(tlv3); }
    {char tlv8; tlv8 = (char)(tlv3); }
    {int rtn; rtn = (int)(tlv3); }
    {char * tlv9; tlv9 = (char *)(tlv3); }
    {char ss [ 9 ]; ss [ ( 9 )-1 ] = (char)(tlv3); }
    {char sideA; sideA = (char)(tlv3); }
    {char sideB; sideB = (char)(tlv3); }
    {int indexA; indexA = (int)(tlv3); }
    {int indexB; indexB = (int)(tlv3); }
    {int tlv1; tlv1 = (int)(tlv3); }
    {char * tlv11; tlv11 = (char *)(tlv3); }
    {void * tlv15; tlv15 = (void *)(tlv3); }
    {void * tlv14; tlv14 = (void *)(tlv3); }
    {cgc_size_t tlv13; tlv13 = (cgc_size_t)(tlv3); }
    {char * tlv18; tlv18 = (char *)(tlv3); }
    {int tlv17; tlv17 = (int)(tlv3); }
    {int tlv16; tlv16 = (int)(tlv3); }
    {int tlv19; tlv19 = (int)(tlv3); }
    {char tlv21; tlv21 = (char)(tlv3); }
    {char tlv22; tlv22 = (char)(tlv3); }
    {char tlv25; tlv25 = (char)(tlv3); }
    {char tlv23; tlv23 = (char)(tlv3); }
    {char* t ; t  = (char*)(tlv3); }
    {char* ss ; ss  = (char*)(tlv3); }
    {char * tlv27; tlv27 = (char *)(tlv3); }
    {char * tlv30; tlv30 = (char *)(tlv3); }
    {cgc_size_t tlv28; tlv28 = (cgc_size_t)(tlv3); }
    {int tlv31; tlv31 = (int)(tlv3); }
    {char * tlv35; tlv35 = (char *)(tlv3); }
    {int tlv34; tlv34 = (int)(tlv3); }
    {int tlv33; tlv33 = (int)(tlv3); }
    {void * tlv38; tlv38 = (void *)(tlv3); }
    {void * tlv37; tlv37 = (void *)(tlv3); }
    {cgc_size_t tlv36; tlv36 = (cgc_size_t)(tlv3); }
    {int tlv39; tlv39 = (int)(tlv3); }
    {void * tlv43; tlv43 = (void *)(tlv3); }
    {void * tlv42; tlv42 = (void *)(tlv3); }
    {cgc_size_t tlv41; tlv41 = (cgc_size_t)(tlv3); }
    {int tlv44; tlv44 = (int)(tlv3); }
    {char * tlv48; tlv48 = (char *)(tlv3); }
    {int tlv47; tlv47 = (int)(tlv3); }
    {int tlv46; tlv46 = (int)(tlv3); }
    {int tlv49; tlv49 = (int)(tlv3); }
    {char * tlv53; tlv53 = (char *)(tlv3); }
    {int tlv52; tlv52 = (int)(tlv3); }
    {int tlv51; tlv51 = (int)(tlv3); }
    {int tlv54; tlv54 = (int)(tlv3); }
    {int tlv2; tlv2 = (int)(tlv3); }
    {char * tlv82; tlv82 = (char *)(tlv3); }
    {char * tlv83; tlv83 = (char *)(tlv3); }
    {char tlv69; tlv69 = (char)(tlv3); }
    {char * tlv58; tlv58 = (char *)(tlv3); }
    {cgc_size_t tlv56; tlv56 = (cgc_size_t)(tlv3); }
    {int tlv59; tlv59 = (int)(tlv3); }
    {char * tlv63; tlv63 = (char *)(tlv3); }
    {cgc_size_t tlv61; tlv61 = (cgc_size_t)(tlv3); }
    {int tlv64; tlv64 = (int)(tlv3); }
    {char * tlv68; tlv68 = (char *)(tlv3); }
    {int tlv67; tlv67 = (int)(tlv3); }
    {int tlv66; tlv66 = (int)(tlv3); }
    {int tlv72; tlv72 = (int)(tlv3); }
    {char * tlv76; tlv76 = (char *)(tlv3); }
    {cgc_size_t tlv74; tlv74 = (cgc_size_t)(tlv3); }
    {int tlv77; tlv77 = (int)(tlv3); }
    {int tlv4; tlv4 = (int)(tlv3); }
    {char tlv79; tlv79 = (char)(tlv3); }
}
void fix_ingred_packet_2_85(){
fix_ingred_packet_2_85_7();
}
void fix_ingred_packet_2(){
fix_ingred_packet_2_8();
fix_ingred_packet_2_17();
fix_ingred_packet_2_25();
fix_ingred_packet_2_33();
fix_ingred_packet_2_38();
fix_ingred_packet_2_39();
fix_ingred_packet_2_40();
fix_ingred_packet_2_41();
fix_ingred_packet_2_43();
fix_ingred_packet_2_45();
fix_ingred_packet_2_46();
fix_ingred_packet_2_47();
fix_ingred_packet_2_49();
fix_ingred_packet_2_50();
fix_ingred_packet_2_52();
fix_ingred_packet_2_53();
fix_ingred_packet_2_54();
fix_ingred_packet_2_59();
fix_ingred_packet_2_62();
fix_ingred_packet_2_66();
fix_ingred_packet_2_67();
fix_ingred_packet_2_69();
fix_ingred_packet_2_71();
fix_ingred_packet_2_72();
fix_ingred_packet_2_73();
fix_ingred_packet_2_74();
fix_ingred_packet_2_75();
fix_ingred_packet_2_78();
fix_ingred_packet_2_85();
}
void fix_ingred_packet_3(){
}
void fix_ingred_packet_4_1_1(){
    {int tlv1; tlv1 = (int)(2); }
}
void fix_ingred_packet_4_1(){
fix_ingred_packet_4_1_1();
}
void fix_ingred_packet_4(){
fix_ingred_packet_4_1();
}
void fix_ingred_packet_5_1_6(){
char req_conn;
    bzero(&req_conn,sizeof(char));
    {int tlv1; tlv1 = (int)(req_conn); }
    {int tlv4; tlv4 = (int)(req_conn); }
}
void fix_ingred_packet_5_1_7(){
char req_conn;
    bzero(&req_conn,sizeof(char));
    {int tlv1; tlv1 = (int)(last_connection_number + 1); }
    {int tlv4; tlv4 = (int)(last_connection_number + 1); }
}
void fix_ingred_packet_5_1(){
fix_ingred_packet_5_1_6();
fix_ingred_packet_5_1_7();
}
void fix_ingred_packet_5(){
fix_ingred_packet_5_1();
}
void fix_ingred_packet_6(){
}
void fix_ingred_packet_7_1_1(){
int i;
    bzero(&i,sizeof(int));
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(i); }
    {void * tlv3; tlv3 = (void *)(i); }
    {void * tlv2; tlv2 = (void *)(i); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(i); }
    {int tlv4; tlv4 = (int)(i); }
    {char * tlv8; tlv8 = (char *)(i); }
    {int tlv7; tlv7 = (int)(i); }
    {int tlv6; tlv6 = (int)(i); }
    {void * tlv11; tlv11 = (void *)(i); }
    {void * tlv10; tlv10 = (void *)(i); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(i); }
    {uint32_t tlv13; tlv13 = (uint32_t)(i); }
    {uint32_t tlv12; tlv12 = (uint32_t)(i); }
}
void fix_ingred_packet_7_1_2(){
int i;
    bzero(&i,sizeof(int));
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(5); }
    {void * tlv3; tlv3 = (void *)(5); }
    {void * tlv2; tlv2 = (void *)(5); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(5); }
    {int tlv4; tlv4 = (int)(5); }
    {char * tlv8; tlv8 = (char *)(5); }
    {int tlv7; tlv7 = (int)(5); }
    {int tlv6; tlv6 = (int)(5); }
    {void * tlv11; tlv11 = (void *)(5); }
    {void * tlv10; tlv10 = (void *)(5); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(5); }
    {uint32_t tlv13; tlv13 = (uint32_t)(5); }
    {uint32_t tlv12; tlv12 = (uint32_t)(5); }
}
void fix_ingred_packet_7_1(){
fix_ingred_packet_7_1_1();
fix_ingred_packet_7_1_2();
}
void fix_ingred_packet_7_2_0(){
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)('a'); }
    {void * tlv3; tlv3 = (void *)('a'); }
    {void * tlv2; tlv2 = (void *)('a'); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)('a'); }
    {int tlv4; tlv4 = (int)('a'); }
    {char * tlv8; tlv8 = (char *)('a'); }
    {int tlv7; tlv7 = (int)('a'); }
    {int tlv6; tlv6 = (int)('a'); }
    {void * tlv11; tlv11 = (void *)('a'); }
    {void * tlv10; tlv10 = (void *)('a'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('a'); }
    {uint32_t tlv13; tlv13 = (uint32_t)('a'); }
    {uint32_t tlv12; tlv12 = (uint32_t)('a'); }
}
void fix_ingred_packet_7_2_1(){
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)('p'); }
    {void * tlv3; tlv3 = (void *)('p'); }
    {void * tlv2; tlv2 = (void *)('p'); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)('p'); }
    {int tlv4; tlv4 = (int)('p'); }
    {char * tlv8; tlv8 = (char *)('p'); }
    {int tlv7; tlv7 = (int)('p'); }
    {int tlv6; tlv6 = (int)('p'); }
    {void * tlv11; tlv11 = (void *)('p'); }
    {void * tlv10; tlv10 = (void *)('p'); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)('p'); }
    {uint32_t tlv13; tlv13 = (uint32_t)('p'); }
    {uint32_t tlv12; tlv12 = (uint32_t)('p'); }
}
void fix_ingred_packet_7_2(){
fix_ingred_packet_7_2_0();
fix_ingred_packet_7_2_1();
}
void fix_ingred_packet_7_3_0(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
char chall_val [ 5 ];
    bzero(&chall_val,( 5 *sizeof(char) ) );
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(tmp . content); }
    {void * tlv3; tlv3 = (void *)(tmp . content); }
    {void * tlv2; tlv2 = (void *)(tmp . content); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(tmp . content); }
    {char * tlv8; tlv8 = (char *)(tmp . content); }
    {int tlv7; tlv7 = (int)(tmp . content); }
    {void * tlv11; tlv11 = (void *)(tmp . content); }
    {void * tlv10; tlv10 = (void *)(tmp . content); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(tmp . content); }
    {uint32_t tlv13; tlv13 = (uint32_t)(tmp . content); }
    {uint32_t tlv12; tlv12 = (uint32_t)(tmp . content); }
}
void fix_ingred_packet_7_3_1(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
char chall_val [ 5 ];
    bzero(&chall_val,( 5 *sizeof(char) ) );
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(chall_val); }
    {void * tlv3; tlv3 = (void *)(chall_val); }
    {void * tlv2; tlv2 = (void *)(chall_val); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(chall_val); }
    {int tlv4; tlv4 = (int)(chall_val); }
    {char * tlv8; tlv8 = (char *)(chall_val); }
    {int tlv7; tlv7 = (int)(chall_val); }
    {int tlv6; tlv6 = (int)(chall_val); }
    {void * tlv11; tlv11 = (void *)(chall_val); }
    {void * tlv10; tlv10 = (void *)(chall_val); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(chall_val); }
    {uint32_t tlv13; tlv13 = (uint32_t)(chall_val); }
    {uint32_t tlv12; tlv12 = (uint32_t)(chall_val); }
}
void fix_ingred_packet_7_3_2(){
Packet tmp;
    bzero(&tmp,sizeof(Packet));
char chall_val [ 5 ];
    bzero(&chall_val,( 5 *sizeof(char) ) );
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(5); }
    {void * tlv3; tlv3 = (void *)(5); }
    {void * tlv2; tlv2 = (void *)(5); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(5); }
    {int tlv4; tlv4 = (int)(5); }
    {char * tlv8; tlv8 = (char *)(5); }
    {int tlv7; tlv7 = (int)(5); }
    {int tlv6; tlv6 = (int)(5); }
    {void * tlv11; tlv11 = (void *)(5); }
    {void * tlv10; tlv10 = (void *)(5); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(5); }
    {uint32_t tlv13; tlv13 = (uint32_t)(5); }
    {uint32_t tlv12; tlv12 = (uint32_t)(5); }
}
void fix_ingred_packet_7_3(){
fix_ingred_packet_7_3_0();
fix_ingred_packet_7_3_1();
fix_ingred_packet_7_3_2();
}
void fix_ingred_packet_7_5_0(){
char chall_val [ 5 ];
    bzero(&chall_val,( 5 *sizeof(char) ) );
int enc;
    bzero(&enc,sizeof(int));
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(chall_val); }
    {void * tlv3; tlv3 = (void *)(chall_val); }
    {void * tlv2; tlv2 = (void *)(chall_val); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(chall_val); }
    {int tlv4; tlv4 = (int)(chall_val); }
    {char * tlv8; tlv8 = (char *)(chall_val); }
    {int tlv7; tlv7 = (int)(chall_val); }
    {int tlv6; tlv6 = (int)(chall_val); }
    {void * tlv11; tlv11 = (void *)(chall_val); }
    {void * tlv10; tlv10 = (void *)(chall_val); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(chall_val); }
    {uint32_t tlv13; tlv13 = (uint32_t)(chall_val); }
    {uint32_t tlv12; tlv12 = (uint32_t)(chall_val); }
}
void fix_ingred_packet_7_5_2(){
char chall_val [ 5 ];
    bzero(&chall_val,( 5 *sizeof(char) ) );
int enc;
    bzero(&enc,sizeof(int));
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(enc); }
    {void * tlv3; tlv3 = (void *)(enc); }
    {void * tlv2; tlv2 = (void *)(enc); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(enc); }
    {int tlv4; tlv4 = (int)(enc); }
    {char * tlv8; tlv8 = (char *)(enc); }
    {int tlv7; tlv7 = (int)(enc); }
    {int tlv6; tlv6 = (int)(enc); }
    {void * tlv11; tlv11 = (void *)(enc); }
    {void * tlv10; tlv10 = (void *)(enc); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(enc); }
    {uint32_t tlv13; tlv13 = (uint32_t)(enc); }
    {uint32_t tlv12; tlv12 = (uint32_t)(enc); }
}
void fix_ingred_packet_7_5(){
fix_ingred_packet_7_5_0();
fix_ingred_packet_7_5_2();
}
void fix_ingred_packet_7_6_0(){
    {char chall_val [ 5 ]; chall_val [ ( 5 )-1 ] = (char)(enc_chal . answer); }
    {void * tlv3; tlv3 = (void *)(enc_chal . answer); }
    {void * tlv2; tlv2 = (void *)(enc_chal . answer); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(enc_chal . answer); }
    {int tlv4; tlv4 = (int)(enc_chal . answer); }
    {char * tlv8; tlv8 = (char *)(enc_chal . answer); }
    {int tlv7; tlv7 = (int)(enc_chal . answer); }
    {int tlv6; tlv6 = (int)(enc_chal . answer); }
    {void * tlv11; tlv11 = (void *)(enc_chal . answer); }
    {void * tlv10; tlv10 = (void *)(enc_chal . answer); }
    {cgc_size_t tlv9; tlv9 = (cgc_size_t)(enc_chal . answer); }
    {uint32_t tlv13; tlv13 = (uint32_t)(enc_chal . answer); }
    {uint32_t tlv12; tlv12 = (uint32_t)(enc_chal . answer); }
}
void fix_ingred_packet_7_6(){
fix_ingred_packet_7_6_0();
}
void fix_ingred_packet_7(){
fix_ingred_packet_7_1();
fix_ingred_packet_7_2();
fix_ingred_packet_7_3();
fix_ingred_packet_7_5();
fix_ingred_packet_7_6();
}
void fix_ingred_packet_8_3_0(){
    {char matches; matches = (char)(SUCCESS); }
    {int tlv1; tlv1 = (int)(SUCCESS); }
    {int tlv3; tlv3 = (int)(SUCCESS); }
    {int tlv5; tlv5 = (int)(SUCCESS); }
    {int tlv7; tlv7 = (int)(SUCCESS); }
}
void fix_ingred_packet_8_3(){
fix_ingred_packet_8_3_0();
}
void fix_ingred_packet_8_4_1(){
int i;
    bzero(&i,sizeof(int));
    {char matches; matches = (char)(i); }
    {int tlv1; tlv1 = (int)(i); }
    {int tlv3; tlv3 = (int)(i); }
    {int tlv5; tlv5 = (int)(i); }
}
void fix_ingred_packet_8_4_2(){
int i;
    bzero(&i,sizeof(int));
    {char matches; matches = (char)(5); }
    {int tlv1; tlv1 = (int)(5); }
    {int tlv3; tlv3 = (int)(5); }
    {int tlv5; tlv5 = (int)(5); }
}
void fix_ingred_packet_8_4(){
fix_ingred_packet_8_4_1();
fix_ingred_packet_8_4_2();
}
void fix_ingred_packet_8_5_0(){
char answer_ref;
    bzero(&answer_ref,1*sizeof(char));
char * answer = &answer_ref;
int i;
    bzero(&i,sizeof(int));
    {char matches; matches = (char)(FAIL); }
    {int tlv1; tlv1 = (int)(FAIL); }
    {int tlv3; tlv3 = (int)(FAIL); }
    {int tlv5; tlv5 = (int)(FAIL); }
    {int tlv7; tlv7 = (int)(FAIL); }
}
void fix_ingred_packet_8_5_4(){
char answer_ref;
    bzero(&answer_ref,1*sizeof(char));
char * answer = &answer_ref;
int i;
    bzero(&i,sizeof(int));
    {    i = 0;
         char matches; matches = (char)(answer [ i ]); }
    {    i = 0;
         int tlv1; tlv1 = (int)(answer [ i ]); }
    {    i = 0;
         int tlv3; tlv3 = (int)(answer [ i ]); }
    {    i = 0;
         int tlv5; tlv5 = (int)(answer [ i ]); }
    {    i = 0;
         int tlv7; tlv7 = (int)(answer [ i ]); }
}
void fix_ingred_packet_8_5(){
fix_ingred_packet_8_5_0();
fix_ingred_packet_8_5_4();
}
void fix_ingred_packet_8_7_1(){
    {char matches; matches = (char)(1); }
    {int tlv5; tlv5 = (int)(1); }
    {int tlv7; tlv7 = (int)(1); }
}
void fix_ingred_packet_8_7(){
fix_ingred_packet_8_7_1();
}
void fix_ingred_packet_8(){
fix_ingred_packet_8_3();
fix_ingred_packet_8_4();
fix_ingred_packet_8_5();
fix_ingred_packet_8_7();
}
void fix_ingred_packet_9_3_3(){
char reason;
    bzero(&reason,sizeof(char));
    {int tlv2; tlv2 = (int)(reason); }
    {int tlv4; tlv4 = (int)(reason); }
}
void fix_ingred_packet_9_3_4(){
char reason;
    bzero(&reason,sizeof(char));
    {int tlv2; tlv2 = (int)(GOOD_DISRESP); }
    {int tlv4; tlv4 = (int)(GOOD_DISRESP); }
}
void fix_ingred_packet_9_3(){
fix_ingred_packet_9_3_3();
fix_ingred_packet_9_3_4();
}
void fix_ingred_packet_9(){
fix_ingred_packet_9_3();
}
void fix_ingred_packet_10_1_3(){
char reason;
    bzero(&reason,sizeof(char));
    {int tlv1; tlv1 = (int)(reason); }
    {int tlv3; tlv3 = (int)(reason); }
}
void fix_ingred_packet_10_1_4(){
char reason;
    bzero(&reason,sizeof(char));
    {int tlv1; tlv1 = (int)(GOOD_DEAUTHRESP); }
    {int tlv3; tlv3 = (int)(GOOD_DEAUTHRESP); }
}
void fix_ingred_packet_10_1(){
fix_ingred_packet_10_1_3();
fix_ingred_packet_10_1_4();
}
void fix_ingred_packet_10(){
fix_ingred_packet_10_1();
}
void fix_ingred_packet_11_1_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {void * tlv2; tlv2 = (void *)(( char * ) pkt); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(( char * ) pkt); }
}
void fix_ingred_packet_11_1_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {void * tlv2; tlv2 = (void *)(sizeof ( Packet )); }
    {cgc_size_t tlv1; tlv1 = (cgc_size_t)(sizeof ( Packet )); }
}
void fix_ingred_packet_11_1(){
fix_ingred_packet_11_1_0();
fix_ingred_packet_11_1_1();
}
void fix_ingred_packet_11(){
fix_ingred_packet_11_1();
}
void fix_ingred_packet_12(){
}
void fix_ingred_packet_13_0_0(){
    {char ret; ret = (char)(0); }
}
void fix_ingred_packet_13_0(){
fix_ingred_packet_13_0_0();
}
void fix_ingred_packet_13_1_0(){
char bytes_ref;
    bzero(&bytes_ref,1*sizeof(char));
char * bytes = &bytes_ref;
int i;
    bzero(&i,sizeof(int));
int len;
    bzero(&len,sizeof(int));
    {    i = 0;
         char ret; ret = (char)(bytes [ i ]); }
}
void fix_ingred_packet_13_1_2(){
char bytes_ref;
    bzero(&bytes_ref,1*sizeof(char));
char * bytes = &bytes_ref;
int i;
    bzero(&i,sizeof(int));
int len;
    bzero(&len,sizeof(int));
    {char ret; ret = (char)(i); }
}
void fix_ingred_packet_13_1_3(){
char bytes_ref;
    bzero(&bytes_ref,1*sizeof(char));
char * bytes = &bytes_ref;
int i;
    bzero(&i,sizeof(int));
int len;
    bzero(&len,sizeof(int));
    {char ret; ret = (char)(len); }
}
void fix_ingred_packet_13_1(){
fix_ingred_packet_13_1_0();
fix_ingred_packet_13_1_2();
fix_ingred_packet_13_1_3();
}
void fix_ingred_packet_13(){
fix_ingred_packet_13_0();
fix_ingred_packet_13_1();
}
void fix_ingred_packet_14_1_0(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char * tlv2; tlv2 = (char *)(( char * ) pkt); }
    {int tlv1; tlv1 = (int)(( char * ) pkt); }
}
void fix_ingred_packet_14_1_1(){
Packet pkt_ref;
    bzero(&pkt_ref,1*sizeof(Packet));
Packet * pkt = &pkt_ref;
    {char * tlv2; tlv2 = (char *)(sizeof ( Packet ) - 1); }
    {int tlv1; tlv1 = (int)(sizeof ( Packet ) - 1); }
}
void fix_ingred_packet_14_1(){
fix_ingred_packet_14_1_0();
fix_ingred_packet_14_1_1();
}
void fix_ingred_packet_14(){
fix_ingred_packet_14_1();
}
void fix_ingred_packet_15(){
}
void fix_ingred_packet_16(){
}
void fix_ingred_packet_17_1_0(){
int type;
    bzero(&type,sizeof(int));
    {int i; i = (int)(0); }
    {int char_index; char_index = (int)(0); }
    {char tlv1; tlv1 = (char)(0); }
    {char tlv2; tlv2 = (char)(0); }
    {char x; x = (char)(0); }
    {signed char x; x = (signed char)(0); }
}
void fix_ingred_packet_17_1_1(){
int type;
    bzero(&type,sizeof(int));
    {int i; i = (int)(type); }
    {int char_index; char_index = (int)(type); }
    {char tlv1; tlv1 = (char)(type); }
    {char tlv2; tlv2 = (char)(type); }
    {char x; x = (char)(type); }
    {signed char x; x = (signed char)(type); }
}
void fix_ingred_packet_17_1_2(){
int type;
    bzero(&type,sizeof(int));
    {int i; i = (int)(ENC_TWO); }
    {int char_index; char_index = (int)(ENC_TWO); }
    {char tlv1; tlv1 = (char)(ENC_TWO); }
    {char tlv2; tlv2 = (char)(ENC_TWO); }
    {char x; x = (char)(ENC_TWO); }
    {signed char x; x = (signed char)(ENC_TWO); }
}
void fix_ingred_packet_17_1(){
fix_ingred_packet_17_1_0();
fix_ingred_packet_17_1_1();
fix_ingred_packet_17_1_2();
}
void fix_ingred_packet_17_2_3(){
int i;
    bzero(&i,sizeof(int));
int len;
    bzero(&len,sizeof(int));
    {int char_index; char_index = (int)(i); }
    {char tlv1; tlv1 = (char)(i); }
    {char tlv2; tlv2 = (char)(i); }
    {char x; x = (char)(i); }
    {signed char x; x = (signed char)(i); }
}
void fix_ingred_packet_17_2_4(){
int i;
    bzero(&i,sizeof(int));
int len;
    bzero(&len,sizeof(int));
    {int i; i = (int)(len); }
    {int char_index; char_index = (int)(len); }
    {char tlv1; tlv1 = (char)(len); }
    {char tlv2; tlv2 = (char)(len); }
    {char x; x = (char)(len); }
    {signed char x; x = (signed char)(len); }
}
void fix_ingred_packet_17_2(){
fix_ingred_packet_17_2_3();
fix_ingred_packet_17_2_4();
}
void fix_ingred_packet_17_3_0(){
char data_ref;
    bzero(&data_ref,1*sizeof(char));
char * data = &data_ref;
int i;
    bzero(&i,sizeof(int));
    {    i = 0;
         int char_index; char_index = (int)(data [ i ]); }
    {    i = 0;
         char tlv1; tlv1 = (char)(data [ i ]); }
    {    i = 0;
         char tlv2; tlv2 = (char)(data [ i ]); }
    {    i = 0;
         char x; x = (char)(data [ i ]); }
    {    i = 0;
         signed char x; x = (signed char)(data [ i ]); }
}
void fix_ingred_packet_17_3(){
fix_ingred_packet_17_3_0();
}
void fix_ingred_packet_17_4_5(){
int char_index;
    bzero(&char_index,sizeof(int));
    {int i; i = (int)(char_index); }
    {char tlv1; tlv1 = (char)(char_index); }
    {char tlv2; tlv2 = (char)(char_index); }
    {char x; x = (char)(char_index); }
    {signed char x; x = (signed char)(char_index); }
}
void fix_ingred_packet_17_4_6(){
int char_index;
    bzero(&char_index,sizeof(int));
    {int i; i = (int)(- 1); }
    {int char_index; char_index = (int)(- 1); }
    {char tlv1; tlv1 = (char)(- 1); }
    {char tlv2; tlv2 = (char)(- 1); }
    {char x; x = (char)(- 1); }
    {signed char x; x = (signed char)(- 1); }
}
void fix_ingred_packet_17_4(){
fix_ingred_packet_17_4_5();
fix_ingred_packet_17_4_6();
}
void fix_ingred_packet_17_6_0(){
int char_index;
    bzero(&char_index,sizeof(int));
    {int i; i = (int)(char_index - offset); }
    {char tlv1; tlv1 = (char)(char_index - offset); }
    {char tlv2; tlv2 = (char)(char_index - offset); }
    {char x; x = (char)(char_index - offset); }
    {signed char x; x = (signed char)(char_index - offset); }
}
void fix_ingred_packet_17_6(){
fix_ingred_packet_17_6_0();
}
void fix_ingred_packet_17_7_0(){
int char_index;
    bzero(&char_index,sizeof(int));
signed char x;
    bzero(&x,sizeof(signed char));
    {int i; i = (int)(LAST_CHAR_POS - ( offset - char_index )); }
    {char tlv1; tlv1 = (char)(LAST_CHAR_POS - ( offset - char_index )); }
    {char tlv2; tlv2 = (char)(LAST_CHAR_POS - ( offset - char_index )); }
    {char x; x = (char)(LAST_CHAR_POS - ( offset - char_index )); }
    {signed char x; x = (signed char)(LAST_CHAR_POS - ( offset - char_index )); }
}
void fix_ingred_packet_17_7_7(){
int char_index;
    bzero(&char_index,sizeof(int));
signed char x;
    bzero(&x,sizeof(signed char));
    {int i; i = (int)(x); }
    {int char_index; char_index = (int)(x); }
    {char tlv1; tlv1 = (char)(x); }
    {char tlv2; tlv2 = (char)(x); }
}
void fix_ingred_packet_17_7_8(){
int char_index;
    bzero(&char_index,sizeof(int));
signed char x;
    bzero(&x,sizeof(signed char));
    {int i; i = (int)(0); }
    {int char_index; char_index = (int)(0); }
    {char tlv1; tlv1 = (char)(0); }
    {char tlv2; tlv2 = (char)(0); }
    {char x; x = (char)(0); }
    {signed char x; x = (signed char)(0); }
}
void fix_ingred_packet_17_7(){
fix_ingred_packet_17_7_0();
fix_ingred_packet_17_7_7();
fix_ingred_packet_17_7_8();
}
void fix_ingred_packet_17_8_2(){
    {int i; i = (int)(ENC_ONE); }
    {int char_index; char_index = (int)(ENC_ONE); }
    {char tlv1; tlv1 = (char)(ENC_ONE); }
    {char tlv2; tlv2 = (char)(ENC_ONE); }
    {char x; x = (char)(ENC_ONE); }
    {signed char x; x = (signed char)(ENC_ONE); }
}
void fix_ingred_packet_17_8(){
fix_ingred_packet_17_8_2();
}
void fix_ingred_packet_17(){
fix_ingred_packet_17_1();
fix_ingred_packet_17_2();
fix_ingred_packet_17_3();
fix_ingred_packet_17_4();
fix_ingred_packet_17_6();
fix_ingred_packet_17_7();
fix_ingred_packet_17_8();
}
void fix_ingred_packet_18(){
}
void fix_ingred_packet_19_1_1(){
int tlv1;
    bzero(&tlv1,sizeof(int));
int goal;
    bzero(&goal,sizeof(int));
    {char buff [ 5 ]; buff [ ( 5 )-1 ] = (char)(tlv1); }
    {int len; len = (int)(tlv1); }
    {char * tlv5; tlv5 = (char *)(tlv1); }
    {char tlv4; tlv4 = (char)(tlv1); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(tlv1); }
}
void fix_ingred_packet_19_1_2(){
int tlv1;
    bzero(&tlv1,sizeof(int));
int goal;
    bzero(&goal,sizeof(int));
    {char buff [ 5 ]; buff [ ( 5 )-1 ] = (char)(goal); }
    {int tlv1; tlv1 = (int)(goal); }
    {int len; len = (int)(goal); }
    {char * tlv5; tlv5 = (char *)(goal); }
    {char tlv4; tlv4 = (char)(goal); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(goal); }
}
void fix_ingred_packet_19_1(){
fix_ingred_packet_19_1_1();
fix_ingred_packet_19_1_2();
}
void fix_ingred_packet_19_3_0(){
char buff [ 5 ];
    bzero(&buff,( 5 *sizeof(char) ) );
    {char buff [ 5 ]; buff [ ( 5 )-1 ] = (char)(buff); }
    {int tlv1; tlv1 = (int)(buff); }
    {int len; len = (int)(buff); }
    {char * tlv5; tlv5 = (char *)(buff); }
    {char tlv4; tlv4 = (char)(buff); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(buff); }
}
void fix_ingred_packet_19_3_1(){
char buff [ 5 ];
    bzero(&buff,( 5 *sizeof(char) ) );
    {char buff [ 5 ]; buff [ ( 5 )-1 ] = (char)('\n'); }
    {int tlv1; tlv1 = (int)('\n'); }
    {int len; len = (int)('\n'); }
    {char * tlv5; tlv5 = (char *)('\n'); }
    {char tlv4; tlv4 = (char)('\n'); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)('\n'); }
}
void fix_ingred_packet_19_3_2(){
char buff [ 5 ];
    bzero(&buff,( 5 *sizeof(char) ) );
    {char buff [ 5 ]; buff [ ( 5 )-1 ] = (char)(25); }
    {int tlv1; tlv1 = (int)(25); }
    {int len; len = (int)(25); }
    {char * tlv5; tlv5 = (char *)(25); }
    {char tlv4; tlv4 = (char)(25); }
    {cgc_size_t tlv3; tlv3 = (cgc_size_t)(25); }
}
void fix_ingred_packet_19_3(){
fix_ingred_packet_19_3_0();
fix_ingred_packet_19_3_1();
fix_ingred_packet_19_3_2();
}
void fix_ingred_packet_19(){
fix_ingred_packet_19_1();
fix_ingred_packet_19_3();
}
