from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time 

driver = webdriver.Firefox()
        # Attach details to use existing webpage
url = driver.command_executor._url   # 127.0.0.1 and something else
session_id = driver.session_id       # some random stuff
driver.get("https://reader.vhlcentral.com/sentieri3e/student-edition/sen3e_vtext?rid=1004538#/book/sen3e_vtext/")
# Log in
elem = driver.find_element_by_id("user_session_username")     
elem.send_keys("an5208@rit.edu")
try:
    elem = driver.find_element_by_id("user_session_password")
    elem.send_keys("Nvanvanva1")
    elem.send_keys(Keys.RETURN)
except Exception:
    print("stale")

time.sleep(7)

for i in range (0, 15):
    elem.send_keys(Keys.ARROW_RIGHT) # Get to page 2
    time.sleep(3)


elem = driver.find_element_by_xpath("//*[@aria-label='Single Page View']")
elem.click()
        # Go to page 2
elem.send_keys(Keys.ARROW_RIGHT)
        # Loop begin    
elem.send_keys(Keys.CONTROL, "P")
elem.send_keys(Keys.RETURN)
elem.send_keys(str(2))
elem.send_keys(Keys.RETURN)    


