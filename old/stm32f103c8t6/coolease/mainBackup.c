	
	void exti2_isr(void)
    {
        
    }
    
    //uint8_t num_temperature_readings = 10;
	//float temperature_readings[num_temperature_readings];

	/*exti_reset_request(EXTI2);
    exti_select_source(EXTI2, GPIOA);
	exti_set_trigger(EXTI2, EXTI_TRIGGER_RISING);
	exti_enable_request(EXTI2);
    nvic_enable_irq(NVIC_EXTI2_IRQ);
    nvic_set_priority(NVIC_EXTI2_IRQ, 0);*/
        
        
        
        //si7051_setup_and_readf_temperature2(temperature_readings, num_temperature_readings);
		//for(int i = 0; i < num_temperature_readings; i++)
		//	serial_print("%4.2f ", temperature_readings[i]);
		//serial_print("\n");
		//serial_print("Entering Standby\n");
		//timers_delay(1);
		//timers_prepare_and_enter_standby(10);
		
		/*uint8_t plain_text[10] = {0,1,2,3,4,5,6,7,8,9};
		uint8_t cipher_text[10];
		uint8_t message[10+24+16];
	
		serial_print("\nPlain Text: "); for(int i=0;i<10;i++)serial_print("%i ", plain_text[i]);
		encrypt_message(plain_text, cipher_text, message); 
		serial_print("\nCypher Text: "); for(int i=0;i<10;i++)serial_print("%i ", cipher_text[i]);
		serial_print("\nMessage: "); for(int i=0;i<50;i++)serial_print("%i ", message[i]);

		if(decrypt_message(plain_text, cipher_text, message))
			serial_print("\nMessage Authentication Failed");
		else
		{
			serial_print("\nDecrypted Text: "); 
			for(int i=0;i<10;i++)serial_print("%i ", plain_text[i]);
			while(1)
				__asm__("nop");
		}

		//timers_pet_dogs();

		if(timer_get_flag(TIM2, TIM_SR_UIF))
		{
			timer_clear_flag(TIM2, TIM_SR_UIF);

			if(cc1101_get_packet(&packet_receive))
				serial_print("Message Received: %c\n", packet_receive.data[0]);

			//cc1101_transmit_packet(packet_send);

			gpio_toggle(GPIOA, GPIO15);

			serial_print("End\n\n");
		}*/