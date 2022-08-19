register_opcode({0xce,0x00},{0x01,0x00}, Instruction_ADC::create, {
REF(A), REF(PC8_1)});

register_opcode({0x8e},{0x01}, Instruction_ADC::create, {
REF(A), REF((HL))});

register_opcode({0xdd,0x8e,0x00},{0x01,0x01,0x00}, Instruction_ADC::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0x8e,0x00},{0x01,0x01,0x00}, Instruction_ADC::create, {
REF(A), REF((IY+::))});

register_opcode({0x8f},{0x01}, Instruction_ADC::create, {
REF(A), REF(A)});

register_opcode({0x88},{0x01}, Instruction_ADC::create, {
REF(A), REF(B)});

register_opcode({0x89},{0x01}, Instruction_ADC::create, {
REF(A), REF(C)});

register_opcode({0x8a},{0x01}, Instruction_ADC::create, {
REF(A), REF(D)});

register_opcode({0x8b},{0x01}, Instruction_ADC::create, {
REF(A), REF(E)});

register_opcode({0x8c},{0x01}, Instruction_ADC::create, {
REF(A), REF(H)});

register_opcode({0x8d},{0x01}, Instruction_ADC::create, {
REF(A), REF(L)});

register_opcode({0xed,0x4a},{0x01,0x01}, Instruction_ADC::create, {
REF(HL), REF(BC)});

register_opcode({0xed,0x5a},{0x01,0x01}, Instruction_ADC::create, {
REF(HL), REF(DE)});

register_opcode({0xed,0x6a},{0x01,0x01}, Instruction_ADC::create, {
REF(HL), REF(HL)});

register_opcode({0xed,0x7a},{0x01,0x01}, Instruction_ADC::create, {
REF(HL), REF(SP)});

register_opcode({0xc6,0x00},{0x01,0x00}, Instruction_ADD::create, {
REF(A), REF(PC8_1)});

register_opcode({0x86},{0x01}, Instruction_ADD::create, {
REF(A), REF((HL))});

register_opcode({0xdd,0x86,0x00},{0x01,0x01,0x00}, Instruction_ADD::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0x86,0x00},{0x01,0x01,0x00}, Instruction_ADD::create, {
REF(A), REF((IY+::))});

register_opcode({0x87},{0x01}, Instruction_ADD::create, {
REF(A), REF(A)});

register_opcode({0x80},{0x01}, Instruction_ADD::create, {
REF(A), REF(B)});

register_opcode({0x81},{0x01}, Instruction_ADD::create, {
REF(A), REF(C)});

register_opcode({0x82},{0x01}, Instruction_ADD::create, {
REF(A), REF(D)});

register_opcode({0x83},{0x01}, Instruction_ADD::create, {
REF(A), REF(E)});

register_opcode({0x84},{0x01}, Instruction_ADD::create, {
REF(A), REF(H)});

register_opcode({0x85},{0x01}, Instruction_ADD::create, {
REF(A), REF(L)});

register_opcode({0x09},{0x01}, Instruction_ADD::create, {
REF(HL), REF(BC)});

register_opcode({0x19},{0x01}, Instruction_ADD::create, {
REF(HL), REF(DE)});

register_opcode({0x29},{0x01}, Instruction_ADD::create, {
REF(HL), REF(HL)});

register_opcode({0x39},{0x01}, Instruction_ADD::create, {
REF(HL), REF(SP)});

register_opcode({0xdd,0x09},{0x01,0x01}, Instruction_ADD::create, {
REF(IX), REF(BC)});

register_opcode({0xdd,0x19},{0x01,0x01}, Instruction_ADD::create, {
REF(IX), REF(DE)});

register_opcode({0xdd,0x29},{0x01,0x01}, Instruction_ADD::create, {
REF(IX), REF(IX)});

register_opcode({0xdd,0x39},{0x01,0x01}, Instruction_ADD::create, {
REF(IX), REF(SP)});

register_opcode({0xfd,0x09},{0x01,0x01}, Instruction_ADD::create, {
REF(IY), REF(BC)});

register_opcode({0xfd,0x19},{0x01,0x01}, Instruction_ADD::create, {
REF(IY), REF(DE)});

register_opcode({0xfd,0x29},{0x01,0x01}, Instruction_ADD::create, {
REF(IY), REF(IY)});

register_opcode({0xfd,0x39},{0x01,0x01}, Instruction_ADD::create, {
REF(IY), REF(SP)});

register_opcode({0xe6,0x00},{0x01,0x00}, Instruction_AND::create, {
REF(A), REF(PC8_1)});

register_opcode({0xdd,0xa6,0x00},{0x01,0x01,0x00}, Instruction_AND::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0xa6,0x00},{0x01,0x01,0x00}, Instruction_AND::create, {
REF(A), REF((IY+::))});

register_opcode({0xa6},{0x01}, Instruction_AND::create, {
REF(A), REF((HL))});

register_opcode({0xa7},{0x01}, Instruction_AND::create, {
REF(A), REF(A)});

register_opcode({0xa0},{0x01}, Instruction_AND::create, {
REF(A), REF(B)});

register_opcode({0xa1},{0x01}, Instruction_AND::create, {
REF(A), REF(C)});

register_opcode({0xa2},{0x01}, Instruction_AND::create, {
REF(A), REF(D)});

register_opcode({0xa3},{0x01}, Instruction_AND::create, {
REF(A), REF(E)});

register_opcode({0xa4},{0x01}, Instruction_AND::create, {
REF(A), REF(H)});

register_opcode({0xa5},{0x01}, Instruction_AND::create, {
REF(A), REF(L)});

register_opcode({0xcb,0x46},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF((HL))});

register_opcode({0xcb,0x4e},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF((HL))});

register_opcode({0xcb,0x56},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF((HL))});

register_opcode({0xcb,0x5e},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF((HL))});

register_opcode({0xcb,0x66},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF((HL))});

register_opcode({0xcb,0x6e},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF((HL))});

register_opcode({0xcb,0x76},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF((HL))});

register_opcode({0xcb,0x7e},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x46},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(0), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x4e},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(1), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x56},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(2), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x5e},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(3), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x66},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(4), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x6e},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(5), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x76},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(6), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x7e},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(7), REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x40},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(0), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x48},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(1), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x50},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(2), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x58},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(3), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x60},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(4), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x68},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(5), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x70},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(6), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x78},{0x01,0x01,0x00,0x01}, Instruction_BIT::create, {
REF(7), REF((IY+::))});

register_opcode({0xcb,0x47},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(A)});

register_opcode({0xcb,0x4f},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(A)});

register_opcode({0xcb,0x57},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(A)});

register_opcode({0xcb,0x5f},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(A)});

register_opcode({0xcb,0x67},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(A)});

register_opcode({0xcb,0x6f},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(A)});

register_opcode({0xcb,0x77},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(A)});

register_opcode({0xcb,0x7f},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(A)});

register_opcode({0xcb,0x40},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(B)});

register_opcode({0xcb,0x48},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(B)});

register_opcode({0xcb,0x50},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(B)});

register_opcode({0xcb,0x58},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(B)});

register_opcode({0xcb,0x60},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(B)});

register_opcode({0xcb,0x68},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(B)});

register_opcode({0xcb,0x70},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(B)});

register_opcode({0xcb,0x78},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(B)});

register_opcode({0xcb,0x41},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(C)});

register_opcode({0xcb,0x49},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(C)});

