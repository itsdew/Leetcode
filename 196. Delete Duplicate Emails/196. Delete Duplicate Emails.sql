//Author: Devendra Uraon
delete org from Person as org, Person as dup where org.email=dup.email and org.id>dup.id;