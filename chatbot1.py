def choosecollege():
    print("welcome")
    cetmarks=int(input("enter your cetmarks: "))
    hscmarks=int(input("enter yout hscmarks: "))

    colleges={
        "col a":{"comp":{"cetcutoff":90,"hsccutoff":88},
                 "it":{"cetcutoff":88,"hsccutoff":87}
                 },
        "col b":{"comp":{"cetcutoff":88,"hsccutoff":80},
                 "it":{"cetcutoff":78,"hsccutoff":66}
                 }
        }
    
    eligible_clg=[]

    for college,branches in colleges.items():
        for branch,cutoff in branches.items():
            if cetmarks>=cutoff["cetcutoff"] and hscmarks>=cutoff["hsccutoff"]:
                eligible_clg.append(college + "-" + branch)

    if eligible_clg:
        print("eligible clgs")
        for clgbranch in eligible_clg:
            print(clgbranch)
        
        else:
            print("not found")
        
choosecollege()