register_opcode({0xcb,0x51},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(C)});

register_opcode({0xcb,0x59},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(C)});

register_opcode({0xcb,0x61},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(C)});

register_opcode({0xcb,0x69},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(C)});

register_opcode({0xcb,0x71},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(C)});

register_opcode({0xcb,0x79},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(C)});

register_opcode({0xcb,0x42},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(D)});

register_opcode({0xcb,0x4a},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(D)});

register_opcode({0xcb,0x52},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(D)});

register_opcode({0xcb,0x5a},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(D)});

register_opcode({0xcb,0x62},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(D)});

register_opcode({0xcb,0x6a},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(D)});

register_opcode({0xcb,0x72},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(D)});

register_opcode({0xcb,0x7a},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(D)});

register_opcode({0xcb,0x43},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(E)});

register_opcode({0xcb,0x4b},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(E)});

register_opcode({0xcb,0x53},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(E)});

register_opcode({0xcb,0x5b},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(E)});

register_opcode({0xcb,0x63},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(E)});

register_opcode({0xcb,0x6b},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(E)});

register_opcode({0xcb,0x73},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(E)});

register_opcode({0xcb,0x7b},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(E)});

register_opcode({0xcb,0x44},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(H)});

register_opcode({0xcb,0x4c},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(H)});

register_opcode({0xcb,0x54},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(H)});

register_opcode({0xcb,0x5c},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(H)});

register_opcode({0xcb,0x64},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(H)});

register_opcode({0xcb,0x6c},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(H)});

register_opcode({0xcb,0x74},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(H)});

register_opcode({0xcb,0x7c},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(H)});

register_opcode({0xcb,0x45},{0x01,0x01}, Instruction_BIT::create, {
REF(0), REF(L)});

register_opcode({0xcb,0x4d},{0x01,0x01}, Instruction_BIT::create, {
REF(1), REF(L)});

register_opcode({0xcb,0x55},{0x01,0x01}, Instruction_BIT::create, {
REF(2), REF(L)});

register_opcode({0xcb,0x5d},{0x01,0x01}, Instruction_BIT::create, {
REF(3), REF(L)});

register_opcode({0xcb,0x65},{0x01,0x01}, Instruction_BIT::create, {
REF(4), REF(L)});

register_opcode({0xcb,0x6d},{0x01,0x01}, Instruction_BIT::create, {
REF(5), REF(L)});

register_opcode({0xcb,0x75},{0x01,0x01}, Instruction_BIT::create, {
REF(6), REF(L)});

register_opcode({0xcb,0x7d},{0x01,0x01}, Instruction_BIT::create, {
REF(7), REF(L)});

register_opcode({0xcd,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
REF(PC16_1)});

register_opcode({0xdc,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(C), REF(PC16_1)});

register_opcode({0xfc,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(M), REF(PC16_1)});

register_opcode({0xd4,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(NC), REF(PC16_1)});

register_opcode({0xc4,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(NZ), REF(PC16_1)});

register_opcode({0xf4,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(P), REF(PC16_1)});

register_opcode({0xec,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(PE), REF(PC16_1)});

register_opcode({0xe4,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(PO), REF(PC16_1)});

register_opcode({0xcc,0x00,0x00},{0x01,0x00,0x00}, Instruction_CALL::create, {
FLAG(Z), REF(PC16_1)});

register_opcode({0x3f},{0x01}, Instruction_CCF::create, {
});

register_opcode({0xfe,0x00},{0x01,0x00}, Instruction_CP::create, {
REF(A), REF(PC8_1)});

register_opcode({0xdd,0xbe,0x00},{0x01,0x01,0x00}, Instruction_CP::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0xbe,0x00},{0x01,0x01,0x00}, Instruction_CP::create, {
REF(A), REF((IY+::))});

register_opcode({0xbe},{0x01}, Instruction_CP::create, {
REF(A), REF((HL))});

register_opcode({0xbf},{0x01}, Instruction_CP::create, {
REF(A), REF(A)});

register_opcode({0xb8},{0x01}, Instruction_CP::create, {
REF(A), REF(B)});

register_opcode({0xb9},{0x01}, Instruction_CP::create, {
REF(A), REF(C)});

register_opcode({0xba},{0x01}, Instruction_CP::create, {
REF(A), REF(D)});

register_opcode({0xbb},{0x01}, Instruction_CP::create, {
REF(A), REF(E)});

register_opcode({0xbc},{0x01}, Instruction_CP::create, {
REF(A), REF(H)});

register_opcode({0xbd},{0x01}, Instruction_CP::create, {
REF(A), REF(L)});

register_opcode({0xed,0xa9},{0x01,0x01}, Instruction_CPD::create, {
});

register_opcode({0xed,0xb9},{0x01,0x01}, Instruction_CPDR::create, {
});

register_opcode({0xed,0xa1},{0x01,0x01}, Instruction_CPI::create, {
});

register_opcode({0xed,0xb1},{0x01,0x01}, Instruction_CPIR::create, {
});

register_opcode({0x2f},{0x01}, Instruction_CPL::create, {
});

register_opcode({0x27},{0x01}, Instruction_DAA::create, {
});

register_opcode({0x35},{0x01}, Instruction_DEC::create, {
REF((HL))});

register_opcode({0xdd,0x35,0x00},{0x01,0x01,0x00}, Instruction_DEC::create, {
REF((IX+::))});

register_opcode({0xfd,0x35,0x00},{0x01,0x01,0x00}, Instruction_DEC::create, {
REF((IY+::))});

register_opcode({0x3d},{0x01}, Instruction_DEC::create, {
REF(A)});

register_opcode({0x05},{0x01}, Instruction_DEC::create, {
REF(B)});

register_opcode({0x0b},{0x01}, Instruction_DEC::create, {
REF(BC)});

register_opcode({0x0d},{0x01}, Instruction_DEC::create, {
REF(C)});

register_opcode({0x15},{0x01}, Instruction_DEC::create, {
REF(D)});

register_opcode({0x1b},{0x01}, Instruction_DEC::create, {
REF(DE)});

register_opcode({0x1d},{0x01}, Instruction_DEC::create, {
REF(E)});

register_opcode({0x25},{0x01}, Instruction_DEC::create, {
REF(H)});

register_opcode({0x2b},{0x01}, Instruction_DEC::create, {
REF(HL)});

register_opcode({0xdd,0x2b},{0x01,0x01}, Instruction_DEC::create, {
REF(IX)});

register_opcode({0xfd,0x2b},{0x01,0x01}, Instruction_DEC::create, {
REF(IY)});

register_opcode({0x2d},{0x01}, Instruction_DEC::create, {
REF(L)});

register_opcode({0x3b},{0x01}, Instruction_DEC::create, {
REF(SP)});

register_opcode({0xf3},{0x01}, Instruction_DI::create, {
});

register_opcode({0x10,0x00},{0x01,0x00}, Instruction_DJNZ::create, {
REF(SPC8_1)});

register_opcode({0xfb},{0x01}, Instruction_EI::create, {
});

register_opcode({0xe3},{0x01}, Instruction_EX::create, {
REF(W(SP)), REF(HL)});

register_opcode({0xdd,0xe3},{0x01,0x01}, Instruction_EX::create, {
REF(W(SP)), REF(IX)});

register_opcode({0xfd,0xe3},{0x01,0x01}, Instruction_EX::create, {
REF(W(SP)), REF(IY)});

