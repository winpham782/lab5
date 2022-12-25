/*
 * command_parser.c
 *
 *  Created on: Dec 7, 2022
 *      Author: phamv
 */
#include "cmd_parser.h"

void command_parser_fsm(){
	switch(cmd_status){
	case WAIT_FOR_BEGIN_CMD:
		if(temp == '!') {
			cmd_status = WAIT_FOR_END_CMD;
		}
		break;
	case WAIT_FOR_END_CMD:
		if(temp == '#') {
			if(strlen(command_buffer) == 3 && strncmp(command_buffer,"RST",3) == 0) sending_flag = 1;
			else if(strlen(command_buffer) == 2 && strncmp(command_buffer,"OK",2) == 0) ok_flag = 1;
			strcpy(command_buffer,"");
			cmd_status = WAIT_FOR_BEGIN_CMD;
		} else {
			strncat(command_buffer, &temp, 1);
		}
		break;
	default:
		break;
	}
}

