//
//  ViewController.swift
//  boltic-ios-demo
//
//  Created by Sagar Kumar on 10/10/24.
//

import UIKit
import FyndAnalytics

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        FyndAnalytics.shared().track("Let's Tack", properties: ["type": "track", "effectDuration": 24.0])
    }
}