register_opcode({0x08},{0x01}, Instruction_EX::create, {
REF(AF), REF(AFt)});

register_opcode({0xeb},{0x01}, Instruction_EX::create, {
REF(DE), REF(HL)});

register_opcode({0xd9},{0x01}, Instruction_EXX::create, {
});

register_opcode({0x76},{0x01}, Instruction_HALT::create, {
});

register_opcode({0xed,0x46},{0x01,0x01}, Instruction_IM::create, {
REF(0)});

register_opcode({0xed,0x56},{0x01,0x01}, Instruction_IM::create, {
REF(1)});

register_opcode({0xed,0x5e},{0x01,0x01}, Instruction_IM::create, {
REF(2)});

register_opcode({0xdb,0x00},{0x01,0x00}, Instruction_IN::create, {
REF(A), REF(PC8_1)});

register_opcode({0xed,0x78},{0x01,0x01}, Instruction_IN::create, {
REF(A), REF((C))});

register_opcode({0xed,0x40},{0x01,0x01}, Instruction_IN::create, {
REF(B), REF((C))});

register_opcode({0xed,0x48},{0x01,0x01}, Instruction_IN::create, {
REF(C), REF((C))});

register_opcode({0xed,0x50},{0x01,0x01}, Instruction_IN::create, {
REF(D), REF((C))});

register_opcode({0xed,0x58},{0x01,0x01}, Instruction_IN::create, {
REF(E), REF((C))});

register_opcode({0xed,0x60},{0x01,0x01}, Instruction_IN::create, {
REF(H), REF((C))});

register_opcode({0xed,0x68},{0x01,0x01}, Instruction_IN::create, {
REF(L), REF((C))});

register_opcode({0xed,0x70},{0x01,0x01}, Instruction_IN::create, {
REF(F), REF((C))});

register_opcode({0x34},{0x01}, Instruction_INC::create, {
REF((HL))});

register_opcode({0xdd,0x34,0x00},{0x01,0x01,0x00}, Instruction_INC::create, {
REF((IX+::))});

register_opcode({0xfd,0x34,0x00},{0x01,0x01,0x00}, Instruction_INC::create, {
REF((IY+::))});

register_opcode({0x3c},{0x01}, Instruction_INC::create, {
REF(A)});

register_opcode({0x04},{0x01}, Instruction_INC::create, {
REF(B)});

register_opcode({0x03},{0x01}, Instruction_INC::create, {
REF(BC)});

register_opcode({0x0c},{0x01}, Instruction_INC::create, {
REF(C)});

register_opcode({0x14},{0x01}, Instruction_INC::create, {
REF(D)});

register_opcode({0x13},{0x01}, Instruction_INC::create, {
REF(DE)});

register_opcode({0x1c},{0x01}, Instruction_INC::create, {
REF(E)});

register_opcode({0x24},{0x01}, Instruction_INC::create, {
REF(H)});

register_opcode({0x23},{0x01}, Instruction_INC::create, {
REF(HL)});

register_opcode({0xdd,0x23},{0x01,0x01}, Instruction_INC::create, {
REF(IX)});

register_opcode({0xfd,0x23},{0x01,0x01}, Instruction_INC::create, {
REF(IY)});

register_opcode({0x2c},{0x01}, Instruction_INC::create, {
REF(L)});

register_opcode({0x33},{0x01}, Instruction_INC::create, {
REF(SP)});

register_opcode({0xed,0xaa},{0x01,0x01}, Instruction_IND::create, {
});

register_opcode({0xed,0xba},{0x01,0x01}, Instruction_INDR::create, {
});

register_opcode({0xed,0xa2},{0x01,0x01}, Instruction_INI::create, {
});

register_opcode({0xed,0xb2},{0x01,0x01}, Instruction_INIR::create, {
});

register_opcode({0xe9},{0x01}, Instruction_JP::create, {
REF(HL)});

register_opcode({0xdd,0xe9},{0x01,0x01}, Instruction_JP::create, {
REF(IX)});

register_opcode({0xfd,0xe9},{0x01,0x01}, Instruction_JP::create, {
REF(IY)});

register_opcode({0xc3,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
REF(PC16_1)});

register_opcode({0xda,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(C), REF(PC16_1)});

register_opcode({0xfa,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(M), REF(PC16_1)});

register_opcode({0xd2,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(NC), REF(PC16_1)});

register_opcode({0xc2,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(NZ), REF(PC16_1)});

register_opcode({0xf2,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(P), REF(PC16_1)});

register_opcode({0xea,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(PE), REF(PC16_1)});

register_opcode({0xe2,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(PO), REF(PC16_1)});

register_opcode({0xca,0x00,0x00},{0x01,0x00,0x00}, Instruction_JP::create, {
FLAG(Z), REF(PC16_1)});

register_opcode({0x18,0x00},{0x01,0x00}, Instruction_JR::create, {
REF(SPC8_1)});

register_opcode({0x38,0x00},{0x01,0x00}, Instruction_JR::create, {
FLAG(C), REF(SPC8_1)});

register_opcode({0x30,0x00},{0x01,0x00}, Instruction_JR::create, {
FLAG(NC), REF(SPC8_1)});

register_opcode({0x20,0x00},{0x01,0x00}, Instruction_JR::create, {
FLAG(NZ), REF(SPC8_1)});

register_opcode({0x28,0x00},{0x01,0x00}, Instruction_JR::create, {
FLAG(Z), REF(SPC8_1)});

register_opcode({0x32,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(BPC16_1), REF(A)});

register_opcode({0xed,0x43,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(WPC16_2), REF(BC)});

register_opcode({0xed,0x53,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(WPC16_2), REF(DE)});

register_opcode({0x22,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(WPC16_1), REF(HL)});

register_opcode({0xdd,0x22,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(WPC16_2), REF(IX)});

register_opcode({0xfd,0x22,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(WPC16_2), REF(IY)});

register_opcode({0xed,0x73,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(WPC16_2), REF(SP)});

register_opcode({0x02},{0x01}, Instruction_LD::create, {
REF((BC)), REF(A)});

register_opcode({0x12},{0x01}, Instruction_LD::create, {
REF((DE)), REF(A)});

register_opcode({0x36,0x00},{0x01,0x00}, Instruction_LD::create, {
REF((HL)), REF(PC8_1)});

register_opcode({0x77},{0x01}, Instruction_LD::create, {
REF((HL)), REF(A)});

register_opcode({0x70},{0x01}, Instruction_LD::create, {
REF((HL)), REF(B)});

register_opcode({0x71},{0x01}, Instruction_LD::create, {
REF((HL)), REF(C)});

register_opcode({0x72},{0x01}, Instruction_LD::create, {
REF((HL)), REF(D)});

register_opcode({0x73},{0x01}, Instruction_LD::create, {
REF((HL)), REF(E)});

register_opcode({0x74},{0x01}, Instruction_LD::create, {
REF((HL)), REF(H)});

register_opcode({0x75},{0x01}, Instruction_LD::create, {
REF((HL)), REF(L)});

register_opcode({0xdd,0x36,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(PC8_3)});

register_opcode({0xdd,0x77,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(A)});

register_opcode({0xdd,0x70,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(B)});

register_opcode({0xdd,0x71,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(C)});

register_opcode({0xdd,0x72,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(D)});

register_opcode({0xdd,0x73,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(E)});

register_opcode({0xdd,0x74,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(H)});

register_opcode({0xdd,0x75,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IX+::)), REF(L)});

