let loop = (n) => {
for(let z = 2;z <= n;z++){
    console.log("multiplication table of:", z);
    for(let i = 1;i <= 12;i++){
        const result = z * i;
        console.log(z,"*",i,"=",result);
    }
}
}
loop(6);


