class Student {
students = [];   // stack used to store the student objects
constructor(id, name, address, email) {   // used to create student objects
this.id = id;
this.name = name;
this.address = address;
this.email = email;
}
addStudent() {  // used to enter the infos of students
   const stid= prompt("Enter your id");
   const stname= prompt("Enter your name");
   const stadd= prompt("Enter your address");
   const stemail= prompt("Enter your email");
    this.students.push(new Student(stid,stname,stadd,stemail));
}
printInfo() {
    document.writeln("<h2> List of students</h2>");
    var tbl = document.createElement("table");
    // document.createElement("th");
    tbl.setAttribute("border", "2px");
    tbl.innerHTML+="<tr><th>ID</th><th>Name</th><th>Address</th><th>Email</th></tr>";

    for(const studs of this.students){

        tbl.innerHTML+=`<tr><td> ${studs.id}</td><td> ${studs.name}</td><td>${studs.address}</td><td>${studs.email}</td></tr>`
    }
    document.body.appendChild(tbl);
}
}
s1=new Student()
s1.addStudent();
s1.addStudent();
s1.printInfo();