register_opcode({0xfd,0x36,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(PC8_3)});

register_opcode({0xfd,0x77,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(A)});

register_opcode({0xfd,0x70,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(B)});

register_opcode({0xfd,0x71,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(C)});

register_opcode({0xfd,0x72,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(D)});

register_opcode({0xfd,0x73,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(E)});

register_opcode({0xfd,0x74,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(H)});

register_opcode({0xfd,0x75,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF((IY+::)), REF(L)});

register_opcode({0x3e,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(A), REF(PC8_1)});

register_opcode({0x3a,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(A), REF(BPC16_1)});

register_opcode({0x0a},{0x01}, Instruction_LD::create, {
REF(A), REF((BC))});

register_opcode({0x1a},{0x01}, Instruction_LD::create, {
REF(A), REF((DE))});

register_opcode({0x7e},{0x01}, Instruction_LD::create, {
REF(A), REF((HL))});

register_opcode({0xdd,0x7e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0x7e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(A), REF((IY+::))});

register_opcode({0x7f},{0x01}, Instruction_LD::create, {
REF(A), REF(A)});

register_opcode({0x78},{0x01}, Instruction_LD::create, {
REF(A), REF(B)});

register_opcode({0x79},{0x01}, Instruction_LD::create, {
REF(A), REF(C)});

register_opcode({0x7a},{0x01}, Instruction_LD::create, {
REF(A), REF(D)});

register_opcode({0x7b},{0x01}, Instruction_LD::create, {
REF(A), REF(E)});

register_opcode({0x7c},{0x01}, Instruction_LD::create, {
REF(A), REF(H)});

register_opcode({0xed,0x57},{0x01,0x01}, Instruction_LD::create, {
REF(A), REF(I)});

register_opcode({0x7d},{0x01}, Instruction_LD::create, {
REF(A), REF(L)});

register_opcode({0xed,0x5f},{0x01,0x01}, Instruction_LD::create, {
REF(A), REF(R)});

register_opcode({0x06,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(B), REF(PC8_1)});

register_opcode({0x46},{0x01}, Instruction_LD::create, {
REF(B), REF((HL))});

register_opcode({0xdd,0x46,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(B), REF((IX+::))});

register_opcode({0xfd,0x46,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(B), REF((IY+::))});

register_opcode({0x47},{0x01}, Instruction_LD::create, {
REF(B), REF(A)});

register_opcode({0x40},{0x01}, Instruction_LD::create, {
REF(B), REF(B)});

register_opcode({0x41},{0x01}, Instruction_LD::create, {
REF(B), REF(C)});

register_opcode({0x42},{0x01}, Instruction_LD::create, {
REF(B), REF(D)});

register_opcode({0x43},{0x01}, Instruction_LD::create, {
REF(B), REF(E)});

register_opcode({0x44},{0x01}, Instruction_LD::create, {
REF(B), REF(H)});

register_opcode({0x45},{0x01}, Instruction_LD::create, {
REF(B), REF(L)});

register_opcode({0xed,0x4b,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(BC), REF(WPC16_2)});

register_opcode({0x01,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(BC), REF(PC16_1)});

register_opcode({0x0e,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(C), REF(PC8_1)});

register_opcode({0x4e},{0x01}, Instruction_LD::create, {
REF(C), REF((HL))});

register_opcode({0xdd,0x4e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(C), REF((IX+::))});

register_opcode({0xfd,0x4e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(C), REF((IY+::))});

register_opcode({0x4f},{0x01}, Instruction_LD::create, {
REF(C), REF(A)});

register_opcode({0x48},{0x01}, Instruction_LD::create, {
REF(C), REF(B)});

register_opcode({0x49},{0x01}, Instruction_LD::create, {
REF(C), REF(C)});

register_opcode({0x4a},{0x01}, Instruction_LD::create, {
REF(C), REF(D)});

register_opcode({0x4b},{0x01}, Instruction_LD::create, {
REF(C), REF(E)});

register_opcode({0x4c},{0x01}, Instruction_LD::create, {
REF(C), REF(H)});

register_opcode({0x4d},{0x01}, Instruction_LD::create, {
REF(C), REF(L)});

register_opcode({0x16,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(D), REF(PC8_1)});

register_opcode({0x56},{0x01}, Instruction_LD::create, {
REF(D), REF((HL))});

register_opcode({0xdd,0x56,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(D), REF((IX+::))});

register_opcode({0xfd,0x56,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(D), REF((IY+::))});

register_opcode({0x57},{0x01}, Instruction_LD::create, {
REF(D), REF(A)});

register_opcode({0x50},{0x01}, Instruction_LD::create, {
REF(D), REF(B)});

register_opcode({0x51},{0x01}, Instruction_LD::create, {
REF(D), REF(C)});

register_opcode({0x52},{0x01}, Instruction_LD::create, {
REF(D), REF(D)});

register_opcode({0x53},{0x01}, Instruction_LD::create, {
REF(D), REF(E)});

register_opcode({0x54},{0x01}, Instruction_LD::create, {
REF(D), REF(H)});

register_opcode({0x55},{0x01}, Instruction_LD::create, {
REF(D), REF(L)});

register_opcode({0xed,0x5b,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(DE), REF(WPC16_2)});

register_opcode({0x11,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(DE), REF(PC16_1)});

register_opcode({0x1e,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(E), REF(PC8_1)});

register_opcode({0x5e},{0x01}, Instruction_LD::create, {
REF(E), REF((HL))});

register_opcode({0xdd,0x5e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(E), REF((IX+::))});

register_opcode({0xfd,0x5e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(E), REF((IY+::))});

register_opcode({0x5f},{0x01}, Instruction_LD::create, {
REF(E), REF(A)});

register_opcode({0x58},{0x01}, Instruction_LD::create, {
REF(E), REF(B)});

register_opcode({0x59},{0x01}, Instruction_LD::create, {
REF(E), REF(C)});

register_opcode({0x5a},{0x01}, Instruction_LD::create, {
REF(E), REF(D)});

register_opcode({0x5b},{0x01}, Instruction_LD::create, {
REF(E), REF(E)});

register_opcode({0x5c},{0x01}, Instruction_LD::create, {
REF(E), REF(H)});

register_opcode({0x5d},{0x01}, Instruction_LD::create, {
REF(E), REF(L)});

register_opcode({0x26,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(H), REF(PC8_1)});

register_opcode({0x66},{0x01}, Instruction_LD::create, {
REF(H), REF((HL))});

register_opcode({0xdd,0x66,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(H), REF((IX+::))});

register_opcode({0xfd,0x66,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(H), REF((IY+::))});

register_opcode({0x67},{0x01}, Instruction_LD::create, {
REF(H), REF(A)});

register_opcode({0x60},{0x01}, Instruction_LD::create, {
REF(H), REF(B)});

register_opcode({0x61},{0x01}, Instruction_LD::create, {
REF(H), REF(C)});

register_opcode({0x62},{0x01}, Instruction_LD::create, {
REF(H), REF(D)});

register_opcode({0x63},{0x01}, Instruction_LD::create, {
REF(H), REF(E)});

register_opcode({0x64},{0x01}, Instruction_LD::create, {
REF(H), REF(H)});

register_opcode({0x65},{0x01}, Instruction_LD::create, {
REF(H), REF(L)});

register_opcode({0x2a,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(HL), REF(WPC16_1)});

register_opcode({0x21,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(HL), REF(PC16_1)});

