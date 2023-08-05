from selenium import webdriver
from selenium.webdriver.common.keys import Keys

def new_session(driver, id, page_url):
    driver = webdriver.Remote(command_executor=url,desired_capabilities={})
    driver.close()   # this prevents the dummy browser
    driver.session_id = session_id
    driver.get("https://reader.vhlcentral.com/sentieri3e/student-edition/sen3e_vtext?rid=1004538#/book/sen3e_vtext/chapter/unit_1__ciao_come_va")

def main():
    START = 2
    END = 640
    #1. Go to webpage
    #2. Navigate to page 2
    #3. Loop: a) Send print + Enter  b) Send page num + Enter  d) Go to next page
    #4. Close webpage
    driver = webdriver.Firefox()
        # Attach details to use existing webpage
    url = driver.command_executor._url   # 127.0.0.1 and something else
    session_id = driver.session_id       # some random stuff

    new_session(driver, session_id, url)
            # Single page mode
    elem = document.querySelector('span[ng-click="singlePage()"]')
    elem.click()
        # Go to page 2
    elem.send_keys(Keys.ARROW_RIGHT)
        # Loop begin
    for START in range (2, 640):
               # Connect to the same driver again
        new_session(driver)
        elem.send_keys(Keys.CONTROL, "P")
        elem.send_keys(Keys.RETURN)
        elem.send_keys(str(START))
        elem.send_keys(Keys.RETURN)

    driver.close()

