from selenium import webdriver
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
from selenium.webdriver.common.by import By
from bs4 import BeautifulSoup

dc = DesiredCapabilities.CHROME
driver = webdriver.Chrome(desired_capabilities=dc)
#launch browser
url = "https://id.inchainge.com/Account/Login?ReturnUrl=%2Fconnect%2Fauthorize%2Fcallback%3Fclient_id%3Dmy-inchainge%26redirect_uri%3Dhttps%253A%252F%252Fmy.inchainge.com%252Flogin-callback%26response_type%3Dcode%26scope%3Dopenid%2520profile%2520email%2520identity-api.profile%2520codes-api%2520tfc-api%2520tcc-api%2520ttc-api%2520education-api%2520my-inchainge-api%2520bundles-api%2520tbc-api%2520codes-api.email%26state%3Dee25d0f219164f2695898ce854dbcb78%26code_challenge%3DZaNixFqAcgXjOIU9_lcJ1LUtjKbLsOruI53syQsvKdM%26code_challenge_method%3DS256%26response_mode%3Dquery"
driver.get (url)

my = 'william1016.cs10@nycu.edu.tw'
passwd = '_419Qg376'

Email = driver.find_element("id" , "Email")
Email.send_keys(my)
Password = driver.find_element("id", "Password")
Password.send_keys(passwd)

submit = driver.find_element(By.CLASS_NAME, "btn-block-xs-only")
# submit = driver.find_element(By.CSS_SELECTOR(".btn.btn-inchainge.btn-block-xs-only"))
submit.click()

# After redirection
# driver.get("https://my.inchainge.com/")
driver.get("http://game.theblueconnection.eu/v2/entry/51291")
driver.get("https://game.theblueconnection.eu/v2/MyCompany/Depreciation")



# dep = driver.find_element(By.CLASS_NAME, "highcharts-container ")
# print(dep.get_attribute('script'))
html = driver.page_source
# print(html)
# print(driver.get_attribute('innerHTML'))

# dc['loggingPrefs'] = { 'browser':'INFO' }
# for entry in driver.get_log('browser'):
#     print(entry)

dep = driver.find_element(By.CLASS_NAME, "depreciationgraph")
print(dep)