register_opcode({0xed,0x47},{0x01,0x01}, Instruction_LD::create, {
REF(I), REF(A)});

register_opcode({0xdd,0x2a,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(IX), REF(WPC16_2)});

register_opcode({0xdd,0x21,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(IX), REF(PC16_2)});

register_opcode({0xfd,0x2a,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(IY), REF(WPC16_2)});

register_opcode({0xfd,0x21,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(IY), REF(PC16_2)});

register_opcode({0x2e,0x00},{0x01,0x00}, Instruction_LD::create, {
REF(L), REF(PC8_1)});

register_opcode({0x6e},{0x01}, Instruction_LD::create, {
REF(L), REF((HL))});

register_opcode({0xdd,0x6e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(L), REF((IX+::))});

register_opcode({0xfd,0x6e,0x00},{0x01,0x01,0x00}, Instruction_LD::create, {
REF(L), REF((IY+::))});

register_opcode({0x6f},{0x01}, Instruction_LD::create, {
REF(L), REF(A)});

register_opcode({0x68},{0x01}, Instruction_LD::create, {
REF(L), REF(B)});

register_opcode({0x69},{0x01}, Instruction_LD::create, {
REF(L), REF(C)});

register_opcode({0x6a},{0x01}, Instruction_LD::create, {
REF(L), REF(D)});

register_opcode({0x6b},{0x01}, Instruction_LD::create, {
REF(L), REF(E)});

register_opcode({0x6c},{0x01}, Instruction_LD::create, {
REF(L), REF(H)});

register_opcode({0x6d},{0x01}, Instruction_LD::create, {
REF(L), REF(L)});

register_opcode({0xed,0x7b,0x00,0x00},{0x01,0x01,0x00,0x00}, Instruction_LD::create, {
REF(SP), REF(WPC16_2)});

register_opcode({0x31,0x00,0x00},{0x01,0x00,0x00}, Instruction_LD::create, {
REF(SP), REF(PC16_1)});

register_opcode({0xf9},{0x01}, Instruction_LD::create, {
REF(SP), REF(HL)});

register_opcode({0xdd,0xf9},{0x01,0x01}, Instruction_LD::create, {
REF(SP), REF(IX)});

register_opcode({0xfd,0xf9},{0x01,0x01}, Instruction_LD::create, {
REF(SP), REF(IY)});

register_opcode({0xed,0x4f},{0x01,0x01}, Instruction_LD::create, {
REF(R), REF(A)});

register_opcode({0xed,0xa8},{0x01,0x01}, Instruction_LDD::create, {
});

register_opcode({0xed,0xb8},{0x01,0x01}, Instruction_LDDR::create, {
});

register_opcode({0xed,0xa0},{0x01,0x01}, Instruction_LDI::create, {
});

register_opcode({0xed,0xb0},{0x01,0x01}, Instruction_LDIR::create, {
});

register_opcode({0xed,0x44},{0x01,0x01}, Instruction_NEG::create, {
});

register_opcode({0x00},{0x01}, Instruction_NOP::create, {
});

register_opcode({0xf6,0x00},{0x01,0x00}, Instruction_OR::create, {
REF(A), REF(PC8_1)});

register_opcode({0xdd,0xb6,0x00},{0x01,0x01,0x00}, Instruction_OR::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0xb6,0x00},{0x01,0x01,0x00}, Instruction_OR::create, {
REF(A), REF((IY+::))});

register_opcode({0xb6},{0x01}, Instruction_OR::create, {
REF(A), REF((HL))});

register_opcode({0xb7},{0x01}, Instruction_OR::create, {
REF(A), REF(A)});

register_opcode({0xb0},{0x01}, Instruction_OR::create, {
REF(A), REF(B)});

register_opcode({0xb1},{0x01}, Instruction_OR::create, {
REF(A), REF(C)});

register_opcode({0xb2},{0x01}, Instruction_OR::create, {
REF(A), REF(D)});

register_opcode({0xb3},{0x01}, Instruction_OR::create, {
REF(A), REF(E)});

register_opcode({0xb4},{0x01}, Instruction_OR::create, {
REF(A), REF(H)});

register_opcode({0xb5},{0x01}, Instruction_OR::create, {
REF(A), REF(L)});

register_opcode({0xed,0xbb},{0x01,0x01}, Instruction_OTDR::create, {
});

register_opcode({0xed,0xb3},{0x01,0x01}, Instruction_OTIR::create, {
});

register_opcode({0xd3,0x00},{0x01,0x00}, Instruction_OUT::create, {
REF(PC8_1), REF(A)});

register_opcode({0xed,0x71},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(0)});

register_opcode({0xed,0x79},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(A)});

register_opcode({0xed,0x41},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(B)});

register_opcode({0xed,0x49},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(C)});

register_opcode({0xed,0x51},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(D)});

register_opcode({0xed,0x59},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(E)});

register_opcode({0xed,0x61},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(H)});

register_opcode({0xed,0x69},{0x01,0x01}, Instruction_OUT::create, {
REF((C)), REF(L)});

register_opcode({0xed,0xab},{0x01,0x01}, Instruction_OUTD::create, {
});

register_opcode({0xed,0xa3},{0x01,0x01}, Instruction_OUTI::create, {
});

register_opcode({0xf1},{0x01}, Instruction_POP::create, {
REF(AF)});

register_opcode({0xc1},{0x01}, Instruction_POP::create, {
REF(BC)});

register_opcode({0xd1},{0x01}, Instruction_POP::create, {
REF(DE)});

register_opcode({0xe1},{0x01}, Instruction_POP::create, {
REF(HL)});

register_opcode({0xdd,0xe1},{0x01,0x01}, Instruction_POP::create, {
REF(IX)});

register_opcode({0xfd,0xe1},{0x01,0x01}, Instruction_POP::create, {
REF(IY)});

register_opcode({0xf5},{0x01}, Instruction_PUSH::create, {
REF(AF)});

register_opcode({0xc5},{0x01}, Instruction_PUSH::create, {
REF(BC)});

register_opcode({0xd5},{0x01}, Instruction_PUSH::create, {
REF(DE)});

register_opcode({0xe5},{0x01}, Instruction_PUSH::create, {
REF(HL)});

register_opcode({0xdd,0xe5},{0x01,0x01}, Instruction_PUSH::create, {
REF(IX)});

register_opcode({0xfd,0xe5},{0x01,0x01}, Instruction_PUSH::create, {
REF(IY)});

register_opcode({0xcb,0x86},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF((HL))});

register_opcode({0xcb,0x8e},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF((HL))});

register_opcode({0xcb,0x96},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF((HL))});

register_opcode({0xcb,0x9e},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF((HL))});

register_opcode({0xcb,0xa6},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF((HL))});

register_opcode({0xcb,0xae},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF((HL))});

register_opcode({0xcb,0xb6},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF((HL))});

register_opcode({0xcb,0xbe},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x86},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(0), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x8e},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(1), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x96},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(2), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0x9e},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(3), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xa6},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(4), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xae},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(5), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xb6},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(6), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xbe},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(7), REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x86},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(0), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x8e},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(1), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x96},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(2), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0x9e},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(3), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xa6},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(4), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xae},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(5), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xb6},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(6), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xbe},{0x01,0x01,0x00,0x01}, Instruction_RES::create, {
REF(7), REF((IY+::))});

register_opcode({0xcb,0x87},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(A)});

register_opcode({0xcb,0x8f},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(A)});

