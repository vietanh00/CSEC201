from geoip import geolite2
import geoip

ip = '17.0.0.1'
match = geolite2.lookup(ip)
match is not None

print(match.country)
print (match.continent)
print(match.timezone)
print(match.subdivisions)