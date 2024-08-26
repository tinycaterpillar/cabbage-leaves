# 승민이가 만들어준 매크로

import json
import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.alert import  Alert
from bs4 import BeautifulSoup
from selenium.webdriver.common.keys import Keys

student_id="123"
student_pw="123@"

options=Options()
options.add_experimental_option("detach",True)
service=Service(ChromeDriverManager().install())
driver=webdriver.Chrome(service=service,options=options)
driver.get('https://sugang.inha.ac.kr')
all_tabs=driver.window_handles
time.sleep(2)

driver.switch_to.frame(driver.find_element("xpath",'/html/body/iframe'))
driver.switch_to.frame('MenuFrame')

time.sleep(0.5)

#login
driver.find_element('xpath','//*[@id="txtCode"]').send_keys(student_id)
driver.find_element('xpath','//*[@id="txtPassword"]').send_keys(student_pw)
driver.find_element('xpath','//*[@id="ibtnLogin"]').click()
time.sleep(0.5)

driver.find_element('xpath','//*[@id="dvMenu"]/ul/li[3]/a').click()
driver.find_element('xpath','//*[@id="dvMenu"]/ul/li[3]/ul/li[2]/a').click()

time.sleep(0.5)
da=Alert(driver)
da.accept()

driver.switch_to.default_content()
driver.switch_to.frame(driver.find_element("xpath", '/html/body/iframe'))
driver.switch_to.frame('MainFrame')

while 1:
    driver.find_element('xpath','//*[@id="dgList2"]/tbody/tr/td[9]/input').click()
    time.sleep(0.5)
    da.accept()
    time.sleep(0.5)
    da.accept()



#driver.find_element('xpath','//*[@id="dgList2"]/tbody/tr[2]/td[9]/input').click()