register_opcode({0xcb,0x97},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(A)});

register_opcode({0xcb,0x9f},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(A)});

register_opcode({0xcb,0xa7},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(A)});

register_opcode({0xcb,0xaf},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(A)});

register_opcode({0xcb,0xb7},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(A)});

register_opcode({0xcb,0xbf},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(A)});

register_opcode({0xcb,0x80},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(B)});

register_opcode({0xcb,0x88},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(B)});

register_opcode({0xcb,0x90},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(B)});

register_opcode({0xcb,0x98},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(B)});

register_opcode({0xcb,0xa0},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(B)});

register_opcode({0xcb,0xa8},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(B)});

register_opcode({0xcb,0xb0},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(B)});

register_opcode({0xcb,0xb8},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(B)});

register_opcode({0xcb,0x81},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(C)});

register_opcode({0xcb,0x89},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(C)});

register_opcode({0xcb,0x91},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(C)});

register_opcode({0xcb,0x99},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(C)});

register_opcode({0xcb,0xa1},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(C)});

register_opcode({0xcb,0xa9},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(C)});

register_opcode({0xcb,0xb1},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(C)});

register_opcode({0xcb,0xb9},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(C)});

register_opcode({0xcb,0x82},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(D)});

register_opcode({0xcb,0x8a},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(D)});

register_opcode({0xcb,0x92},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(D)});

register_opcode({0xcb,0x9a},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(D)});

register_opcode({0xcb,0xa2},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(D)});

register_opcode({0xcb,0xaa},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(D)});

register_opcode({0xcb,0xb2},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(D)});

register_opcode({0xcb,0xba},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(D)});

register_opcode({0xcb,0x83},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(E)});

register_opcode({0xcb,0x8b},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(E)});

register_opcode({0xcb,0x93},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(E)});

register_opcode({0xcb,0x9b},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(E)});

register_opcode({0xcb,0xa3},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(E)});

register_opcode({0xcb,0xab},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(E)});

register_opcode({0xcb,0xb3},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(E)});

register_opcode({0xcb,0xbb},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(E)});

register_opcode({0xcb,0x84},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(H)});

register_opcode({0xcb,0x8c},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(H)});

register_opcode({0xcb,0x94},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(H)});

register_opcode({0xcb,0x9c},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(H)});

register_opcode({0xcb,0xa4},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(H)});

register_opcode({0xcb,0xac},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(H)});

register_opcode({0xcb,0xb4},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(H)});

register_opcode({0xcb,0xbc},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(H)});

register_opcode({0xcb,0x85},{0x01,0x01}, Instruction_RES::create, {
REF(0), REF(L)});

register_opcode({0xcb,0x8d},{0x01,0x01}, Instruction_RES::create, {
REF(1), REF(L)});

register_opcode({0xcb,0x95},{0x01,0x01}, Instruction_RES::create, {
REF(2), REF(L)});

register_opcode({0xcb,0x9d},{0x01,0x01}, Instruction_RES::create, {
REF(3), REF(L)});

register_opcode({0xcb,0xa5},{0x01,0x01}, Instruction_RES::create, {
REF(4), REF(L)});

register_opcode({0xcb,0xad},{0x01,0x01}, Instruction_RES::create, {
REF(5), REF(L)});

register_opcode({0xcb,0xb5},{0x01,0x01}, Instruction_RES::create, {
REF(6), REF(L)});

register_opcode({0xcb,0xbd},{0x01,0x01}, Instruction_RES::create, {
REF(7), REF(L)});

register_opcode({0xc9},{0x01}, Instruction_RET::create, {
});

register_opcode({0xd8},{0x01}, Instruction_RET::create, {
FLAG(C)});

register_opcode({0xf8},{0x01}, Instruction_RET::create, {
FLAG(M)});

register_opcode({0xd0},{0x01}, Instruction_RET::create, {
FLAG(NC)});

register_opcode({0xc0},{0x01}, Instruction_RET::create, {
FLAG(NZ)});

register_opcode({0xf0},{0x01}, Instruction_RET::create, {
FLAG(P)});

register_opcode({0xe8},{0x01}, Instruction_RET::create, {
FLAG(PE)});

register_opcode({0xe0},{0x01}, Instruction_RET::create, {
FLAG(PO)});

register_opcode({0xc8},{0x01}, Instruction_RET::create, {
FLAG(Z)});

register_opcode({0xed,0x4d},{0x01,0x01}, Instruction_RETI::create, {
});

register_opcode({0xed,0x45},{0x01,0x01}, Instruction_RETN::create, {
});

register_opcode({0xcb,0x16},{0x01,0x01}, Instruction_RL::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x16},{0x01,0x01,0x00,0x01}, Instruction_RL::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x16},{0x01,0x01,0x00,0x01}, Instruction_RL::create, {
REF((IY+::))});

register_opcode({0xcb,0x17},{0x01,0x01}, Instruction_RL::create, {
REF(A)});

register_opcode({0xcb,0x10},{0x01,0x01}, Instruction_RL::create, {
REF(B)});

register_opcode({0xcb,0x11},{0x01,0x01}, Instruction_RL::create, {
REF(C)});

register_opcode({0xcb,0x12},{0x01,0x01}, Instruction_RL::create, {
REF(D)});

register_opcode({0xcb,0x13},{0x01,0x01}, Instruction_RL::create, {
REF(E)});

register_opcode({0xcb,0x14},{0x01,0x01}, Instruction_RL::create, {
REF(H)});

register_opcode({0xcb,0x15},{0x01,0x01}, Instruction_RL::create, {
REF(L)});

register_opcode({0x17},{0x01}, Instruction_RLA::create, {
});

register_opcode({0xcb,0x06},{0x01,0x01}, Instruction_RLC::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x06},{0x01,0x01,0x00,0x01}, Instruction_RLC::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x06},{0x01,0x01,0x00,0x01}, Instruction_RLC::create, {
REF((IY+::))});

register_opcode({0xcb,0x07},{0x01,0x01}, Instruction_RLC::create, {
REF(A)});

register_opcode({0xcb,0x00},{0x01,0x01}, Instruction_RLC::create, {
REF(B)});

register_opcode({0xcb,0x01},{0x01,0x01}, Instruction_RLC::create, {
REF(C)});

register_opcode({0xcb,0x02},{0x01,0x01}, Instruction_RLC::create, {
REF(D)});

register_opcode({0xcb,0x03},{0x01,0x01}, Instruction_RLC::create, {
REF(E)});

register_opcode({0xcb,0x04},{0x01,0x01}, Instruction_RLC::create, {
REF(H)});

register_opcode({0xcb,0x05},{0x01,0x01}, Instruction_RLC::create, {
REF(L)});

register_opcode({0x07},{0x01}, Instruction_RLCA::create, {
});

register_opcode({0xed,0x6f},{0x01,0x01}, Instruction_RLD::create, {
});

register_opcode({0xcb,0x1e},{0x01,0x01}, Instruction_RR::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x1e},{0x01,0x01,0x00,0x01}, Instruction_RR::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x1e},{0x01,0x01,0x00,0x01}, Instruction_RR::create, {
REF((IY+::))});

register_opcode({0xcb,0x1f},{0x01,0x01}, Instruction_RR::create, {
REF(A)});

register_opcode({0xcb,0x18},{0x01,0x01}, Instruction_RR::create, {
REF(B)});

register_opcode({0xcb,0x19},{0x01,0x01}, Instruction_RR::create, {
REF(C)});

