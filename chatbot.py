def choose_college():
    print("Welcome to the College Selection Chatbot!")
    print("Please provide your marks obtained in the CET and HSC exams.")
    
    cet_marks = int(input("Enter your CET marks: "))
    hsc_marks = int(input("Enter your HSC marks: "))
    
    colleges = {
        "College A": {
            "Computer Science": {"cet_cutoff": 85, "hsc_cutoff": 80},
            "Electronics": {"cet_cutoff": 80, "hsc_cutoff": 75}
        },
        "College B": {
            "Mechanical": {"cet_cutoff": 90, "hsc_cutoff": 85},
            "Civil": {"cet_cutoff": 85, "hsc_cutoff": 80}
        },
        "College C": {
            "Chemical": {"cet_cutoff": 80, "hsc_cutoff": 75},
            "Electrical": {"cet_cutoff": 85, "hsc_cutoff": 80}
        }
    }
    
    eligible_colleges = []
    
    for college, branches in colleges.items():
        for branch, cutoffs in branches.items():
            if cet_marks >= cutoffs["cet_cutoff"] and hsc_marks >= cutoffs["hsc_cutoff"]:
                eligible_colleges.append(college + " - " + branch)
    
    if eligible_colleges:
        print("You are eligible for the following colleges and branches:")
        for college in eligible_colleges:
            print("- " + college)
    else:
        print("Sorry, you are not eligible for any college.")
    
    print("Thank you for using the College Selection Chatbot!")

choose_college()
