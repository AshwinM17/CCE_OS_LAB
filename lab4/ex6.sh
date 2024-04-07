myFunction() {
param1=("${!1}")
param2=("${!2}")
for i in ${param1[@]}; do
for j in ${param2[@]}; do
if [ "${i}" == "${j}" ]; then
echo ${i}
echo ${j}
fi
done
done
}
a=(foo bar baz)
b=(foo bar qux)
myFunction a[@] b[@] # would display foo foo bar bar.