register_opcode({0xcb,0x1a},{0x01,0x01}, Instruction_RR::create, {
REF(D)});

register_opcode({0xcb,0x1b},{0x01,0x01}, Instruction_RR::create, {
REF(E)});

register_opcode({0xcb,0x1c},{0x01,0x01}, Instruction_RR::create, {
REF(H)});

register_opcode({0xcb,0x1d},{0x01,0x01}, Instruction_RR::create, {
REF(L)});

register_opcode({0x1f},{0x01}, Instruction_RRA::create, {
});

register_opcode({0xcb,0x0e},{0x01,0x01}, Instruction_RRC::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x0e},{0x01,0x01,0x00,0x01}, Instruction_RRC::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x0e},{0x01,0x01,0x00,0x01}, Instruction_RRC::create, {
REF((IY+::))});

register_opcode({0xcb,0x0f},{0x01,0x01}, Instruction_RRC::create, {
REF(A)});

register_opcode({0xcb,0x08},{0x01,0x01}, Instruction_RRC::create, {
REF(B)});

register_opcode({0xcb,0x09},{0x01,0x01}, Instruction_RRC::create, {
REF(C)});

register_opcode({0xcb,0x0a},{0x01,0x01}, Instruction_RRC::create, {
REF(D)});

register_opcode({0xcb,0x0b},{0x01,0x01}, Instruction_RRC::create, {
REF(E)});

register_opcode({0xcb,0x0c},{0x01,0x01}, Instruction_RRC::create, {
REF(H)});

register_opcode({0xcb,0x0d},{0x01,0x01}, Instruction_RRC::create, {
REF(L)});

register_opcode({0x0f},{0x01}, Instruction_RRCA::create, {
});

register_opcode({0xed,0x67},{0x01,0x01}, Instruction_RRD::create, {
});

register_opcode({0xc7},{0x01}, Instruction_RST::create, {
REF(0)});

register_opcode({0xcf},{0x01}, Instruction_RST::create, {
REF(1)});

register_opcode({0xd7},{0x01}, Instruction_RST::create, {
REF(2)});

register_opcode({0xdf},{0x01}, Instruction_RST::create, {
REF(3)});

register_opcode({0xe7},{0x01}, Instruction_RST::create, {
REF(4)});

register_opcode({0xef},{0x01}, Instruction_RST::create, {
REF(5)});

register_opcode({0xf7},{0x01}, Instruction_RST::create, {
REF(6)});

register_opcode({0xff},{0x01}, Instruction_RST::create, {
REF(7)});

register_opcode({0xde,0x00},{0x01,0x00}, Instruction_SBC::create, {
REF(A), REF(PC8_1)});

register_opcode({0x9e},{0x01}, Instruction_SBC::create, {
REF(A), REF((HL))});

register_opcode({0xdd,0x9e,0x00},{0x01,0x01,0x00}, Instruction_SBC::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0x9e,0x00},{0x01,0x01,0x00}, Instruction_SBC::create, {
REF(A), REF((IY+::))});

register_opcode({0x9f},{0x01}, Instruction_SBC::create, {
REF(A), REF(A)});

register_opcode({0x98},{0x01}, Instruction_SBC::create, {
REF(A), REF(B)});

register_opcode({0x99},{0x01}, Instruction_SBC::create, {
REF(A), REF(C)});

register_opcode({0x9a},{0x01}, Instruction_SBC::create, {
REF(A), REF(D)});

register_opcode({0x9b},{0x01}, Instruction_SBC::create, {
REF(A), REF(E)});

register_opcode({0x9c},{0x01}, Instruction_SBC::create, {
REF(A), REF(H)});

register_opcode({0x9d},{0x01}, Instruction_SBC::create, {
REF(A), REF(L)});

register_opcode({0xed,0x42},{0x01,0x01}, Instruction_SBC::create, {
REF(HL), REF(BC)});

register_opcode({0xed,0x52},{0x01,0x01}, Instruction_SBC::create, {
REF(HL), REF(DE)});

register_opcode({0xed,0x62},{0x01,0x01}, Instruction_SBC::create, {
REF(HL), REF(HL)});

register_opcode({0xed,0x72},{0x01,0x01}, Instruction_SBC::create, {
REF(HL), REF(SP)});

register_opcode({0x37},{0x01}, Instruction_SCF::create, {
});

register_opcode({0xcb,0xc6},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF((HL))});

register_opcode({0xcb,0xce},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF((HL))});

register_opcode({0xcb,0xd6},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF((HL))});

register_opcode({0xcb,0xde},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF((HL))});

register_opcode({0xcb,0xe6},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF((HL))});

register_opcode({0xcb,0xee},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF((HL))});

register_opcode({0xcb,0xf6},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF((HL))});

register_opcode({0xcb,0xfe},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF((HL))});

register_opcode({0xdd,0xcb,0x00,0xc6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(0), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xce},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(1), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xd6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(2), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xde},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(3), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xe6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(4), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xee},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(5), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xf6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(6), REF((IX+::))});

register_opcode({0xdd,0xcb,0x00,0xfe},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(7), REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0xc6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(0), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xce},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(1), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xd6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(2), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xde},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(3), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xe6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(4), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xee},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(5), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xf6},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(6), REF((IY+::))});

register_opcode({0xfd,0xcb,0x00,0xfe},{0x01,0x01,0x00,0x01}, Instruction_SET::create, {
REF(7), REF((IY+::))});

register_opcode({0xcb,0xc7},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(A)});

register_opcode({0xcb,0xcf},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(A)});

register_opcode({0xcb,0xd7},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(A)});

register_opcode({0xcb,0xdf},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(A)});

register_opcode({0xcb,0xe7},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(A)});

register_opcode({0xcb,0xef},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(A)});

register_opcode({0xcb,0xf7},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(A)});

register_opcode({0xcb,0xff},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(A)});

register_opcode({0xcb,0xc0},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(B)});

register_opcode({0xcb,0xc8},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(B)});

register_opcode({0xcb,0xd0},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(B)});

register_opcode({0xcb,0xd8},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(B)});

register_opcode({0xcb,0xe0},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(B)});

register_opcode({0xcb,0xe8},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(B)});

register_opcode({0xcb,0xf0},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(B)});

register_opcode({0xcb,0xf8},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(B)});

register_opcode({0xcb,0xc1},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(C)});

register_opcode({0xcb,0xc9},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(C)});

register_opcode({0xcb,0xd1},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(C)});

register_opcode({0xcb,0xd9},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(C)});

register_opcode({0xcb,0xe1},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(C)});

register_opcode({0xcb,0xe9},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(C)});

register_opcode({0xcb,0xf1},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(C)});

register_opcode({0xcb,0xf9},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(C)});

register_opcode({0xcb,0xc2},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(D)});

register_opcode({0xcb,0xca},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(D)});

register_opcode({0xcb,0xd2},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(D)});

register_opcode({0xcb,0xda},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(D)});

register_opcode({0xcb,0xe2},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(D)});

register_opcode({0xcb,0xea},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(D)});

register_opcode({0xcb,0xf2},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(D)});

register_opcode({0xcb,0xfa},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(D)});

register_opcode({0xcb,0xc3},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(E)});

register_opcode({0xcb,0xcb},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(E)});

register_opcode({0xcb,0xd3},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(E)});

register_opcode({0xcb,0xdb},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(E)});

register_opcode({0xcb,0xe3},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(E)});

