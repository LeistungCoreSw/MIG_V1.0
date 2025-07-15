/* USER CODE BEGIN Header */
/**`
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "ltdc.h"
#include "lwip.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../lvgl/lvgl.h"
#include "../../lv_conf.h"
#include "../../hal_stm_lvgl/tft/tft.h"
#include "../../hal_stm_lvgl/touchpad/touchpad.h"
#include "../lwip/apps/httpd.h"



float value1=1.4;
float value2=118.0;
float value3 = 3.0;
float value4 = 1.1;
float value5= 22.9;
float value6 = 0.4;

float value11=2.4;
float value22=123.0;
float value33 = 2.0;
float value44 = 2.1;
float value55= 25.9;
float value66 = 0.5;


//#include "../../lv_examples.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
  // This assumes you have an image called 'my_image'
//int count;
// Declare the TFT display object and other global variables


//FOR ADC AND INPUT CAPTURE


#define FLASH_SECTOR7_ADDRESS 0x080C0000 // Must be word-aligned (multiple of 4)
#define FLASH_MAX_ADDRESS     0x080FFFFF
#define FLASH_SECTOR           FLASH_SECTOR_7




extern bool BYPASS;


typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float prev_error;
    float integral;
} PID_Controller;

PID_Controller pid = { .Kp = 1.5f, .Ki = 0.5f, .Kd = 0.1f };
float target_speed = 100.0f;

uint32_t brake_start_time = 0;
uint32_t brake_end_time = 0;
uint8_t brake_started = 0;
uint8_t brake_finished = 0;

float prev_duty_percent = 20.0f;

char rx_buffer[10];          // UART RX buffer
uint8_t rx_index = 0;

uint8_t rx_data;     // For receiving 1 byte

//float duty_cycle = 0.0f;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern SDRAM_HandleTypeDef hsdram1;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//extern struct netif gnetif;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */


void Flash_Write_Data(void);
void Flash_Read_Data(void);
void Flash_Erase_Sector7(void);



//void lv_example_main_page(void);  //FOR MAIN PAGEE

void lv_example_dropdown_2(void);  //FOR SETTING PAGE

void lv_example_img_1(void); //FOR IMAGES

void lv_example_btn_1(void);  //FOR BUTTONS

void lv_example_main_page(float value1,float value2,float value3,float value4,float value5,float value6);
void handle_two_t_screen(void);

float Get_Encoder_Speed(void); // Simulated for now
float PID_Compute(PID_Controller *pid, float setpoint, float measured, float dt);
void Set_PWM_Output(float duty);
//void handle_2T_mode(float value11 , float value22, float value33 , float value44 , float value55, float value66);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//float target_voltage = 22.0f; // Set between 0 to 24
//
//void Set_PWM_Voltage(float voltage)
//{
//    if (voltage > 24.0f) voltage = 24.0f;
//    if (voltage < 0.0f) voltage = 0.0f;
//
//    float duty = (voltage / 24.0f) * 100.0f;
//    uint32_t pulse = (htim2.Init.Period + 1) * duty / 100.0f;
//    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
//}


float duty_percent = 50.0f;  ///duty cycle in percentage

void Set_PWM_Duty(float duty)
{
    if (duty > 100.0f) duty = 100.0f;
    if (duty < 0.0f) duty = 0.0f;

    uint32_t pulse = (htim2.Init.Period + 1) * duty / 100.0f;
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_LTDC_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  MX_FMC_Init();
  MX_LWIP_Init();
  MX_TIM3_Init();

  /* USER CODE BEGIN 2 */
	/* Enable I-Cache */
	//  ethernetif_notify_conn_changed(&gnetif);



	SDRAM_Initialization_Sequence(&hsdram1);

	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
	MX_GPIO_Init();


//	Flash_Read_Data();

	lv_init();

	tft_init();

	touchpad_init();


//	lv_example_main_page();  //FOR MAIN PAGEE

	lv_example_dropdown_2();  //FOR SETTING PAGE

	lv_example_img_1(); //FOR IMAGES

	lv_example_main_page(value1,value2,value3,value4,value5,value6);

	  char buffer[100];

	  char buffer1[100];
	  char buffer2[100];


	  char buffer_tx[100];


    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_Base_Start(&htim3);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		   uint8_t receivedChar[2];

			MX_LWIP_Process(); // To initiate the LWIP process
			Set_PWM_Duty(duty_percent);
			HAL_Delay(10);

//			Flash_Write_Data();
//	        if (HAL_GetTick() - last_time >= 10)
//	        {
//	            last_time = HAL_GetTick();
//
//	            float actual_speed = Get_Encoder_Speed();
//	            float pid_output = PID_Compute(&pid, target_speed, actual_speed, dt);
//	            Set_PWM_Output(pid_output);
//	        }

//				HAL_UART_Receive(&huart1, &receivedChar, 1, HAL_MAX_DELAY);
//				duty_percent = receivedChar[0] - '0';
//
//		            sprintf(buffer_tx, "uart cycle : %d \r\n", duty_percent);
//		            HAL_UART_Transmit(&huart1, (uint8_t *)buffer_tx, strlen(buffer_tx), HAL_MAX_DELAY);
//
////
//					  if (duty_percent < 10.0f && brake_started == 0 && brake_finished == 0)
//					        {
//					            brake_start_time = __HAL_TIM_GET_COUNTER(&htim3);
//					            brake_started = 1;
//					            sprintf(buffer, "Brake start time: %lu ms\r\n", brake_start_time);
//					                HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
//
//					        }
//
//					        // Step 2: duty reaches 0% → brake complete
//					        if (brake_started && duty_percent == 0.0f && brake_finished == 0)
//					        {
//					            brake_end_time = __HAL_TIM_GET_COUNTER(&htim3);
//					            uint32_t brake_time = brake_end_time - brake_start_time;
//
//					            sprintf(buffer1, "Brake endtime: %lu ms\r\n", brake_end_time);
//					                HAL_UART_Transmit(&huart1, (uint8_t *)buffer1, strlen(buffer1), HAL_MAX_DELAY);
//
//					                sprintf(buffer2, "Brake time: %lu ms\r\n", brake_time);
//					         			                HAL_UART_Transmit(&huart1, (uint8_t *)buffer2, strlen(buffer2), HAL_MAX_DELAY);
//
//					            brake_finished = 1;
//					            brake_started = 0;
//					        }
//
//					        // Optional: reset state when motor is restarted
//					        if (duty_percent > 10.0f)
//					        {
//					            brake_started = 0;
//					            brake_finished = 0;
//					        }

//					        HAL_Delay(10);  // loop delay
			lv_tick_inc(5);
			lv_task_handler();

			HAL_Delay(5);  // Small delay to prevent CPU overuse
		}


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