register_opcode({0xcb,0xeb},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(E)});

register_opcode({0xcb,0xf3},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(E)});

register_opcode({0xcb,0xfb},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(E)});

register_opcode({0xcb,0xc4},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(H)});

register_opcode({0xcb,0xcc},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(H)});

register_opcode({0xcb,0xd4},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(H)});

register_opcode({0xcb,0xdc},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(H)});

register_opcode({0xcb,0xe4},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(H)});

register_opcode({0xcb,0xec},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(H)});

register_opcode({0xcb,0xf4},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(H)});

register_opcode({0xcb,0xfc},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(H)});

register_opcode({0xcb,0xc5},{0x01,0x01}, Instruction_SET::create, {
REF(0), REF(L)});

register_opcode({0xcb,0xcd},{0x01,0x01}, Instruction_SET::create, {
REF(1), REF(L)});

register_opcode({0xcb,0xd5},{0x01,0x01}, Instruction_SET::create, {
REF(2), REF(L)});

register_opcode({0xcb,0xdd},{0x01,0x01}, Instruction_SET::create, {
REF(3), REF(L)});

register_opcode({0xcb,0xe5},{0x01,0x01}, Instruction_SET::create, {
REF(4), REF(L)});

register_opcode({0xcb,0xed},{0x01,0x01}, Instruction_SET::create, {
REF(5), REF(L)});

register_opcode({0xcb,0xf5},{0x01,0x01}, Instruction_SET::create, {
REF(6), REF(L)});

register_opcode({0xcb,0xfd},{0x01,0x01}, Instruction_SET::create, {
REF(7), REF(L)});

register_opcode({0xcb,0x26},{0x01,0x01}, Instruction_SLA::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x26},{0x01,0x01,0x00,0x01}, Instruction_SLA::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x26},{0x01,0x01,0x00,0x01}, Instruction_SLA::create, {
REF((IY+::))});

register_opcode({0xcb,0x27},{0x01,0x01}, Instruction_SLA::create, {
REF(A)});

register_opcode({0xcb,0x20},{0x01,0x01}, Instruction_SLA::create, {
REF(B)});

register_opcode({0xcb,0x21},{0x01,0x01}, Instruction_SLA::create, {
REF(C)});

register_opcode({0xcb,0x22},{0x01,0x01}, Instruction_SLA::create, {
REF(D)});

register_opcode({0xcb,0x23},{0x01,0x01}, Instruction_SLA::create, {
REF(E)});

register_opcode({0xcb,0x24},{0x01,0x01}, Instruction_SLA::create, {
REF(H)});

register_opcode({0xcb,0x25},{0x01,0x01}, Instruction_SLA::create, {
REF(L)});

register_opcode({0xcb,0x2e},{0x01,0x01}, Instruction_SRA::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x2e},{0x01,0x01,0x00,0x01}, Instruction_SRA::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x2e},{0x01,0x01,0x00,0x01}, Instruction_SRA::create, {
REF((IY+::))});

register_opcode({0xcb,0x2f},{0x01,0x01}, Instruction_SRA::create, {
REF(A)});

register_opcode({0xcb,0x28},{0x01,0x01}, Instruction_SRA::create, {
REF(B)});

register_opcode({0xcb,0x29},{0x01,0x01}, Instruction_SRA::create, {
REF(C)});

register_opcode({0xcb,0x2a},{0x01,0x01}, Instruction_SRA::create, {
REF(D)});

register_opcode({0xcb,0x2b},{0x01,0x01}, Instruction_SRA::create, {
REF(E)});

register_opcode({0xcb,0x2c},{0x01,0x01}, Instruction_SRA::create, {
REF(H)});

register_opcode({0xcb,0x2d},{0x01,0x01}, Instruction_SRA::create, {
REF(L)});

register_opcode({0xcb,0x3e},{0x01,0x01}, Instruction_SRL::create, {
REF((HL))});

register_opcode({0xdd,0xcb,0x00,0x3e},{0x01,0x01,0x00,0x01}, Instruction_SRL::create, {
REF((IX+::))});

register_opcode({0xfd,0xcb,0x00,0x3e},{0x01,0x01,0x00,0x01}, Instruction_SRL::create, {
REF((IY+::))});

register_opcode({0xcb,0x3f},{0x01,0x01}, Instruction_SRL::create, {
REF(A)});

register_opcode({0xcb,0x38},{0x01,0x01}, Instruction_SRL::create, {
REF(B)});

register_opcode({0xcb,0x39},{0x01,0x01}, Instruction_SRL::create, {
REF(C)});

register_opcode({0xcb,0x3a},{0x01,0x01}, Instruction_SRL::create, {
REF(D)});

register_opcode({0xcb,0x3b},{0x01,0x01}, Instruction_SRL::create, {
REF(E)});

register_opcode({0xcb,0x3c},{0x01,0x01}, Instruction_SRL::create, {
REF(H)});

register_opcode({0xcb,0x3d},{0x01,0x01}, Instruction_SRL::create, {
REF(L)});

register_opcode({0xd6,0x00},{0x01,0x00}, Instruction_SUB::create, {
REF(A), REF(PC8_1)});

register_opcode({0xdd,0x96,0x00},{0x01,0x01,0x00}, Instruction_SUB::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0x96,0x00},{0x01,0x01,0x00}, Instruction_SUB::create, {
REF(A), REF((IY+::))});

register_opcode({0x96},{0x01}, Instruction_SUB::create, {
REF(A), REF((HL))});

register_opcode({0x97},{0x01}, Instruction_SUB::create, {
REF(A), REF(A)});

register_opcode({0x90},{0x01}, Instruction_SUB::create, {
REF(A), REF(B)});

register_opcode({0x91},{0x01}, Instruction_SUB::create, {
REF(A), REF(C)});

register_opcode({0x92},{0x01}, Instruction_SUB::create, {
REF(A), REF(D)});

register_opcode({0x93},{0x01}, Instruction_SUB::create, {
REF(A), REF(E)});

register_opcode({0x94},{0x01}, Instruction_SUB::create, {
REF(A), REF(H)});

register_opcode({0x95},{0x01}, Instruction_SUB::create, {
REF(A), REF(L)});

register_opcode({0xee,0x00},{0x01,0x00}, Instruction_XOR::create, {
REF(A), REF(PC8_1)});

register_opcode({0xdd,0xae,0x00},{0x01,0x01,0x00}, Instruction_XOR::create, {
REF(A), REF((IX+::))});

register_opcode({0xfd,0xae,0x00},{0x01,0x01,0x00}, Instruction_XOR::create, {
REF(A), REF((IY+::))});

register_opcode({0xae},{0x01}, Instruction_XOR::create, {
REF(A), REF((HL))});

register_opcode({0xaf},{0x01}, Instruction_XOR::create, {
REF(A), REF(A)});

register_opcode({0xa8},{0x01}, Instruction_XOR::create, {
REF(A), REF(B)});

register_opcode({0xa9},{0x01}, Instruction_XOR::create, {
REF(A), REF(C)});

register_opcode({0xaa},{0x01}, Instruction_XOR::create, {
REF(A), REF(D)});

register_opcode({0xab},{0x01}, Instruction_XOR::create, {
REF(A), REF(E)});

register_opcode({0xac},{0x01}, Instruction_XOR::create, {
REF(A), REF(H)});

register_opcode({0xad},{0x01}, Instruction_XOR::create, {
REF(A), REF(L)});

